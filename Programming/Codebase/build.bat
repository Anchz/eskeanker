@echo off

llvm-dlltool -m i386:x86-64 -d win32_kernel32.def -l win32_kernel32.a

clang -c --target=x86_64-w64-mingw32 -std=c23 -ffreestanding -nostdlibinc -g win32_host.c -o win32_host.o

ld.lld -m i386pep -e run --subsystem windows -o eskeanker.exe win32_host.o win32_kernel32.a
