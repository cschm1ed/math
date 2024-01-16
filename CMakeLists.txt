cmake_minimum_required(VERSION 3.27)
project(untitled)

set(CMAKE_CXX_STANDARD 23)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Werror -Wextra")
add_executable(untitled main.cpp
        LGS.h
        LGS.cpp
        ParsingUtils.cpp
        ParsingUtils.h)
