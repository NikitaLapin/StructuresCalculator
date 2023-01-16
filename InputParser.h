#pragma once

#include "ExpressionTree.h"

class InputParser {
public:
    static std::string getInput();
    static ExpressionTree parseInput(std::string input);
};
