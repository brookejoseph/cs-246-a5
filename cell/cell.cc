#include <vector>
#include <tuple>
#include <iostream>
#include <ostream>
#include "cell.h"
#include "board/board.h"

class Cell : public Board
{
private:
    std::vector<std::vector<char>> plainGrid;

public:
    virtual char charAt(int x, int y)
    {
        return plainGrid.at(x).at(y);
    }

    Cell(int row, int col) : Board()
    {
        plainGrid = vector<std::vector<char>>(row, vector<char>(col, ' '));
    };

    void setValue(char newValue, int x, int y)
    {
        plainGrid.at(x).at(y) = newValue;
    }

    char getValue(int x, int y) const
    {
        return plainGrid.at(x).at(y);
    };

    void setDimX(int x)
    {
        dimX = x;
    };

    void setDimY(int y)
    {
        dimY = y;
    };
};