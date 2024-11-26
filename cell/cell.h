#ifndef CELL_H // Add this line
#define CELL_H // Add this line

#include <vector>
#include <tuple>
#include <iostream>
#include <ostream>
#include <memory>

using namespace std;

class Cell : public Board
{
private:
    std::vector<std::vector<char>> plainGrid;

public:
    virtual char charAt(int x, int y);
    virtual ~Cell() = default;
    Cell(int row, int col);
    virtual void setValue(char newValue, int x, int y);
    virtual char getValue(int x, int y);

    void setDimX(int x) override;
    void setDimY(int y) override;
};

#endif