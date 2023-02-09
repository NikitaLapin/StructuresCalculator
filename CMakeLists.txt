cmake_minimum_required(VERSION 3.24)
project(TreeCalculator)

set(CMAKE_CXX_STANDARD 17)

add_executable(TreeCalculator Model/main.cpp Controller/InputParser.cpp Controller/InputParser.h Model/ExpressionTree.cpp Model/ExpressionTree.h Controller/TreeCalculator.cpp Controller/TreeCalculator.h View/ConsoleHandler.cpp View/ConsoleHandler.h View/InputHandler.cpp View/InputHandler.h)
