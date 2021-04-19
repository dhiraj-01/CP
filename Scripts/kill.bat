@ECHO OFF
if "%*" NEQ "" (taskkill /IM "%*" /F) else (
    echo usage: kill "process_name"
    echo ex. kill chrome.exe, kill a.exe
)