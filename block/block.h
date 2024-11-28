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

    pair<int, int> a;
    pair<int, int> b;
    pair<int, int> c;
    pair<int, int> d;

    int levelCreated;

public:
    Block(Board *cells,
          pair<int, int> a,
          pair<int, int> b,
          pair<int, int> c,
          pair<int, int> d);
    explicit Block(Board *cells);
    virtual ~Block();

    // virtual bool getHeavy();
    // virtual void setHeavy();
    virtual char getChar(int x, int y) const override = 0;
    virtual char getType() const = 0;
    virtual int getLevel() const;
    virtual void setLevel(int lvl);
    virtual vector<pair<int, int>> getCoord() const;

    // void heavy();
    void rotateccw();
    void rotatecw();
    void left();
    void right();
    void down();
    // virtual void drop();
};

#endif
