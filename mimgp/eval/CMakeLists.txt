message("lol")
add_library(eval eval.cc exec.cc cmds.cc cmd_binds.cc lexer.cc parser.cc)
target_link_libraries(eval PUBLIC global_compiler_flags)
