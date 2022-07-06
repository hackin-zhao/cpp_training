cmake_minimum_required(VERSION 3.10.1)
project(command CXX)

set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

add_executable(command
    main.cpp
)
