cmake_minimum_required(VERSION 3.12)
project(Task3)
#add_subdirectory(cmake-build-debug)
#add_subdirectory(test)
set(CMAKE_CXX_STANDARD 14)

find_package(GTest REQUIRED)
include_directories(test)

add_executable(runTests test/unit_tests.cpp)
target_link_libraries(runTests ${GTEST_LIBRARIES} pthread)

#find_package(Threads REQUIRED)

add_executable(Task3 main.cpp Array.cpp Functions.h)
#set(core_SRCS ADD ALL SOURCE FILES HERE)

#add_library(core ${core_SRCS} test/unit_tests.cpp)
#add_executable(exe main.cpp)
#target_link_libraries(exe core)