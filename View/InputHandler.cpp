#include <iostream>
#include <utility>
#include "InputHandler.h"
#include "../Controller/InputParser.h"

bool isInputCorrect(std::string);
bool isOperand(const std::string&);
bool isOperator(std::string);
bool isOperatorSupported(char);

std::string supportedOperators = {'+', '-', '*', '/'};

std::string* InputHandler::handleInput(int* inputChunksAmount) {
    std::cout << "Calculate expression: " << std::endl;
    std::string rawInput;
    std::cin.ignore();
    getline(std::cin, rawInput);

    while(!isInputCorrect(rawInput)){
        std::cout << "Incorrect input. Try again :)" << std::endl;
        getline(std::cin, rawInput);
    }

    auto* finalInput = new std::string;
    *inputChunksAmount = InputParser::parseInput(rawInput, finalInput);
    return finalInput;
}

bool isInputCorrect(std::string rawInput) {
    auto *separatedInput = new std::string;
    int size = InputParser::parseInput(std::move(rawInput), separatedInput);

    int currentStackSize = 0;
    for(int i = 0; i < size; i++){
        if(isOperand(separatedInput[i])) currentStackSize++;
        if(isOperator(separatedInput[i])) currentStackSize--;
        if(currentStackSize <= 0) return false;
    }

    return currentStackSize == 1;
}

bool isOperand(const std::string& symbol){
    for(char i : symbol)
        if(i < '0' || i > '9') return false;

    return true;
}

bool isOperator(std::string symbol){
    if(symbol.size() > 1) return false;
    return isOperatorSupported(symbol[0]);
}

bool isOperatorSupported(char symbol) {
    for (char supportedOperator: supportedOperators)
        if (symbol == supportedOperator) return true;

    return false;
}

