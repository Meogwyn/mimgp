add_library(lexer lexer.cc tokens.cc)
target_link_libraries(lexer PUBLIC global_compiler_flags)
target_include_directories(lexer PUBLIC ${PROJECT_SOURCE_DIR})

if (TEST_LEXER)
	add_executable(
	  lexer.test
	  lexer.test.cc
	)

	target_include_directories(lexer.test PRIVATE 
		${PROJECT_SOURCE_DIR})
	target_link_libraries(
	  lexer.test
	  GTest::gtest_main
	  lexer
	  global_compiler_flags
	)
	gtest_discover_tests(lexer.test WORKING_DIRECTORY ${PROJECT_BINARY_DIR})
endif()
