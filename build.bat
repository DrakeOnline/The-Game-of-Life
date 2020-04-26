@echo off
echo.
cls

:: Variables
set originalDirectory=%~dp0
set directory=C:\Program Files (x86)\CodeBlocks
set program= codeblocks.exe
set rebuild= --rebuild C:\Users\Drake\Desktop\C++\%1\%1.cbp
set target= --target="Debug"

:: Change the directory
cd %directory%

:: Build executable
echo|set /p=Building %1...
%program% --no-splash-screen --no-batch-window-close --debug-log %rebuild% %target%
echo DONE

:: Change directory back to project
cd %originalDirectory%

:: Run Executable
echo|set /p=Running %1.exe...
bin\Debug\%1.exe
echo DONE

:: Return to Desktop
cd %originalDirectory%
