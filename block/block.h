#ifndef BLOCK_H
#define BLOCK_H

#include <vector>
#include <tuple>
#include <iostream>
#include <ostream>
#include "../board/board.h"
// #include "cell/cell.h" // to add

using namespace std;

class Block : public Board
{
protected:
    Board *cells;
    int levelCreated;

public:
    virtual int getLevel() = 0;
    virtual void setLevel(int val) = 0;
    explicit Block(Board *cells);
    explicit Block();
    virtual ~Block();

    // virtual bool getHeavy();
    // virtual void setHeavy();
    virtual char getChar(int x, int y) = 0;
    virtual char getType() = 0;

    // void heavy();
    void virtual rotateccw() = 0;
    void virtual rotatecw() = 0;
    virtual void left() = 0;
    virtual void right() = 0;
    virtual void down() = 0;
    // virtual void drop();
    virtual vector<pair<int, int>> getCoord() = 0;
};

#endif
