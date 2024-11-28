
#ifndef BLOCKZ_H
#define BLOCKZ_H
// the main block interface file
#include <vector>
#include <tuple>
#include <iostream>
#include <ostream>
#include "block.h"

class ZBlock : public Block {
public:
    ZBlock(Board *cell,
           pair<int, int> a,
           pair<int, int> b,
           pair<int, int> c,
           pair<int, int> d);

    ZBlock();
    ZBlock(Board *cell);
    ~ZBlock() override = default;

    void rotateccw() override;
    void rotatecw() override;
    char getValue(int x, int y) override;
    char getType() override;
    void left() override;
    void right() override;
    void down() override;
    // void drop() override;
};

#endif