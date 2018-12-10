cmake_minimum_required(VERSION 3.12)
project(Task3)
set(CMAKE_CXX_STANDARD 17)

find_package(GTest REQUIRED)
include_directories(test)
add_executable(runTests test/unit_tests.cpp)
target_link_libraries(runTests ${GTEST_LIBRARIES} pthread)

add_executable(Task3 main.cpp Array.h Functions.h)

