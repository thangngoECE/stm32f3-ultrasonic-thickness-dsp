@echo off
:: Post-build (CubeIDE runs this in Debug\): export the .elf as .hex to prebuilt\
if not exist "..\prebuilt" mkdir "..\prebuilt"
arm-none-eabi-objcopy -O ihex "%~1" "..\prebuilt\%~2.hex"
exit /b %errorlevel%
