cmake_minimum_required(VERSION 2.8)
project(kr2_17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} --std=c++11")
add_executable(hahaha main.cpp Autotest.cpp FractionVector.cpp FractionPoint.cpp FractionPoint.h FractionVector.h)