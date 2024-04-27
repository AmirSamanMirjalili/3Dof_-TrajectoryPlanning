cmake_minimum_required(VERSION 3.12)
project(my-cpp-project)

# Set C++ standard
set(CMAKE_CXX_STANDARD 11)
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
add_executable(my-cpp-project ${SOURCES} ${HEADERS})

# Add include directories
target_include_directories(my-cpp-project PUBLIC include)

# Add test executable target
add_executable(tests tests/test_main.cpp ${SOURCES} ${HEADERS})

# Add test include directories
target_include_directories(tests PUBLIC include)

# Add test libraries or dependencies if needed
# target_link_libraries(tests <library_name>)

# Add test command
enable_testing()
add_test(NAME my-cpp-project-tests COMMAND tests)