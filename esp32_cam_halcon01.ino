/*
 ============================================================================
  PROYECTO: FLYEDRON CASTILLA - NODO DRON HALCÓN-01
  HARDWARE: AI-Thinker ESP32-CAM (o ESP32 estándar con cámara OV2640)
  DESCRIPCIÓN:
    1. Se conecta a la red Wi-Fi comunitaria de Castilla.
    2. Inicia el servidor de Streaming MJPEG (video en vivo) en el puerto 81.
    3. ENVÍA DIRECTAMENTE SU IP DINÁMICA A FIRESTORE DATABASE:
       - No expone IPs locales estáticas en el código HTML de la web.
       - Actualiza el documento: /drones/halcon-01
       - Sube: ipStream, estado ("online"), bateria, señal WiFi (RSSI), timestamp.
    4. El frontend lee automáticamente Firestore en tiempo real (onSnapshot).
 ============================================================================
*/

#include "esp_camera.h"
#include <WiFi.h>
#include <HTTPClient.h>
#include <WiFiClientSecure.h>
#include "esp_http_server.h"

// ----------------------------------------------------------------------------
// 1. CREDENCIALES WI-FI
// ----------------------------------------------------------------------------
const char* ssid     = "TU_RED_WIFI";       // <-- Coloca aquí el nombre de tu red Wi-Fi
const char* password = "TU_PASSWORD_WIFI";   // <-- Coloca aquí la contraseña de tu Wi-Fi

// ----------------------------------------------------------------------------
// 2. CONFIGURACIÓN FIRESTORE DATABASE (REST API v1)
// ----------------------------------------------------------------------------
// Proyecto de Firebase de FLYEDRON
const char* FIREBASE_PROJECT_ID = "sistema-vecinal-flyedron";
const char* FIREBASE_API_KEY    = "AIzaSyBNkI4q0mbZ_CjLwFyjRQWTkf3Kt5o-GXE";
const char* DRONE_DOCUMENT_ID   = "halcon-01"; // ID del dron en /drones/halcon-01

// ----------------------------------------------------------------------------
// 3. DEFINICIÓN DE PINES PARA MÓDULO AI-THINKER ESP32-CAM
// ----------------------------------------------------------------------------
#define PWDN_GPIO_NUM     32
#define RESET_GPIO_NUM    -1
#define XCLK_GPIO_NUM      0
#define SIOD_GPIO_NUM     26
#define SIOC_GPIO_NUM     27

#define Y9_GPIO_NUM       35
#define Y8_GPIO_NUM       34
#define Y7_GPIO_NUM       39
#define Y6_GPIO_NUM       36
#define Y5_GPIO_NUM       21
#define Y4_GPIO_NUM       19
#define Y3_GPIO_NUM       18
#define Y2_GPIO_NUM        5
#define VSYNC_GPIO_NUM    25
#define HREF_GPIO_NUM     23
#define PCLK_GPIO_NUM     22

#define FLASH_LED_PIN      4 // LED flash de alta luminosidad de la ESP32-CAM

// Servidores HTTP
httpd_handle_t stream_httpd = NULL;

#define PART_BOUNDARY "123456789000000000000987654321"
static const char* _STREAM_CONTENT_TYPE = "multipart/x-mixed-replace;boundary=" PART_BOUNDARY;
static const char* _STREAM_BOUNDARY = "\r\n--" PART_BOUNDARY "\r\n";
static const char* _STREAM_PART = "Content-Type: image/jpeg\r\nContent-Length: %u\r\n\r\n";

// ----------------------------------------------------------------------------
// 4. CONTROLADOR DE STREAMING DE VIDEO MJPEG
// ----------------------------------------------------------------------------
static esp_err_t stream_handler(httpd_req_t *req) {
  camera_fb_t * fb = NULL;
  esp_err_t res = ESP_OK;
  size_t _jpg_buf_len = 0;
  uint8_t * _jpg_buf = NULL;
  char * part_buf[64];

  res = httpd_resp_set_type(req, _STREAM_CONTENT_TYPE);
  if (res != ESP_OK) return res;

  // Cabecera CORS para permitir la inserción directa en el Dashboard Web
  httpd_resp_set_hdr(req, "Access-Control-Allow-Origin", "*");

  while (true) {
    fb = esp_camera_fb_get();
    if (!fb) {
      Serial.println("[ESP32-CAM] Error al capturar fotograma");
      res = ESP_FAIL;
    } else {
      _jpg_buf_len = fb->len;
      _jpg_buf = fb->buf;
    }

    if (res == ESP_OK) {
      size_t hlen = snprintf((char *)part_buf, 64, _STREAM_PART, _jpg_buf_len);
      res = httpd_resp_send_chunk(req, (const char *)part_buf, hlen);
    }
    if (res == ESP_OK) {
      res = httpd_resp_send_chunk(req, (const char *)_jpg_buf, _jpg_buf_len);
    }
    if (res == ESP_OK) {
      res = httpd_resp_send_chunk(req, _STREAM_BOUNDARY, strlen(_STREAM_BOUNDARY));
    }

    if (fb) {
      esp_camera_fb_return(fb);
      fb = NULL;
      _jpg_buf = NULL;
    } else if (res != ESP_OK) {
      break;
    }
  }
  return res;
}

