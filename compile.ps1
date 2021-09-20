cls
Write-Host ">>> Compiling program..." -ForegroundColor magenta
if ($args[0] -eq "--force") {
  Remove-Item .\bin\* -Recurse
} elseif (!(Test-Path -path .\bin\)) {
  New-Item -ItemType directory -Path .\bin\
}
cd .\bin\
cmake ..
if (!$?) {
  Write-Host ">>> Error: Could not compile to binaries" -ForegroundColor red
  cd ..
  exit 1
}
cmake --build .
if (!$?) {
  Write-Host ">>> Error: Could not build executable" -ForegroundColor red
  cd ..
  exit 1
}
Write-Output ""
Write-Host ">>> Running program..." -ForegroundColor magenta
.\Debug\program.exe
if (!$?) {
  Write-Host ">>> Error: Could run executable" -ForegroundColor red
  cd ..
  exit 1
}
cd ..