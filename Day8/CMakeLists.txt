cmake_minimum_required(VERSION 2.8)

project(Day8)
SET(CMAKE_CXX_FLAGS "-std=c++17")
file(GLOB SRC "*.cpp" "*.h") # search all the files globally that matches any of the patterns, load them into SRC variable
add_executable(${PROJECT_NAME} "${SRC}")
