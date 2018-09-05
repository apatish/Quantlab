# Specify the minimum version for CMake

cmake_minimum_required(VERSION 3.9)

add_compile_options(-std=c++14)
# Project's name

project(ExchangeDataProcessor)
# Set the output folder where your program will be created
set(CMAKE_BINARY_DIR ${CMAKE_SOURCE_DIR}/bin)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR})
set(LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR})

find_program (BASH_PROGRAM bash)

# The following folders will be included
include_directories("${PROJECT_SOURCE_DIR}")
include_directories("${PROJECT_SOURCE_DIR}/include")
add_executable(ExchangeDataProcessor ${PROJECT_SOURCE_DIR}/main.cpp)
add_executable(ExchangeDataUnitTest ${PROJECT_SOURCE_DIR}/tests/ExchangeDataUnitTest.cpp)

include(CTest) 
set(UNIT_TEST ExchangeDataUnitTest)
add_test(ExchangeDataUnitTest NAME Test COMMAND $<TARGET_FILE:ExchangeDataUnitTest>)
add_custom_command(
         TARGET ${UNIT_TEST}
         COMMENT "Run tests"
         POST_BUILD 
         WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
         COMMAND ${CMAKE_CTEST_COMMAND} -C $<CONFIGURATION> -R "^${UNIT_TEST}$" --output-on-failures
                             )
