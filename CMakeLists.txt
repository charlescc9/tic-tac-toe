cmake_minimum_required(VERSION 3.12)
project(tic-tac-toe)
set(CMAKE_CXX_STANDARD 14)

file(GLOB SRC "*.h" "*.cpp")

add_executable(tic-tac-toe main.cpp ${SRC})