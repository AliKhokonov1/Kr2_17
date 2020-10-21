cmake_minimum_required(VERSION 2.8)
project(kr2_13)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} --std=c++11")
add_executable(lalala main.cpp Autotest.cpp CComplexVector.cpp CComplexPoint.cpp CComplexPoint.hpp CComplexVector.hpp)