cmake_minimum_required(VERSION 3.12)
project(Word_couner)

set(CMAKE_CXX_STANDARD 11)

add_executable(Word_couner word_count.cpp Words_reader.h Words_reader.cpp Frequency_counter.h Frequency_counter.cpp)