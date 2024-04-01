add_library(util util.cc)
target_link_libraries(util PUBLIC global_compiler_flags)
target_include_directories(util PUBLIC ${PROJECT_SOURCE_DIR})


add_subdirectory(lexer)
add_subdirectory(calc)
add_subdirectory(eval)
add_subdirectory(cmd)
add_subdirectory(ui)

if (TEST_UTIL)
	add_executable(
	  util.test
	  util.test.cc
	)

	target_include_directories(util.test PRIVATE 
		${PROJECT_SOURCE_DIR})
	target_link_libraries(
	  util.test
	  GTest::gtest_main
	  util
	  global_compiler_flags
	)
	gtest_discover_tests(util.test WORKING_DIRECTORY ${PROJECT_BINARY_DIR})
endif()
