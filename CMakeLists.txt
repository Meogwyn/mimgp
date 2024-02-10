cmake_minimum_required(VERSION 3.27.0)

project(elg_smp_attack VERSION 0.1)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(global_compiler_flags INTERFACE)
target_compile_options(global_compiler_flags INTERFACE -Wall -g)

add_executable(main src/main.cc)
target_link_libraries(main PUBLIC global_compiler_flags)
target_link_libraries(main PUBLIC util)
target_include_directories(main PUBLIC ${PROJECT_SOURCE_DIR}/include)
