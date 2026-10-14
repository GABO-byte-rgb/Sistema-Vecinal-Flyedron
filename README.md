<div align="center">

<img src="./docs/banner.svg" alt="FLYEDRON — Sistema Táctico Vecinal" width="100%">

**Vigilancia civil autónoma con drones, reportes en tiempo real y comunidad conectada.**

<br>

![Estado](https://img.shields.io/badge/estado-prototipo_UI%2FUX-7357F5?style=for-the-badge)
![HTML5](https://img.shields.io/badge/HTML5-E34F26?style=for-the-badge&logo=html5&logoColor=white)
![TailwindCSS](https://img.shields.io/badge/Tailwind_CSS-06B6D4?style=for-the-badge&logo=tailwindcss&logoColor=white)
![JavaScript](https://img.shields.io/badge/JavaScript-F7DF1E?style=for-the-badge&logo=javascript&logoColor=black)
![Firebase](https://img.shields.io/badge/Firebase_Hosting-FFCA28?style=for-the-badge&logo=firebase&logoColor=black)
![ESP32](https://img.shields.io/badge/ESP32--CAM-E7352C?style=for-the-badge&logo=espressif&logoColor=white)

![Mobile First](https://img.shields.io/badge/mobile--first-360px→428px-20C7E8?style=flat-square)
![Idioma](https://img.shields.io/badge/idioma-español-10B981?style=flat-square)
![Tema](https://img.shields.io/badge/tema-dark_tactical-07152F?style=flat-square)

<br>

<img src="./1._bienvenida_e_inicio_de_sesi_n/screen.png" width="22%" alt="Bienvenida">
<img src="./3._inicio_panel_principal/screen.png" width="22%" alt="Panel principal">
<img src="./4._mapa_de_seguridad_castilla/screen.png" width="22%" alt="Mapa de seguridad">
<img src="./2._verificaci_n_de_identidad_y_privacidad/screen.png" width="22%" alt="Verificación de identidad">

</div>

---

<a id="toc"></a>

## <img src="./docs/icons/list.svg" width="28" height="28" align="absmiddle" alt="list"> Tabla de contenido

- <img src="./docs/icons/drone.svg" width="20" height="20" align="absmiddle" alt="drone"> [¿Qué es FLYEDRON?](#que-es)
- <img src="./docs/icons/layout.svg" width="20" height="20" align="absmiddle" alt="layout"> [Características](#caracteristicas)
- <img src="./docs/icons/smartphone.svg" width="20" height="20" align="absmiddle" alt="smartphone"> [Pantallas](#pantallas)
- <img src="./docs/icons/palette.svg" width="20" height="20" align="absmiddle" alt="palette"> [Sistema de diseño: AeroGuard Castilla](#diseno)
- <img src="./docs/icons/layers.svg" width="20" height="20" align="absmiddle" alt="layers"> [Arquitectura](#arquitectura)
- <img src="./docs/icons/folder.svg" width="20" height="20" align="absmiddle" alt="folder"> [Estructura del proyecto](#estructura)
- <img src="./docs/icons/rocket.svg" width="20" height="20" align="absmiddle" alt="rocket"> [Inicio rápido](#inicio)
- <img src="./docs/icons/radio.svg" width="20" height="20" align="absmiddle" alt="radio"> [Conectar el dron (ESP32-CAM)](#esp32)
- <img src="./docs/icons/cloud.svg" width="20" height="20" align="absmiddle" alt="cloud"> [Despliegue en Firebase](#firebase)
- <img src="./docs/icons/shield-check.svg" width="20" height="20" align="absmiddle" alt="shield-check"> [Privacidad](#privacidad)
- <img src="./docs/icons/route.svg" width="20" height="20" align="absmiddle" alt="route"> [Roadmap](#roadmap)
- <img src="./docs/icons/heart.svg" width="20" height="20" align="absmiddle" alt="heart"> [Créditos](#creditos)

---

<a id="que-es"></a>

## <img src="./docs/icons/drone.svg" width="28" height="28" align="absmiddle" alt="drone"> ¿Qué es FLYEDRON?

**FLYEDRON** es un prototipo de **sistema de seguridad comunitaria** pensado para el barrio **Castilla (Zona 8, Bogotá)**. Conecta a vecinos verificados, comités barriales y una flota de **drones de patrullaje** en una sola app móvil:

> Los vecinos reportan →  un dron inspecciona en minutos →  la comunidad se entera al instante.

El proyecto contiene el **diseño UI/UX completo** (generado con Stitch) en HTML + Tailwind, con interacciones reales como captura de rostro por cámara y visor de transmisión en vivo desde un **ESP32-CAM**.

---

<a id="caracteristicas"></a>

## <img src="./docs/icons/layout.svg" width="28" height="28" align="absmiddle" alt="layout"> Características

| | Función | Descripción |
|---|---|---|
| <img src="./docs/icons/lock.svg" width="26" height="26" align="absmiddle" alt="lock"> | **Inicio de sesión dual** | Acceso como *Vecino Residente* u *Operador / CAA*, con opción biométrica |
| <img src="./docs/icons/scan-face.svg" width="26" height="26" align="absmiddle" alt="scan-face"> | **Verificación de identidad** | Captura facial con la cámara del dispositivo, en voluntario y con estados *Verificado / Pendiente / Rechazado* |
| <img src="./docs/icons/home.svg" width="26" height="26" align="absmiddle" alt="home"> | **Panel principal** | Resumen sectorial: alertas activas, estado del barrio, patrullas y vuelo del dron en curso |
| <img src="./docs/icons/map.svg" width="26" height="26" align="absmiddle" alt="map"> | **Mapa táctico** | Capas de alertas, dron en vuelo, reportes ciudadanos y puntos CAI con ETA del dron |
| <img src="./docs/icons/alert.svg" width="26" height="26" align="absmiddle" alt="alert"> | **Alertas sectoriales** | Filtro por prioridad (críticas / preventivas) y asignación de dron |
| <img src="./docs/icons/edit.svg" width="26" height="26" align="absmiddle" alt="edit"> | **Reportar incidente** | Robo, sospechoso, luminaria, médica, convivencia… con opción de **despachar inspección de dron** |
| <img src="./docs/icons/users.svg" width="26" height="26" align="absmiddle" alt="users"> | **Comunidad** | Contactos de emergencia, asambleas y muro de la Junta de Acción Comunal |
| <img src="./docs/icons/video.svg" width="26" height="26" align="absmiddle" alt="video"> | **Centro de vigilancia** | Transmisión en vivo, telemetría (batería, altitud, velocidad, GPS), foco LED, sirena y captura de foto |
| <img src="./docs/icons/sos.svg" width="26" height="26" align="absmiddle" alt="sos"> | **SOS 123** | Acceso rápido de emergencia sin autenticación previa |

---

<a id="pantallas"></a>

## <img src="./docs/icons/smartphone.svg" width="28" height="28" align="absmiddle" alt="smartphone"> Pantallas

| # | Pantalla | Carpeta |
|:-:|---|---|
| 1 | <img src="./docs/icons/shield.svg" width="22" height="22" align="absmiddle" alt="shield"> Bienvenida e inicio de sesión | [`1._bienvenida_e_inicio_de_sesi_n`](./1._bienvenida_e_inicio_de_sesi_n) |
| 2 | <img src="./docs/icons/scan-face.svg" width="22" height="22" align="absmiddle" alt="scan-face"> Verificación de identidad y privacidad | [`2._verificaci_n_de_identidad_y_privacidad`](./2._verificaci_n_de_identidad_y_privacidad) |
| 3 | <img src="./docs/icons/home.svg" width="22" height="22" align="absmiddle" alt="home"> Inicio / panel principal | [`3._inicio_panel_principal`](./3._inicio_panel_principal) |
| 4 | <img src="./docs/icons/map.svg" width="22" height="22" align="absmiddle" alt="map"> Mapa de seguridad Castilla | [`4._mapa_de_seguridad_castilla`](./4._mapa_de_seguridad_castilla) |
| 5 | <img src="./docs/icons/alert.svg" width="22" height="22" align="absmiddle" alt="alert"> Alertas sectoriales | [`5._alertas_sectoriales`](./5._alertas_sectoriales) |
| 6 | <img src="./docs/icons/edit.svg" width="22" height="22" align="absmiddle" alt="edit"> Reportar incidente | [`6._reportar_incidente`](./6._reportar_incidente) |
| 7 | <img src="./docs/icons/users.svg" width="22" height="22" align="absmiddle" alt="users"> Comunidad Castilla | [`7._comunidad_castilla`](./7._comunidad_castilla) |
| 8 | <img src="./docs/icons/video.svg" width="22" height="22" align="absmiddle" alt="video"> Centro de vigilancia | [`8._centro_de_vigilancia`](./8._centro_de_vigilancia) |

<details>
<summary><b> Ver capturas en grande</b></summary>

<br>

<div align="center">

| Bienvenida | Verificación | Panel | Mapa |
|:-:|:-:|:-:|:-:|
| <img src="./1._bienvenida_e_inicio_de_sesi_n/screen.png" width="200"> | <img src="./2._verificaci_n_de_identidad_y_privacidad/screen.png" width="200"> | <img src="./3._inicio_panel_principal/screen.png" width="200"> | <img src="./4._mapa_de_seguridad_castilla/screen.png" width="200"> |

</div>

</details>

La navegación inferior flotante tiene 6 destinos: **Inicio · Mapa · Alertas · Reportar · Comunidad · Vigilancia**.

---

<a id="diseno"></a>

## <img src="./docs/icons/palette.svg" width="28" height="28" align="absmiddle" alt="palette"> Sistema de diseño: AeroGuard Castilla

Estética **tactical-futurist**: fondos azul marino profundo, telemetría luminosa y alta legibilidad en situaciones de emergencia. La especificación completa está en [`aeroguard_castilla/DESIGN.md`](./aeroguard_castilla/DESIGN.md).

### Paleta

| Rol | Color | Hex |
|---|:-:|---|
| Fondo / canvas | ![](https://img.shields.io/badge/-%20%20%20-07152F) | `#07152F` |
| Superficie / paneles | ![](https://img.shields.io/badge/-%20%20%20-102448) | `#102448` |
| Primario (acciones) | ![](https://img.shields.io/badge/-%20%20%20-7357F5) | `#7357F5` |
| Secundario (telemetría / dron) | ![](https://img.shields.io/badge/-%20%20%20-20C7E8) | `#20C7E8` |
| Crítico / SOS | ![](https://img.shields.io/badge/-%20%20%20-EF4444) | `#EF4444` |
| Advertencia / preventivo | ![](https://img.shields.io/badge/-%20%20%20-F59E0B) | `#F59E0B` |
| Seguro / verificado | ![](https://img.shields.io/badge/-%20%20%20-10B981) | `#10B981` |

### Tipografía

- **Inter** → interfaz, textos y notificaciones
- **Space Grotesk** → telemetría, badges, coordenadas (`ALT 42M`, `BAT 89%`)
- **Material Symbols Outlined** → iconografía

### Componentes clave

- <img src="./docs/icons/sos.svg" width="20" height="20" align="absmiddle" alt="sos">  **Botón SOS** con pulso ambiental y *hold* de 1.5 s para evitar activaciones accidentales
- <img src="./docs/icons/shield-check.svg" width="20" height="20" align="absmiddle" alt="shield-check">  **Badges de estado** tipo píldora con punto parpadeante en alertas críticas
- <img src="./docs/icons/terminal.svg" width="20" height="20" align="absmiddle" alt="terminal">  **Navegación flotante** con *glassmorphism* (`blur 16px`) y glow cian en el ítem activo
- <img src="./docs/icons/video.svg" width="20" height="20" align="absmiddle" alt="video">  **Tarjetas de dron** con visor 16:9 y HUD cian

---

<a id="arquitectura"></a>

## <img src="./docs/icons/layers.svg" width="28" height="28" align="absmiddle" alt="layers"> Arquitectura

```mermaid
flowchart LR
   V[" Vecino<br/>(app móvil)"] -->|reporta incidente| UI[" FLYEDRON UI<br/>HTML + Tailwind"]
   OP[" Operador CAA"] -->|supervisa| UI
   UI -->|despacha| D[" Dron Halcón-01"]
   D -->|video MJPEG| ESP[" ESP32-CAM<br/>:81/stream"]
   ESP -->|stream en vivo| UI
   UI -->|alerta vecinal| C[" Comunidad Castilla"]
   UI -.->|SOS| E[" Línea 123"]
```

**Stack actual**

- <img src="./docs/icons/layout.svg" width="20" height="20" align="absmiddle" alt="layout">  Frontend estático: **HTML5 + Tailwind CSS (CDN) + JavaScript vanilla**
- <img src="./docs/icons/scan-face.svg" width="20" height="20" align="absmiddle" alt="scan-face">  `getUserMedia` para captura facial → imagen en **Base64** (`window.capturedFaceBase64`)
- <img src="./docs/icons/radio.svg" width="20" height="20" align="absmiddle" alt="radio">  Visor de video por flujo MJPEG de **ESP32-CAM**
- <img src="./docs/icons/cloud.svg" width="20" height="20" align="absmiddle" alt="cloud">  Hosting en **Firebase** (proyecto `sistema-vecinal-flyedron`)
- <img src="./docs/icons/terminal.svg" width="20" height="20" align="absmiddle" alt="terminal">  Servidor local en **PowerShell** (`serve.ps1`)

---

<a id="estructura"></a>

## <img src="./docs/icons/folder.svg" width="28" height="28" align="absmiddle" alt="folder"> Estructura del proyecto

```text
flyedron/
├── 1._bienvenida_e_inicio_de_sesi_n/        # code.html + screen.png
├── 2._verificaci_n_de_identidad_y_privacidad/ # code.html + screen.png
├── 3._inicio_panel_principal/               # code.html + screen.png
├── 4._mapa_de_seguridad_castilla/           # code.html + screen.png
├── 5._alertas_sectoriales/                  # code.html
├── 6._reportar_incidente/                   # code.html
├── 7._comunidad_castilla/                   # code.html
├── 8._centro_de_vigilancia/                 # code.html
├── aeroguard_castilla/
│   └── DESIGN.md                            # Sistema de diseño
├── flyedron_community_security_tactical_drone_system/
│   └── code.html                               # Pantalla de bienvenida (versión inicial)
├── public/
├── index.html                               # Redirige a la verificación de identidad
├── iniciar_servidor.bat                     # Lanzador rápido (Windows)
├── serve.ps1                                # Servidor local en PowerShell
├── docs/                                       # Banner e iconos SVG del README
├── firebase.json
└── .firebaserc
```

---

<a id="inicio"></a>

## <img src="./docs/icons/rocket.svg" width="28" height="28" align="absmiddle" alt="rocket"> Inicio rápido

### Paso 1 · Clonar el repositorio

```bash
git clone https://github.com/TU_USUARIO/flyedron.git
cd flyedron
```

### Paso 2 · Levantar el servidor local

> La captura de rostro usa la cámara, que **solo funciona en `localhost` o HTTPS**. Por eso no basta con abrir el HTML con doble clic.

<details open>
<summary><b>Windows (recomendado)</b></summary>

Doble clic en **`iniciar_servidor.bat`**. Se abre automáticamente `http://localhost:5500`.

(Si el puerto 5500 está ocupado, usa el `8080`.)

</details>

<details>
<summary><b>Linux / macOS</b></summary>

```bash
python3 -m http.server 5500
```

Luego abre  http://localhost:5500

</details>

<details>
<summary><b>Node.js</b></summary>

```bash
npx serve -l 5500 .
```

</details>

### Paso 3 · Explorar

Entra a cualquiera de las 8 pantallas, por ejemplo:

```text
http://localhost:5500/1._bienvenida_e_inicio_de_sesi_n/code.html
```

---

<a id="esp32"></a>

## <img src="./docs/icons/radio.svg" width="28" height="28" align="absmiddle" alt="radio"> Conectar el dron (ESP32-CAM)

Las pantallas **Inicio** y **Centro de vigilancia** muestran el video del dron desde un ESP32-CAM. La URL por defecto es:

```text
http://192.168.1.50:81/stream
```

Para usar tu propio módulo:

1. Enciende el ESP32-CAM y conéctalo a la **misma red Wi-Fi** que tu computador.
2. Anota su IP (por ejemplo, desde el monitor serial).
3. En **Centro de vigilancia**, escribe la nueva URL en el campo de configuración de IP y pulsa **Reconectar**.
4. Para dejarla fija, cambia `src="http://192.168.1.50:81/stream"` en `3._inicio_panel_principal/code.html` y `8._centro_de_vigilancia/code.html`.

---

<a id="firebase"></a>

## <img src="./docs/icons/cloud.svg" width="28" height="28" align="absmiddle" alt="cloud"> Despliegue en Firebase

```bash
npm install -g firebase-tools
firebase login
firebase deploy --only hosting
```

El proyecto ya está configurado con el ID `sistema-vecinal-flyedron` (ver [`.firebaserc`](./.firebaserc)). Los archivos `*.bat`, `*.ps1` y ocultos se excluyen del despliegue automáticamente.

---

<a id="privacidad"></a>

## <img src="./docs/icons/shield-check.svg" width="28" height="28" align="absmiddle" alt="shield-check"> Privacidad

FLYEDRON está diseñado alrededor de la confianza vecinal:

- <img src="./docs/icons/shield-check.svg" width="20" height="20" align="absmiddle" alt="shield-check">  Verificación de identidad **voluntaria**
- <img src="./docs/icons/shield.svg" width="20" height="20" align="absmiddle" alt="shield">  Marco de protección de datos de la **Ley 1581 de Colombia**
- <img src="./docs/icons/lock.svg" width="20" height="20" align="absmiddle" alt="lock">  Indicadores de cifrado de extremo a extremo en la interfaz
- <img src="./docs/icons/home.svg" width="20" height="20" align="absmiddle" alt="home">  Las ubicaciones residenciales se muestran en **áreas aproximadas**
- <img src="./docs/icons/users.svg" width="20" height="20" align="absmiddle" alt="users">  Vigilancia civil autorizada por el comité vecinal de seguridad

> <img src="./docs/icons/alert.svg" width="22" height="22" align="absmiddle" alt="alert"> Este repositorio es un **prototipo de interfaz**. Antes de usarlo con datos reales de personas (rostros, ubicaciones, cédulas) hay que implementar un backend con autenticación, cifrado y almacenamiento seguro.

---

<a id="roadmap"></a>

## <img src="./docs/icons/route.svg" width="28" height="28" align="absmiddle" alt="route"> Roadmap

- [x]  Sistema de diseño AeroGuard Castilla
- [x]  8 pantallas móviles diseñadas
- [x]  Captura facial con `getUserMedia`
- [x]  Visor de video ESP32-CAM
- [x]  Configuración de hosting en Firebase
- [ ]  Autenticación real (Firebase Auth)
- [ ]  Base de datos de reportes y alertas en tiempo real
- [ ]  Mapa interactivo con GIS real
- [ ]  Notificaciones push a vecinos
- [ ]  Detección con visión por computador
- [ ]  Telemetría real del dron (batería, GPS, altitud)
- [ ]  Empaquetado como PWA

---

<a id="creditos"></a>

## <img src="./docs/icons/heart.svg" width="28" height="28" align="absmiddle" alt="heart"> Créditos

- Diseño de interfaces generado con **Stitch**
- Desarrollo e integración: **[@TU_USUARIO](https://github.com/TU_USUARIO)**
- Pensado para la comunidad de **Castilla, Bogotá** 

<div align="center">

<br>

**Hecho con <img src="./docs/icons/heart.svg" width="20" height="20" align="absmiddle" alt="heart"> y <img src="./docs/icons/drone.svg" width="20" height="20" align="absmiddle" alt="drone"> en Bogotá, Colombia**

 Si te gustó el proyecto, ¡dale una estrella al repo!

</div>
