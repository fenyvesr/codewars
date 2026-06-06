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

set "CMAKE_PATH=%~dp0Tools\cmake-4.3.3\bin"
set "DOXYGEN_PATH=%~dp0Tools\doxygen-1.17.0.windows.x64.bin"
set "BUILD_DIR=%~dp0build"
set "DOC_DIR=%~dp0doc"
set "CMAKE_PROFILE=%BUILD_DIR%\cmake-profile.json"

if defined DO_CLEAN (
    echo Cleaning build and doc folders...
    rd /s /q "%BUILD_DIR%" 2>nul
    rd /s /q "%DOC_DIR%" 2>nul
)

if not exist "%BUILD_DIR%" mkdir "%BUILD_DIR%"

echo.
echo ==========================
echo Configure %BUILD_TYPE%
echo ==========================
powershell -NoProfile -ExecutionPolicy Bypass -Command "$sw=[Diagnostics.Stopwatch]::StartNew(); & '%CMAKE_PATH%\cmake.exe' -G 'MinGW Makefiles' -B '%BUILD_DIR%' -DCMAKE_BUILD_TYPE=%BUILD_TYPE% --profiling-format=google-trace --profiling-output='%CMAKE_PROFILE%'; $code=$LASTEXITCODE; $sw.Stop(); Write-Host ('Configure elapsed: {0}' -f $sw.Elapsed); if (Test-Path '%CMAKE_PROFILE%') { Write-Host 'CMake profile written to: %CMAKE_PROFILE%' }; exit $code"
if errorlevel 1 goto :error

echo.
echo ==========================
echo Build %BUILD_TYPE%
echo ==========================
powershell -NoProfile -ExecutionPolicy Bypass -Command "$sw=[Diagnostics.Stopwatch]::StartNew(); & '%CMAKE_PATH%\cmake.exe' --build '%BUILD_DIR%' --verbose; $code=$LASTEXITCODE; $sw.Stop(); Write-Host ('Build elapsed: {0}' -f $sw.Elapsed); exit $code"
if errorlevel 1 goto :error

echo.
echo ==========================
echo Tests
echo ==========================
powershell -NoProfile -ExecutionPolicy Bypass -Command "$sw=[Diagnostics.Stopwatch]::StartNew(); & '%CMAKE_PATH%\ctest.exe' --test-dir '%BUILD_DIR%' --output-on-failure; $code=$LASTEXITCODE; $sw.Stop(); Write-Host ('Tests elapsed: {0}' -f $sw.Elapsed); exit $code"
if errorlevel 1 goto :error

if /I "%BUILD_TYPE%"=="Release" (
    echo.
    echo ==========================
    echo Documentation
    echo ==========================
    powershell -NoProfile -ExecutionPolicy Bypass -Command "$sw=[Diagnostics.Stopwatch]::StartNew(); & '%DOXYGEN_PATH%\doxygen.exe' '%~dp0Doxygen_config'; $code=$LASTEXITCODE; $sw.Stop(); Write-Host ('Documentation elapsed: {0}' -f $sw.Elapsed); exit $code"
    if errorlevel 1 goto :error
)

echo.
echo Done.
echo Open the CMake profile in Perfetto if needed:
echo   https://ui.perfetto.dev
echo   %CMAKE_PROFILE%
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
