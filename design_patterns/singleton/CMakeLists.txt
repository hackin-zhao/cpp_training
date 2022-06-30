cmake_minimum_required(VERSION 3.10.1)
project(singleton CXX )

set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

add_executable(singleton
    main.cpp
)
