cmake_minimum_required(VERSION 3.8)

project (Triangles)  

set(CMAKE_CXX_STANDARD 17)
set(SOURCE_EXE ${CMAKE_CURRENT_SOURCE_DIR}/Source/TrianglesIntersection.cpp)
set(SOURCE_LIB ${CMAKE_CURRENT_SOURCE_DIR}/Headers)

add_executable(TrianglesIntersection.exe)

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

target_sources(TrianglesIntersection.exe PRIVATE ${SOURCE_EXE})
target_include_directories(TrianglesIntersection.exe PRIVATE ${SOURCE_LIB})
