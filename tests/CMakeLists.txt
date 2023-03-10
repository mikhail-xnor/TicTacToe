cmake_minimum_required(VERSION 3.16)

set(SOURCES test_setup.h
	test_setup.cpp
	test_map.cpp
	test_engine.cpp)

enable_testing()

find_package(GTest QUIET)

if (NOT GTEST_LIBRARY)
	message("GTest dependencies not found local, and installed from reposiotry!")
	include(FetchContent)
	FetchContent_Declare(
	  googletest
	  URL https://github.com/google/googletest/archive/5376968f6948923e2411081fd9372e71a59d8e77.zip)
	set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
	FetchContent_MakeAvailable(googletest)
endif()

add_executable(${TESTS_NAME} ${SOURCES})

target_include_directories(${TESTS_NAME} PRIVATE ../src/
    ${Boost_INCLUDE_DIR}
	${GTEST_INCLUDE_DIR})

target_link_libraries(${TESTS_NAME} PRIVATE ${LIBRARY_NAME}
    ${Boost_LIBRARIES}
	${GTEST_LIBRARIES})

add_test(NAME ${TESTS_NAME}
	COMMAND ${TESTS_NAME})
