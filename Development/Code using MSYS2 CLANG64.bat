@echo off

setlocal

set "MSYSTEM=CLANG64"
set "CHERE_INVOKING=1"

cd /d "%~dp0Codebase"

start "" "C:\msys64\usr\bin\mintty.exe" -i /clang64.ico /usr/bin/bash --login

endlocal