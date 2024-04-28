cmake_minimum_required(VERSION 3.16.3)
project(my-cpp-project)

# Set C++ standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Include directories
include_directories(include)

# Globbing source files for the main application
file(GLOB MAIN_SOURCES "src/*.cpp")
list(REMOVE_ITEM MAIN_SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp")

# Globbing source files for tests
file(GLOB TEST_SOURCES "tests/*.cpp")
list(APPEND TEST_SOURCES ${MAIN_SOURCES})

# Add executable for the main application
add_executable(${PROJECT_NAME} src/main.cpp ${MAIN_SOURCES})

# Add executable for tests
add_executable(tests ${TEST_SOURCES})

# Link Google Test to the test executable
add_subdirectory(lib/googletest)
target_link_libraries(tests gtest gtest_main)
target_include_directories(tests PUBLIC ${CMAKE_SOURCE_DIR}/lib/googletest/googletest/include)

# Add test command
enable_testing()
add_test(NAME my-cpp-project-tests COMMAND tests)