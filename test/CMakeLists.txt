cmake_minimum_required(VERSION 3.10)

project (Demo)
aux_source_directory(. DIR_SRCS)


ADD_DEFINITIONS(
 -O3 -W -Wall
 -std=c++17
)

add_executable(Demo.out main.cpp)
