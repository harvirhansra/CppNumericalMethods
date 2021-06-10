cmake_minimum_required(VERSION 3.0)
project(NumericalMethods)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17")

include_directories( ./include ./src )
add_executable(NumericalMethods src/main.cpp src/Differentiation.cpp src/Integration.cpp src/PolynomialApproximation.cpp src/SingleNonLinear.cpp)
