cmake_minimum_required(VERSION 3.12)
project(Task4)
set(CMAKE_CXX_STANDARD 17)

find_package(GTest REQUIRED)
include_directories(test)
add_executable(runTests test/tests.cpp test/tests.cpp Haffman_algorithm.cpp)
target_link_libraries(runTests ${GTEST_LIBRARIES} pthread)


add_executable(Task4 main.cpp Haffman_algorithm.cpp TreeforBytes.cpp TreeforBytes.h BitWriter.cpp BitWriter.h Encoder.cpp Encoder.h Decoder.cpp)