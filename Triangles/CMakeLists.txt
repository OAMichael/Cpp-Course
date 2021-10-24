cmake_minimum_required(VERSION 2.8)

add_executable(Source/TrianglesIntersection.exe Source/TrianglesIntersection.cpp)

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