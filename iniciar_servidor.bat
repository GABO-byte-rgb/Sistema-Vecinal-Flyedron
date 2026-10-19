@echo off
title FLYEDRON - Servidor Local
echo ===================================================
echo  Iniciando servidor local FLYEDRON...
echo  Abriendo http://localhost:5500 en tu navegador...
echo ===================================================
powershell -NoProfile -ExecutionPolicy Bypass -File "%~dp0serve.ps1"
pause
