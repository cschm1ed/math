

#ifndef LGS_H
#define LGS_H

#include <iostream>
#include <vector>
#include "ParsingUtils.h"

typedef struct s_add {
    int r1;
    int r2;
    double factor;
} t_add;

typedef struct s_mul {
    int r;
    double factor;
} t_mul;

class LGS {
public:
    LGS();
    ~LGS();

    std::vector<std::vector<double> *> *_matrix;
    void add();
    void multiply();

    int _rows;
    int _cols;
private:
    void getDimensions();
    t_add getAddInput();
    t_mul getMulInput();

};

std::ostream& operator<<(std::ostream & os, LGS & obj);

#endif //UNTITLED_LGS_H
