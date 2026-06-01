@echo off
setlocal

if /I "%~1"=="help" goto :help
if /I "%~1"=="-h" goto :help
if /I "%~1"=="--help" goto :help

set "CMAKE_PATH=%~dp0Tools\cmake-3.22.1-windows-x86_64\bin"
set "DOXYGEN_PATH=%~dp0Tools\doxygen-1.17.0.windows.x64.bin"
set "BUILD_DIR=%~dp0build"
set "DOC_DIR=%~dp0doc"

if /I "%~1"=="clean" (
    echo Cleaning build and doc folders...
    rd /s /q "%BUILD_DIR%" 2>nul
    rd /s /q "%DOC_DIR%" 2>nul
)

echo Configuring...
"%CMAKE_PATH%\cmake.exe" -G "MinGW Makefiles" -B "%BUILD_DIR%" -DCMAKE_BUILD_TYPE=Release || goto :error

echo Building...
"%CMAKE_PATH%\cmake.exe" --build "%BUILD_DIR%" || goto :error

echo Running tests...
"%CMAKE_PATH%\ctest.exe" --test-dir "%BUILD_DIR%" --output-on-failure || goto :error

echo Generating documentation...
"%DOXYGEN_PATH%\doxygen.exe" "%~dp0Doxygen_config" || goto :error

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
echo   build.bat [clean]
echo   build.bat help
echo.
echo Options:
echo   clean     Delete build/ and doc/ before building.
echo   help      Show this help message.
echo   -h        Show this help message.
echo   --help    Show this help message.
echo.
echo Examples:
echo   build.bat
echo   build.bat clean
echo   build.bat help
echo.
echo What this script does:
echo   1. Configures the project with CMake.
echo   2. Builds the project using MinGW Makefiles.
echo   3. Runs the CTest tests.
echo   4. Generates Doxygen documentation.
echo.
exit /b 0