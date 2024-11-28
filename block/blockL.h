#ifndef BLOCKL_H
#define BLOCKL_H
#include <vector>
#include <tuple>
#include <iostream>
#include <ostream>
#include "block.h"

using namespace std;

class LBlock : public Block
{
public:
    LBlock(std::shared_ptr<Board> cells,
           pair<int, int> a,
           pair<int, int> b,
           pair<int, int> c,
           pair<int, int> d); // to change
    LBlock();
    LBlock(std::shared_ptr<Board> cells);
    ~LBlock() override = default;

    virtual char getChar(int x, int y) const override;
    virtual char getType() const override;
    // void drop() override;
};

#endif