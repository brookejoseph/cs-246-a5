#ifndef CELL_H // Add this line
#define CELL_H // Add this line

#include <vector>
#include <tuple>
#include <iostream>
#include <ostream>
#include <memory>
#include "../board/board.h"

using namespace std;

class Cell : public Board
{
private:
    std::vector<std::vector<char>> plainGrid;

public:
    char charAt(int x, int y);
    ~Cell();
    Cell(int row, int col);
    void setValue(char newValue, int x, int y);
    char getValue(int x, int y) override;

    void setDimX(int x) override;
    void setDimY(int y) override;
};

#endif