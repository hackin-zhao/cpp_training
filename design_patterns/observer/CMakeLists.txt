cmake_minimum_required(VERSION 3.10.1)
project(observer CXX)

set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17")

add_executable(observer
    main.cpp
)
