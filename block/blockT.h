#ifndef BLOCKT_H
#define BLOCKT_H
// the main block interface file
#include <vector>
#include <tuple>
#include <iostream>
#include <ostream>
#include "block.h"

class TBlock : public Block
{
public:
    TBlock(Board *cell,
           pair<int, int> a,
           pair<int, int> b,
           pair<int, int> c,
           pair<int, int> d); // to change
    TBlock();
    TBlock(Board *cell);
    ~TBlock() override = default;

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