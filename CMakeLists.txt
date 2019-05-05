cmake_minimum_required(VERSION 3.12)
project(ticktacktoe)
set(CMAKE_CXX_STANDARD 14)

file(GLOB SRC "*.h" "*.cpp")

add_executable(ticktacktoe main.cpp ${SRC})