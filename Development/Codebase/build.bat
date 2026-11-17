@echo off

setlocal

set SHARED_COMPILATION_FLAGS=-std=c23 -ffreestanding

clang -c %SHARED_COMPILATION_FLAGS% runtime.c -o runtime.o
clang -c %SHARED_COMPILATION_FLAGS% win32_host.c -o win32_host.o
clang -c %SHARED_COMPILATION_FLAGS% application.c -o application.o
clang -c %SHARED_COMPILATION_FLAGS% win32_platform.c -o win32_platform.o

clang -nostdlib -mwindows -e run runtime.o win32_host.o application.o win32_platform.o -o eskeanker.exe -lkernel32 -luser32
