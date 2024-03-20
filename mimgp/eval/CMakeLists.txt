add_library(eval eval.cc)
target_link_libraries(eval PUBLIC global_compiler_flags)
target_include_directories(eval PUBLIC ${PROJECT_SOURCE_DIR})

if (TEST_EVAL)
	add_executable(
	  eval.test
	  eval.test.cc
	)

	target_include_directories(eval.test PRIVATE 
		${PROJECT_SOURCE_DIR})
	target_link_libraries(
	  eval.test
	  GTest::gtest_main
	  eval
	  global_compiler_flags
	)
	gtest_discover_tests(eval.test WORKING_DIRECTORY ${PROJECT_BINARY_DIR})
endif()
