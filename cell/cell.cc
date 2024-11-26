#include <vector>
#include <tuple>
#include <iostream>
#include <ostream>
#include "../board/board.h"
#include "../cell/cell.h"

using namespace std;
Cell::Cell(int row, int col) : Board(row, col), plainGrid(row, vector<char>(col, ' ')) {};

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