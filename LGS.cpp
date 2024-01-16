
#include "LGS.h"
#include <iomanip>

LGS::LGS() {
    std::cout << "creating LGS\n";
    _matrix = new std::vector<std::vector<double> *>;
    std::vector<double> *current_row;

    getDimensions();
    for (int i = 0; i < _rows; ++i) {
        current_row = new std::vector<double>;
        std::cout << "enter row " << i << " :\n";
        for (int j = 0; j < _cols;  ++j) {
            current_row->push_back(ParsingUtils::getIntFromCin(""));
        }
        _matrix->push_back(current_row);
    }
    std::cout << "LGS created\n";
    std::cout << *this;
}

void LGS::getDimensions() {
    _rows = ParsingUtils::getIntFromCin("enter number of rows:");
    _cols = ParsingUtils::getIntFromCin("enter number of columns:");
    if (_rows < 1 ||_cols < 1) {
        std::cout << "either dimension must be larger than 0 \n";
        getDimensions();
    }
}

LGS::~LGS() {
    // Release allocated memory for the matrix
    for (auto row : *_matrix) {
        delete row;
    }
    delete _matrix;
}

void LGS::multiply() {
    t_mul input = getMulInput();

    for (int i = 0; i < _cols; ++i) {
        (*((*_matrix)[input.r - 1]))[i] *= input.factor;
    }
}

void LGS::add() {
    t_add addInput = getAddInput();
    int i = 0;
    std::vector<double> rowCopy  = *((*_matrix)[addInput.r1 - 1]);

    for (auto it = rowCopy.begin(); it != rowCopy.end(); ++it) {
        (*((*_matrix)[addInput.r2 - 1]))[i] += *it * addInput.factor;
        i ++;
    }
}

t_mul LGS::getMulInput() {
    std::string input;
    t_mul mulInput;

    std::cout << "Enter: <row> <factor>: ";
    std::getline(std::cin, input);

    std::istringstream stream(input);

    if (!(stream >> mulInput.r >> mulInput.factor) ||
        mulInput.r < 1 || mulInput.r > _rows) {
        std::cout << "Invalid input\n";
        return getMulInput();
    }

    return mulInput;
}
t_add LGS::getAddInput() {
    std::string input;
    t_add addInput;

    std::cout << "Enter: <row1> <row2> <factor>: ";
    std::getline(std::cin, input);

    std::istringstream stream(input);

    if (!(stream >> addInput.r1 >> addInput.r2 >> addInput.factor) ||
        addInput.r1 < 1 || addInput.r1 > _rows ||
        addInput.r2 < 1 || addInput.r2 > _rows) {
        std::cout << "Invalid input\n";
        return getAddInput();
    }

    return addInput;
}

std::ostream& operator<<(std::ostream & os, LGS & obj) {
    int x = 0;

    for (std::vector<std::vector<double> *>::iterator it = obj._matrix->begin(); it != obj._matrix->end(); ++it) {
        const auto& row = *(*it);
        if (x == 0) {
            os << "/";
        } else if (x == obj._rows - 1) {
            os << "\\";
        } else {
            os << "|";
        }
        for (int i = 0; i < obj._cols; ++i) {
            os << std::setw(3)  << row[i];
            if (obj._cols > 1 && i == obj._cols - 2) {
                os << " |";
            }
            else if (i != obj._cols - 1) {
                os << " ";
            }
        }
        if (x == 0) {
            os << "\\";
        } else if(x == obj._rows - 1) {
            os << "/";
        } else {
            os << "|";
        }
        os << "\n";
        x ++;
    }
    return os;
}
