#include <iostream>
#include "LGS.h"

int main() {
    std::string input;

    std::cout << "Matrix operation checker" << std::endl;
    std::cout << "possible operations are adding and multiplying lines";

    LGS Matrix;

    while (1) {
        std::cout << "possible operations: \n"
                  << "ADD // (row1, row2, factor) // adds row1 * factor to row2\n"
                  << "MUL //(row, factor) // multiplies row by factor\n"
                  << "quit // quits the program\n";

        std::getline(std::cin, input);
        if (input == "quit") {
            std::cout << Matrix;
            exit(0);
        } else if (input == "ADD") {
            Matrix.add();
        } else if (input == "MUL") {
            Matrix.multiply();
        } else {
            std::cout << "invalid input\n";
        }
        std::cout << Matrix;
    }

    return 0;
}
