cmake_minimum_required(VERSION 3.10)
project(MyProject)


set(CMAKE_C_STANDARD 99)

include_directories(${PROJECT_SOURCE_DIR}/lib/LinkdedList/include/)

# Define options for building static libs, dynamic libs, and unit tests
option(BUILD_STATIC_LIBS "Build static libraries" OFF)
option(BUILD_SHARED_LIBS "Build shared libraries" OFF)
option(BUILD_UNIT_TESTS "Build unit tests" OFF)
option(BUILD_MAIN_PROGRAM "Build main program" OFF)

# Add subdirectories
add_subdirectory(${PROJECT_SOURCE_DIR}/lib/LinkdedList/src/))

if (BUILD_UNIT_TESTS)
    enable_testing()
    add_subdirectory(tests)
endif()
