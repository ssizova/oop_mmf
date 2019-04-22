cmake_minimum_required(VERSION 3.12)
project(Task5)

set(CMAKE_CXX_STANDARD 17)

include_directories(.)

find_package(GTest REQUIRED)
include_directories(test)
add_executable(runTests test/tests.cpp)
target_link_libraries(runTests ${GTEST_LIBRARIES} pthread)
add_executable(Task5
        CSVParser.h
        InputIterator.h
        main.cpp TupleLibrary.h)
