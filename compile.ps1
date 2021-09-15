cls
Write-Host ">>> Compiling program..." -ForegroundColor magenta
cd bin
cmake ..
cmake --build .
Write-Output ""
Write-Host ">>> Running program..." -ForegroundColor magenta
.\Debug\program.exe
cd ..
