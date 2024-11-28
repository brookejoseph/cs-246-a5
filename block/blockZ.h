
#ifndef BLOCKZ_H
#define BLOCKZ_H
// the main block interface file
#include <vector>
#include <tuple>
#include <iostream>
#include <ostream>
#include "block.h"

using namespace std;

class ZBlock : public Block
{
public:
    ZBlock(Board *cell,
           pair<int, int> a,
           pair<int, int> b,
           pair<int, int> c,
           pair<int, int> d);

    ZBlock();
    ZBlock(Board *cell);
    ~ZBlock() override = default;

    virtual char getChar(int x, int y) const override;
    virtual char getType() const override;
    // void drop() override;
};

#endif