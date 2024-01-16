//
// Created by Christian on 16.01.2024.
//

#include "ParsingUtils.h"

int ParsingUtils::getIntFromCin(std::string message) {
    int input;
    char remainingChar;

    while (1) {
        std::cout << message;
        std::cin >> input;

        if (!(std::cin.fail() || (std::cin.get(remainingChar) && remainingChar != '\n'))) {
            return input;
        }
        else {
            std::cin.clear();
        }
    }
}