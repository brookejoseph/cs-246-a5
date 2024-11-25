#include <vector>
#include <tuple>
#include <iostream>
#include <ostream>

using namespace std;

class Cell : public Board
{
private:
    std::vector<std::vector<char>> plainGrid;

public:
    virtual char charAt(int x, int y) = 0;
    virtual ~Cell();
    Cell(int row, int col);
    void setValue(char newValue, int x, int y);
    char getValue(int x, int y);

    void setDimX(int x) override {};
    void setDimY(int y) override {};
};