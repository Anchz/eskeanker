@echo off

clang -std=c23 win32_host.c application.c win32_platform.c -o application.exe -municode -mwindows
