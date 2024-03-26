add_subdirectory(calclexer)
add_subdirectory(calcparser)
add_subdirectory(group)

add_library(calc calc.cc)
target_link_libraries(calc PUBLIC global_compiler_flags calclexer calcparser 
	group)
target_include_directories(calc PUBLIC ${PROJECT_SOURCE_DIR})

if (TEST_CALC)
	add_executable(
	  calc.test
	  calc.test.cc
	)

	target_include_directories(calc.test PRIVATE 
		${PROJECT_SOURCE_DIR})
	target_link_libraries(
	  calc.test
	  GTest::gtest_main
	  calc
	  global_compiler_flags
	)
	gtest_discover_tests(calc.test WORKING_DIRECTORY ${PROJECT_BINARY_DIR})
endif()
