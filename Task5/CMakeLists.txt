cmake_minimum_required(VERSION 3.12)
project(Task5)

set(CMAKE_CXX_STANDARD 17)

include_directories(.)

add_executable(Task5
        CSVParser.h
        InputIterator.h
        main.cpp TupleLibrary.h)
