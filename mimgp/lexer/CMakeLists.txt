add_library(lexer lexer.cc tokens.cc)
target_link_libraries(lexer PUBLIC global_compiler_flags)
target_include_directories(lexer PUBLIC ${PROJECT_SOURCE_DIR})
