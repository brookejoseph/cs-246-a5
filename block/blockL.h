#ifndef BLOCKL_H
#define BLOCKL_H
#include <vector>
#include <tuple>
#include <iostream>
#include <ostream>
#include "block.h"

class LBlock : public Block {
public:
    LBlock(Board *cell,
           pair<int, int> a,
           pair<int, int> b,
           pair<int, int> c,
           pair<int, int> d); // to change
    LBlock();
    LBlock(Board *cell);
    ~LBlock() override = default;

    virtual void rotateccw() override;
    virtual void rotatecw() override;
    virtual char getValue(int x, int y) override;
    virtual char getType() override;
    virtual void left() override;
    virtual void right() override;
    virtual void down() override;
    // void drop() override;
};

#endif