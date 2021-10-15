cmake_minimum_required(VERSION 2.8)

add_executable(TrianglesIntersect.exe TrianglesIntersect.cpp)

add_compile_options(
    -Werror

    -O3

    -Wall 
    -Wextra 
     
    -Wnarrowing 
    -Wconversion 
    -Wwrite-strings 
    -Wcast-qual 
    -Wundef    
    -Wreturn-type
)