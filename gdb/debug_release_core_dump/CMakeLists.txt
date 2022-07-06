cmake_minimum_required(VERSION 3.10.1)
project(debug_relase CXX)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

if(CMAKE_BUILD_TYPE STREQUAL Debug)
    add_definitions(-g)
endif()

include(SplitDebugInformation.cmake)

add_executable(test
    main.cpp
)

SPLIT_DEBUG_INFORMATION(test)

# 1、objcopy --only-keep-debug projectD projectsymbol.dbg #生成符号表；
# 2、gdb -q --symbol=projectsymbol.dbg -exec=projectR #加载符号表；
