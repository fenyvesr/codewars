@echo off
setlocal

set "BUILD_TYPE=Release"

if /I "%~1"=="Debug" set "BUILD_TYPE=Debug"
if /I "%~1"=="Release" set "BUILD_TYPE=Release"
if /I "%~2"=="clean" set "DO_CLEAN=1"
if /I "%~1"=="clean" set "DO_CLEAN=1"

if /I "%~1"=="help" goto :help
if /I "%~1"=="-h" goto :help
if /I "%~1"=="--help" goto :help

set "CMAKE_PATH=%~dp0Tools\cmake-3.22.1-windows-x86_64\bin"
set "DOXYGEN_PATH=%~dp0Tools\doxygen-1.17.0.windows.x64.bin"
set "BUILD_DIR=%~dp0build"
set "DOC_DIR=%~dp0doc"

if defined DO_CLEAN (
    echo Cleaning build and doc folders...
    rd /s /q "%BUILD_DIR%" 2>nul
    rd /s /q "%DOC_DIR%" 2>nul
)

echo Configuring %BUILD_TYPE%...
"%CMAKE_PATH%\cmake.exe" -G "MinGW Makefiles" -B "%BUILD_DIR%" -DCMAKE_BUILD_TYPE=%BUILD_TYPE% || goto :error

echo Building %BUILD_TYPE%...
"%CMAKE_PATH%\cmake.exe" --build "%BUILD_DIR%" || goto :error

echo Running tests...
"%CMAKE_PATH%\ctest.exe" --test-dir "%BUILD_DIR%" --output-on-failure || goto :error

if /I "%BUILD_TYPE%"=="Release" (
    echo Generating documentation...
    "%DOXYGEN_PATH%\doxygen.exe" "%~dp0Doxygen_config" || goto :error
)

echo.
echo Done.
exit /b 0

:error
echo.
echo Build script failed.
exit /b 1

:help
echo.
echo Usage:
echo   build.bat
echo   build.bat Debug
echo   build.bat Release
echo   build.bat clean
echo   build.bat Debug clean
echo.
exit /b 0
