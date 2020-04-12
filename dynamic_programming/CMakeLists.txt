cmake_minimum_required(VERSION 3.13)

set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")

project(dp_practice)

add_executable(
	ugly_number_simple
	ugly_numbers.cpp
)