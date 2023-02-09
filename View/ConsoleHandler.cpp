#include <iostream>
#include "ConsoleHandler.h"

std::string askForInput();
char waitForCorrectInput(std::string);
char commandToLower(char command);

char ConsoleHandler::handleCommand() {
    std::string input = askForInput();
    char command = waitForCorrectInput(input);
    return commandToLower(command);
}

char waitForCorrectInput(std::string first_input){
    while(first_input.size() > 1){
        std::cout << "Command cannot be longer than one symbol" << std::endl;
        first_input = askForInput();
    }

    return first_input[0];
}

std::string askForInput(){
    std::string input;
    std::cout << "Enter a command. Enter 'h' for help" << std::endl;
    std::cin >> input;
    return input;
}

char commandToLower(char command){
    char lower_command = (char) tolower(command);
    return lower_command;
}