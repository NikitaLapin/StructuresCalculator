#include <iostream>
#include "TreeCalculator.h"
#include "../View/InputHandler.h"
#include "InputParser.h"
#include "../Model/ExpressionTree.h"
#include "../View/ConsoleHandler.h"


void processCommand(char);
void calculate();

void TreeCalculator::runWorkCycle(){
    char command = ' ';
    while (command != 'q' && command != 'Q'){
        command = ConsoleHandler::handleCommand();
        processCommand(command);
    }
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
    int size = 0;
    std::string* input = InputHandler::handleInput(&size);
    // ExpressionTree expressionTree = new ExpressionTree(input);
    // float result = expressionTree.solve();
    // std::cout << "result is " << result << std::endl;


    std::cout << "Your Input: ";
    for(int i = 0; i < size; i++){
        std::cout << input[i] << ' ';
    }
    std::cout << std::endl;
}