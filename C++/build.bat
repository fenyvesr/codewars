
CALL Tools\cmake-3.22.1-windows-x86_64\bin\cmake.exe -S ./ -B ./build
CALL Tools\cmake-3.22.1-windows-x86_64\bin\cmake.exe --build ./build
CALL build\Debug\Codewars.exe