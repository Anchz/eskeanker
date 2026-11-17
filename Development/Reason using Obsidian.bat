@echo off

setlocal

set "VAULT_DIRECTORY=%~dp0Rationale"

powershell -NoProfile -Command "$p = [System.Uri]::EscapeDataString((Resolve-Path '%VAULT_DIRECTORY%').Path); Start-Process \"obsidian://open?path=$p\""

exit

endlocal