cmake_minimum_required(VERSION 3.8)

project (Cache)  

set(CMAKE_CXX_STANDARD 17)
set(SOURCE_EXE  ${CMAKE_CURRENT_SOURCE_DIR}/Source/2Q-Cache.cpp)
set(SOURCE_LIB  ${CMAKE_CURRENT_SOURCE_DIR}/Headers)
set(PERFECT_EXE ${CMAKE_CURRENT_SOURCE_DIR}/PerfectCache/PerfectCache.cpp)


add_executable(2Q-Cache.exe)
add_executable(PerfectCache.exe)

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

target_sources(2Q-Cache.exe PRIVATE ${SOURCE_EXE})
target_sources(PerfectCache.exe PRIVATE ${PERFECT_EXE})
target_include_directories(2Q-Cache.exe PRIVATE ${SOURCE_LIB})