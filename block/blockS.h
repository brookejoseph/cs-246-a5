#ifndef BLOCKS_H
#define BLOCKS_H

// the main block interface file
#include <vector>
#include <tuple>
#include <iostream>
#include <ostream>
#include "block.h"

using namespace std;

class SBlock : public Block
{
public:
    SBlock(std::shared_ptr<Board> cells,
           pair<int, int> a,
           pair<int, int> b,
           pair<int, int> c,
           pair<int, int> d); // to change
    SBlock();
    SBlock(std::shared_ptr<Board> cells);
    ~SBlock() override = default;

    virtual char getChar(int x, int y) const override;
    virtual char getType() const override;
    // void drop() override;
};

#endif