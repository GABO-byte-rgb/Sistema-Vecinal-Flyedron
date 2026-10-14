param(
    [int]$port = 5500,
    [string]$page = "2._verificaci_n_de_identidad_y_privacidad/code.html"
)

$root = $PSScriptRoot
if (-not $root) { $root = Get-Location }

$listener = New-Object System.Net.HttpListener
$listener.Prefixes.Add("http://localhost:$port/")

try {
    $listener.Start()
} catch {
    $port = 8080
    $listener = New-Object System.Net.HttpListener
    $listener.Prefixes.Add("http://localhost:$port/")
    try {
        $listener.Start()
    } catch {
        # Puerto ya en uso por instancia previa, reutilizar
    }
}

$url = "http://localhost:$port/"
$targetUrl = if ($page) { "$url$page" } else { $url }
Write-Host "=================================================" -ForegroundColor Cyan
Write-Host " FLYEDRON - SERVIDOR LOCAL ACTIVO               " -ForegroundColor Green
Write-Host " URL: $targetUrl                                " -ForegroundColor Yellow
Write-Host " Soporta: Webcam getUserMedia, Base64 & ESP32   " -ForegroundColor White
Write-Host " Presiona Ctrl + C para detener el servidor     " -ForegroundColor Gray
Write-Host "=================================================" -ForegroundColor Cyan

# Abrir automáticamente la pantalla solicitada en el navegador
Start-Process $targetUrl

$mimeTypes = @{
    ".html" = "text/html; charset=utf-8"
    ".css"  = "text/css; charset=utf-8"
    ".js"   = "application/javascript; charset=utf-8"
    ".png"  = "image/png"
    ".jpg"  = "image/jpeg"
    ".jpeg" = "image/jpeg"
    ".svg"  = "image/svg+xml"
    ".json" = "application/json"
    ".ico"  = "image/x-icon"
}

while ($listener.IsListening) {
    try {
        $context = $listener.GetContext()
        $request = $context.Request
        $response = $context.Response

        $rawPath = [System.Uri]::UnescapeDataString($request.Url.LocalPath.TrimStart('/'))
        if ([string]::IsNullOrWhiteSpace($rawPath)) {
            $rawPath = "index.html"
        }

        $localPath = [System.IO.Path]::Combine($root, $rawPath)

        if (Test-Path $localPath -PathType Leaf) {
            $ext = [System.IO.Path]::GetExtension($localPath).ToLower()
            $mime = if ($mimeTypes.ContainsKey($ext)) { $mimeTypes[$ext] } else { "application/octet-stream" }
            $bytes = [System.IO.File]::ReadAllBytes($localPath)
            
            $response.ContentType = $mime
            $response.ContentLength64 = $bytes.Length
            $response.Headers.Add("Access-Control-Allow-Origin", "*")
            $response.OutputStream.Write($bytes, 0, $bytes.Length)
        } else {
            $response.StatusCode = 404
            $msg = [System.Text.Encoding]::UTF8.GetBytes("404 No Encontrado: $rawPath")
            $response.OutputStream.Write($msg, 0, $msg.Length)
        }
        $response.Close()
    } catch {
        # Ignorar desconexiones abruptas del cliente
    }
}
