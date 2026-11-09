@echo off
cd /d "%~dp0Codebase"
set MSYSTEM=CLANG64
set CHERE_INVOKING=1
start "" "C:\msys64\usr\bin\mintty.exe" -i /msys2.ico /usr/bin/bash --login
exit