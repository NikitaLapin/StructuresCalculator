cmake_minimum_required(VERSION 3.24)
project(TreeCalculator)

set(CMAKE_CXX_STANDARD 17)

add_executable(TreeCalculator main.cpp InputParser.cpp InputParser.h ExpressionTree.cpp ExpressionTree.h TreeCalculator.cpp TreeCalculator.h)
