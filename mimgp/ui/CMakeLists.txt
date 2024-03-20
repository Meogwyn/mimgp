add_library(ui ui.cc tabl_rend.cc uinp.cc)
target_link_libraries(ui PUBLIC global_compiler_flags)
target_link_libraries(ui PUBLIC cmd)
target_include_directories(ui PUBLIC ${PROJECT_SOURCE_DIR})
