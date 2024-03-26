add_library(calclexer calclexer.cc calctokens.cc)
target_link_libraries(calclexer PUBLIC global_compiler_flags)
target_include_directories(calclexer PUBLIC ${PROJECT_SOURCE_DIR})

if (TEST_CALCLEXER)
	add_executable(
	  calclexer.test
	  calclexer.test.cc
	)

	target_include_directories(calclexer.test PRIVATE 
		${PROJECT_SOURCE_DIR})
	target_link_libraries(
	  calclexer.test
	  GTest::gtest_main
	  calclexer
	  global_compiler_flags
	)
	gtest_discover_tests(calclexer.test WORKING_DIRECTORY ${PROJECT_BINARY_DIR})
endif()
