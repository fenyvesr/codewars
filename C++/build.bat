@RD /S /Q build
@RD /S /Q doc

CALL Tools\cmake-3.22.1-windows-x86_64\bin\cmake.exe -B ./build -DCMAKE_BUILD_TYPE=Release
CALL Tools\cmake-3.22.1-windows-x86_64\bin\cmake.exe --build ./build --config Release
CALL Tools\cmake-3.22.1-windows-x86_64\bin\ctest.exe -C Release --output-on-failure
CALL Tools\doxygen-1.9.2.windows.x64\doxygen.exe Doxygen_config

CALL build\Release\Codewars.exe