add_library(cmd cmd.cc cmd_binds.cc cmdotp.cc)
target_link_libraries(cmd PUBLIC global_compiler_flags)
target_include_directories(cmd PUBLIC ${PROJECT_SOURCE_DIR})
