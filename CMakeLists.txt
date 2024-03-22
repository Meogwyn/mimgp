cmake_minimum_required(VERSION 3.27.0)

project(elg_smp_attack VERSION 0.1)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

option(ENABLE_TESTING "Enable testing - unit tests won't run get built this. \
Or rather, they will try to get built, and then crash the entire build process \
as a result." OFF)
option(TEST_EVAL "Enable building of eval unit tests." OFF)
option(TEST_LEXER "Enable building of eval lexer (not calc lexer) unit tests." 
	OFF)

if (ENABLE_TESTING)
	enable_testing()
	# Prepare for testing.
	# Google Test Dependency.
	include(FetchContent)

	FetchContent_Declare(
	  googletest
	  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
	)
	FetchContent_MakeAvailable(googletest)
	include(GoogleTest)
endif()

add_library(global_compiler_flags INTERFACE)
target_compile_options(global_compiler_flags INTERFACE -Wall -g)

add_library(util mimgp/util.cc)
target_link_libraries(util PUBLIC global_compiler_flags)

add_subdirectory(mimgp)

add_executable(main mimgp/main.cc)
target_link_libraries(main PUBLIC global_compiler_flags)
target_link_libraries(main PUBLIC util)
target_link_libraries(main PUBLIC ui)
target_link_libraries(main PUBLIC eval)

target_include_directories(main PUBLIC ${PROJECT_SOURCE_DIR}/include)
