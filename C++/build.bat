@RD /S /Q build
@RD /S /Q doc

CALL Tools\cmake-3.22.1-windows-x86_64\bin\cmake.exe -S ./ -B ./build
CALL Tools\cmake-3.22.1-windows-x86_64\bin\cmake.exe --build ./build
CALL Tools\doxygen-1.9\doxygen.exe Doxygen_config

CALL build\Debug\Codewars.exe