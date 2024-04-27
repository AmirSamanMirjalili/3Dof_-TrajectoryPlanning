cmake_minimum_required(VERSION 3.16.3)
project(my-cpp-project)

# Set C++ standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add source files
set(SOURCES
    src/main.cpp
    src/other_classes.cpp
)

# Add header files
set(HEADERS
    include/other_classes.h
)

# Add executable target
add_executable(${PROJECT_NAME} ${SOURCES} ${HEADERS})

# Add include directories
target_include_directories(${PROJECT_NAME} PUBLIC include)

# Add test executable target
add_executable(tests tests/test_main.cpp ${SOURCES} ${HEADERS})

# Add test include directories
target_include_directories(tests PUBLIC include)

# link Google Test to the test executable
add_subdirectory(lib/googletest)
target_link_libraries(tests gtest gtest_main)
target_include_directories(tests PUBLIC ${CMAKE_SOURCE_DIR}/lib/googletest/googletest/include)
# Add test command
enable_testing()
add_test(NAME my-cpp-project-tests COMMAND tests)