cmake_minimum_required(VERSION 3.12)
project(Task1)

set(CMAKE_CXX_STANDARD 14)
#set(CMAKE_CXX_FLAGS_RELEASE "-DNDEBUG -Wall -O2")

#SET(SFML_FLAGS "-lsfml-graphics -lsfml-window -lsfml-system")
#SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${SFML_FLAGS}")
#SET(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} ${SFML_FLAGS}")
add_executable(Task1 main.cpp GameLife.cpp GameLife.h Field.cpp Field.h GraphicViewer.cpp GraphicViewer.h)

# Detect and add SFML
set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake_modules" ${CMAKE_MODULE_PATH})
#Find any version 2.X of SFML
#See the FindSFML.cmake file for additional details and instructions
find_package(SFML REQUIRED graphics window system)
if(SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(Task1 ${SFML_LIBRARIES} ${SFML_DEPENDENCIES})
endif()


# Install target
install(TARGETS Task1 DESTINATION bin)

