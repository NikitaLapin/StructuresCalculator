#include <iostream>
#include "TreeCalculator.h"
#include "InputParser.h"
#include "ExpressionTree.h"


char getCommandInput();
void processCommand(char);
void calculate();

void TreeCalculator::runWorkCycle(){
    char command = ' ';
    while (command != 'q' && command != 'Q'){
        command = getCommandInput();
        processCommand(command);
    }
}

char getCommandInput(){
    std::string input;
    std::cout << "Enter a command. Enter 'h' for help" << std::endl;
    std::cin >> input;

    while(input.size() > 1){
        std::cout << "Command cannot be longer than one symbol" << std::endl;
        std::cout << "Enter a command. Enter 'h' for help" << std::endl;
        std::cin >> input;
    }

    char lower_command = (char) tolower(input[0]);
    return lower_command;
}

void processCommand(char command) {
    switch (command) {
        case 'h':
            std::cout << "H - help \nQ - quit \nC - calculate \n";
            break;
        case 'q':
            std::cout << "Collapsing program...\n";
            break;
        case 'c':
            calculate();
            break;
        default:
            std::cout << "Unknown command. Write 'H' for help :) \n";
            break;
    }
}

void calculate(){
    std::string input = InputParser::getInput();
    ExpressionTree expressionTree = InputParser::parseInput(input);
    float result = expressionTree.solve();
    std::cout << "result is " << result << std::endl;
}