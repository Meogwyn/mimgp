add_library(calc calc.cc group.cc symb_table.cc)
target_link_libraries(calc PUBLIC global_compiler_flags)
target_include_directories(calc PUBLIC ${PROJECT_SOURCE_DIR})