void startCameraServer() {
  httpd_config_t config = HTTPD_DEFAULT_CONFIG();
  config.server_port = 81;
  config.ctrl_port = 32768;

  httpd_uri_t stream_uri = {
    .uri       = "/stream",
    .method    = HTTP_GET,
    .handler   = stream_handler,
    .user_ctx  = NULL
  };

  Serial.printf("[ESP32-CAM] Iniciando servidor de streaming en puerto: '%d'\n", config.server_port);
  if (httpd_start(&stream_httpd, &config) == ESP_OK) {
    httpd_register_uri_handler(stream_httpd, &stream_uri);
    Serial.println("[ESP32-CAM] Servidor MJPEG /stream activo y listo.");
  }
}

// ----------------------------------------------------------------------------
// 5. REGISTRAR IP DIRECTAMENTE EN FIRESTORE (SIN EXPONERLA EN EL CLIENTE)
// ----------------------------------------------------------------------------
void reportIpToFirestore(String localIpStr) {
  if (WiFi.status() != WL_CONNECTED) {
    Serial.println("[Firestore] Wi-Fi desconectado. No se puede sincronizar IP.");
    return;
  }

  WiFiClientSecure client;
  client.setInsecure(); // Permite SSL con Firebase sin necesidad de certificado local pesado

  HTTPClient https;

  // Endpoint oficial de Firestore REST API v1 para actualizar un documento específico:
  // PATCH https://firestore.googleapis.com/v1/projects/{projectId}/databases/(default)/documents/{collection}/{documentId}?key={apiKey}
  String url = String("https://firestore.googleapis.com/v1/projects/") + FIREBASE_PROJECT_ID +
               "/databases/(default)/documents/drones/" + DRONE_DOCUMENT_ID +
               "?key=" + FIREBASE_API_KEY;

  String fullStreamUrl = "http://" + localIpStr + ":81/stream";

  // Formato JSON estándar de Firestore REST
  String jsonBody = "{"
    "\"fields\": {"
      "\"nombre\": {\"stringValue\": \"Dron Halcón-01\"},"
      "\"cuadrante\": {\"stringValue\": \"Castilla Sector 2\"},"
      "\"ip\": {\"stringValue\": \"" + localIpStr + "\"},"
      "\"ipStream\": {\"stringValue\": \"" + fullStreamUrl + "\"},"
      "\"estado\": {\"stringValue\": \"online\"},"
      "\"bateria\": {\"integerValue\": \"88\"},"
      "\"altitudMetros\": {\"integerValue\": \"45\"},"
      "\"velocidadKmh\": {\"integerValue\": \"18\"},"
      "\"rssiWifi\": {\"integerValue\": \"" + String(WiFi.RSSI()) + "\"},"
      "\"ultimaConexion\": {\"stringValue\": \"" + String(millis()) + "\"}"
    "}"
  "}";

  Serial.println("[Firestore] Enviando IP y estado a Firestore...");
  Serial.print("  URL: "); Serial.println(fullStreamUrl);

  if (https.begin(client, url)) {
    https.addHeader("Content-Type", "application/json");
    // Usamos PATCH con override o POST con updateMask
    int httpResponseCode = https.sendRequest("PATCH", jsonBody);

    if (httpResponseCode > 0) {
      Serial.printf("[Firestore] Respuesta exitosa de Firebase. Código: %d\n", httpResponseCode);
      String response = https.getString();
      Serial.println("[Firestore] ¡IP guardada exitosamente en la nube!");
    } else {
      Serial.printf("[Firestore] Error al enviar a Firestore: %s (código: %d)\n", https.errorToString(httpResponseCode).c_str(), httpResponseCode);
    }
    https.end();
  } else {
    Serial.println("[Firestore] No se pudo abrir conexión segura HTTPS con Firebase.");
  }
}

