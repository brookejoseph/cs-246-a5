#include <vector>
#include <tuple>
#include <iostream>
#include <ostream>
#include "../board/board.h"
#include "../cell/cell.h"

Cell::Cell(int row, int col) : Board()
{
    dimX = row;
    dimY = col;
    plainGrid = std::vector<std::vector<char>>(row, std::vector<char>(col, ' '));
};

Cell::~Cell() = default;

char Cell::charAt(int x, int y)
{
    return plainGrid.at(x).at(y);
}

void Cell::setValue(char newValue, int x, int y)
{
    plainGrid.at(x).at(y) = newValue;
}

char Cell::getValue(int x, int y)
{
    return plainGrid.at(x).at(y);
};

void Cell::setDimX(int x)
{
    dimX = x;
};

void Cell::setDimY(int y)
{
    dimY = y;
};