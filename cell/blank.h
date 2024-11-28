#ifndef BLANK_H
#define BLANK_H
#include "cell.h"

class Blank: public Cell {
    virtual char getValue(int x, int y) override;
};

#endif
