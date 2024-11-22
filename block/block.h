#include <vector>
#include <tuple>
#include <iostream>
#include <ostream>
#include "board.h"
// #include "cell/cell.h" // to add

using namespace std;

class Block:public Board
{
    protected:
    Board *board;

public:
Block(Board *cells): board{cells} {};
    virtual ~Block() {};

    bool getHeavy();
    void setHeavy();
    virtual char getChar(int x, int y) = 0;
    

    void heavy();
    void virtual rotateccw() = 0;
    void virtual rotatecw() = 0;
    void left();
    void right();
    void down();
    void drop();

    vector<tuple<pair<int, int>, pair<int, int>, pair<int, int>, pair<int, int>>> getCoord();
};