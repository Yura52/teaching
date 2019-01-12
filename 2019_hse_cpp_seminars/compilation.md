## Compilation
Linux/macOS (compilation from terminal):  
`<compiler> -std=c++17 -Wall -Werror my_program.cpp [-o my_program]`  
Examples:
```
clang++ -std=c++17 -Wall -Werror my_program.cpp
clang++ -std=c++17 -Wall -Werror my_program.cpp -o my_program
g++ -std=c++17 -Wall -Werror my_program.cpp
g++ -std=c++17 -Wall -Werror my_program.cpp -o my_program
```

CLion:
1. Make sure that the file `CMakeLists.txt` contains "set(CMAKE_CXX_STANDARD 17)" or something similar
2. Make sure that the file `CMakeLists.txt` contains "set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra")"

Visual Studio:
1. Properties > C/C++ > Language > *set "C++ Language Standard" to "C++17"*
2. Properties > C/C++ > General > *set "Treat Warnings As Errors" to "Yes"*
3. Properties > C/C++ > General > *set "Warning Level" to "EnableAllWarnings"* (if it leads to warnings
that are not caused by your code than change this setting to "Level4")


