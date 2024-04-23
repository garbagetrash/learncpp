cmake_minimum_required(VERSION 3.10)
project(learncpp)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_executable(tutorial src/tutorial.cpp)
target_include_directories(tutorial PUBLIC include)
