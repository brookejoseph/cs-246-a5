#include <vector>
#include <tuple>
#include <iostream>
#include <ostream>
#include "../board/board.h"
#include "cell.h"
char Cell::charAt(int x, int y) // Ensure to use override
{
    return plainGrid.at(x).at(y);
}

// Implement any other pure virtual functions from Board here
// {{ edit_1 }} // Example: virtual void someFunction() override { /* implementation */ }

Cell::Cell(int row, int col) : Board()
{
    plainGrid = std::vector<std::vector<char>>(row, std::vector<char>(col, ' '));
};

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