cmake_minimum_required(VERSION 3.0)

project(minic-compiler)

set(lib_name "minic-compiler")
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib/)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib/)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin/)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED 11)
set(CMAKE_C_FLAGS "-g")

file(GLOB includes "eeyore2tigger/*.h" "common/*.h" "minic2eeyore/*.h" "tigger2riscv/*.h")
file(GLOB sources "eeyore2tigger/*.c" "common/*.c" "minic2eeyore/*.c" "tigger2riscv/*.c")


include_directories("eeyore2tigger/" "minic2eeyore/" "common/" "tigger2riscv/")

add_library(${lib_name} SHARED ${includes} ${sources})

set(CMAKE_C_FLAGS "-g")
add_executable(main main.c)
target_link_libraries(main LINK_PUBLIC ${lib_name})