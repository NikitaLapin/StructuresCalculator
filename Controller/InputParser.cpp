#include <iostream>
#include <utility>
#include "InputParser.h"


int separateString(std::string, char, std::string*);
std::string chunk(int, int, std::string);

int InputParser::parseInput(std::string input, std::string* result){
    return separateString(std::move(input), ' ', result);
}

int separateString(std::string rawString, char separator, std::string* result)
{
    int currentSize = 0;
    int previousSeparatorIndex = -1;

    for(int i = 0; i < rawString.size(); i++){
        if(rawString[i] == separator){
            std::string currentChunk = chunk(previousSeparatorIndex + 1, i - 1, rawString);
            result[currentSize] = currentChunk;
            currentSize++;
            previousSeparatorIndex = i;
        }
    }

    std::string currentChunk = chunk(previousSeparatorIndex + 1, rawString.size() - 1, rawString);
    result[currentSize] = currentChunk;
    currentSize++;

    return currentSize;
}

std::string chunk(int startIndex, int endIndex, std::string rawString){
    std::string chunk;
    for(int j = startIndex; j <= endIndex; j++) chunk += rawString[j];
    return chunk;
}
