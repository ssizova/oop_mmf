cmake_minimum_required(VERSION 3.12)
project(Task3)
#add_subdirectory(cmake-build-debug)
#add_subdirectory(test)
set(CMAKE_CXX_STANDARD 17)

find_package(GTest REQUIRED)
include_directories(test)
#SET(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS}-S -masm=intel -save-temps -fverbose-asm")
add_executable(runTests test/unit_tests.cpp)
target_link_libraries(runTests ${GTEST_LIBRARIES} pthread)

#find_package(Threads REQUIRED)

add_executable(Task3 main.cpp Array.h Functions.h)


#set(core_SRCS ADD ALL SOURCE FILES HERE)

#add_library(core ${core_SRCS} test/unit_tests.cpp)
#add_executable(exe main.cpp)
#target_link_libraries(exe core)