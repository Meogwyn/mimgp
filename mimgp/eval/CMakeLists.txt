add_library(eval eval.cc)
target_link_libraries(eval PUBLIC global_compiler_flags)
target_include_directories(eval PUBLIC ${PROJECT_SOURCE_DIR})
