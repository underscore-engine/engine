cls
Write-Host ">>> Compiling program..." -ForegroundColor magenta
if ($args[0] -eq "--force") {
  Remove-Item .\bin\* -Recurse
} elseif (!(Test-Path -path .\bin\)) {
  New-Item -ItemType directory -Path .\bin\
}
cd .\bin\
cmake ..
cmake --build .
Write-Output ""
Write-Host ">>> Running program..." -ForegroundColor magenta
.\Debug\program.exe
cd ..