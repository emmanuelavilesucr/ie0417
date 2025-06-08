cmake_minimum_required(VERSION 3.10)
project(CalculatorTests)

set(CMAKE_CXX_STANDARD 11)

find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

add_executable(runTests test_calculator.cpp)
target_link_libraries(runTests ${GTEST_LIBRARIES} pthread)
