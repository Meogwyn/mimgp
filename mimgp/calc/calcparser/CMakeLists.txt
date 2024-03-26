add_library(calcparser calcparser.cc st.cc tacode.cc)
target_link_libraries(calcparser PUBLIC global_compiler_flags)
target_include_directories(calcparser PUBLIC ${PROJECT_SOURCE_DIR})

if (TEST_CALCPARSER)
	add_executable(
	  calcparser.test
	  calcparser.test.cc
	)

	target_include_directories(calcparser.test PRIVATE 
		${PROJECT_SOURCE_DIR})
	target_link_libraries(
	  calcparser.test
	  GTest::gtest_main
	  calcparser
	  global_compiler_flags
	)
	gtest_discover_tests(calcparser.test WORKING_DIRECTORY ${PROJECT_BINARY_DIR})
endif()
#if (TEST_ST)
#endif()
#if (TEST_TACODE)
#endif()