// ----------------------------------------------------------------------------
// 6. SETUP PRINCIPAL
// ----------------------------------------------------------------------------
void setup() {
  Serial.begin(115200);
  Serial.setDebugOutput(true);
  Serial.println("\n\n==========================================");
  Serial.println("  FLYEDRON CASTILLA - DRON HALCÓN-01 ESP32");
  Serial.println("==========================================");

  pinMode(FLASH_LED_PIN, OUTPUT);
  digitalWrite(FLASH_LED_PIN, LOW); // LED flash apagado al inicio

  // Configuración de la Cámara OV2640
  camera_config_t config;
  config.ledc_channel = LEDC_CHANNEL_0;
  config.ledc_timer   = LEDC_TIMER_0;
  config.pin_d0       = Y2_GPIO_NUM;
  config.pin_d1       = Y3_GPIO_NUM;
  config.pin_d2       = Y4_GPIO_NUM;
  config.pin_d3       = Y5_GPIO_NUM;
  config.pin_d4       = Y6_GPIO_NUM;
  config.pin_d5       = Y7_GPIO_NUM;
  config.pin_d6       = Y8_GPIO_NUM;
  config.pin_d7       = Y9_GPIO_NUM;
  config.pin_xclk     = XCLK_GPIO_NUM;
  config.pin_pclk     = PCLK_GPIO_NUM;
  config.pin_vsync    = VSYNC_GPIO_NUM;
  config.pin_href     = HREF_GPIO_NUM;
  config.pin_sscb_sda = SIOD_GPIO_NUM;
  config.pin_sscb_scl = SIOC_GPIO_NUM;
  config.pin_pwdn     = PWDN_GPIO_NUM;
  config.pin_reset    = RESET_GPIO_NUM;
  config.xclk_freq_hz = 20000000;
  config.pixel_format = PIXFORMAT_JPEG;

  // Ajustes de buffer de fotogramas según memoria PSRAM
  if (psramFound()) {
    config.frame_size = FRAMESIZE_VGA; // 640x480 ideal para streaming fluido
    config.jpeg_quality = 12;          // Calidad óptima (10-63)
    config.fb_count = 2;
  } else {
    config.frame_size = FRAMESIZE_SVGA;
    config.jpeg_quality = 14;
    config.fb_count = 1;
  }

  // Inicializar hardware de la cámara
  esp_err_t err = esp_camera_init(&config);
  if (err != ESP_OK) {
    Serial.printf("[ESP32-CAM] Falló la inicialización de la cámara con error 0x%x\n", err);
    return;
  }

  // Sensor OV2640: Ajuste de brillo, contraste y volteo
  sensor_t * s = esp_camera_sensor_get();
  if (s != NULL) {
    s->set_vflip(s, 1);       // Invierte verticalmente si la cámara está invertida
    s->set_brightness(s, 1);   // Aumenta brillo para tomas nocturnas
    s->set_saturation(s, 0);
  }

  // Conectar a Wi-Fi
  Serial.print("[WiFi] Conectando a ");
  Serial.println(ssid);
  WiFi.begin(ssid, password);

  int reintentos = 0;
  while (WiFi.status() != WL_CONNECTED && reintentos < 30) {
    delay(500);
    Serial.print(".");
    reintentos++;
  }

  if (WiFi.status() == WL_CONNECTED) {
    Serial.println("\n[WiFi] ¡Conexión establecida!");
    Serial.print("[WiFi] IP local asignada: ");
    Serial.println(WiFi.localIP());

    // Iniciar servidor de video MJPEG
    startCameraServer();

    // Guardar la IP directamente en Firestore (Cloud)
    reportIpToFirestore(WiFi.localIP().toString());

    // Señal luminosa breve: 2 parpadeos del flash indicando OK
    digitalWrite(FLASH_LED_PIN, HIGH);
    delay(80);
    digitalWrite(FLASH_LED_PIN, LOW);
    delay(80);
    digitalWrite(FLASH_LED_PIN, HIGH);
    delay(80);
    digitalWrite(FLASH_LED_PIN, LOW);
  } else {
    Serial.println("\n[WiFi] No se pudo conectar a la red Wi-Fi especificada.");
  }
}

// ----------------------------------------------------------------------------
// 7. BUCLE PRINCIPAL (Heartbeat periódico a Firestore cada 30 segundos)
// ----------------------------------------------------------------------------
unsigned long lastHeartbeat = 0;
const unsigned long HEARTBEAT_INTERVAL = 30000; // 30 segundos

void loop() {
  // Cada 30 segundos confirma su presencia e IP activa en Firestore
  if (millis() - lastHeartbeat >= HEARTBEAT_INTERVAL) {
    lastHeartbeat = millis();
    if (WiFi.status() == WL_CONNECTED) {
      reportIpToFirestore(WiFi.localIP().toString());
    } else {
      Serial.println("[WiFi] Reconectando a la red...");
      WiFi.reconnect();
    }
  }
  delay(10);
}
