cmake_minimum_required(VERSION 3.25)
project(graph_technopark)

set(CMAKE_CXX_STANDARD 17)

file(GLOB SOURCES src/*.cpp)

add_executable(${PROJECT_NAME} ${SOURCES})

target_include_directories(${PROJECT_NAME} PRIVATE inc)
