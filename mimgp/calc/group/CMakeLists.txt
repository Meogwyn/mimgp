add_library(group group.cc)
target_link_libraries(group PUBLIC global_compiler_flags)
target_include_directories(group PUBLIC ${PROJECT_SOURCE_DIR})

if (TEST_GROUP)
	add_executable(
	  group.test
	  group.test.cc
	)

	target_include_directories(group.test PRIVATE 
		${PROJECT_SOURCE_DIR})
	target_link_libraries(
	  group.test
	  GTest::gtest_main
	  group
	  global_compiler_flags
	)
	gtest_discover_tests(group.test WORKING_DIRECTORY ${PROJECT_BINARY_DIR})
endif()
