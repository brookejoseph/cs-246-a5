#ifndef BLOCK_H
#define BLOCK_H

#include <vector>
#include <tuple>
#include <iostream>
#include <ostream>
#include "../board/board.h"
// #include "cell/cell.h" // to add

class Block : public Cell
{
protected:
    std::shared_ptr<Board> cells;

    std::pair<int, int> a;
    std::pair<int, int> b;
    std::pair<int, int> c;
    std::pair<int, int> d;

    int levelCreated;

public:
    Block(std::shared_ptr<Board> cells,
          std::pair<int, int> a,
          std::pair<int, int> b,
          std::pair<int, int> c,
          std::pair<int, int> d);
    Block() = default;
    virtual ~Block() = 0;

    int getLevel() const;
    void setLevel(int val);

    // virtual bool getHeavy();
    // virtual void setHeavy();
    virtual std::vector<std::pair<int, int>> getCoord();
    virtual char getValue(int x, int y) override = 0;
    virtual char getType() = 0;

    // void heavy();
    virtual void rotateccw() = 0;
    virtual void rotatecw() = 0;
    virtual void left() = 0;
    virtual void right() = 0;
    virtual void down() = 0;
    // virtual void drop();
};

#endif
