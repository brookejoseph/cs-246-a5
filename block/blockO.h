#ifndef BLOCKO_H
#define BLOCKO_H

// the main block interface file
#include <vector>
#include <tuple>
#include <iostream>
#include <ostream>
#include "block.h"

using namespace std;

class OBlock : public Block
{
public:
    OBlock(std::shared_ptr<Board> cells,
           pair<int, int> a,
           pair<int, int> b,
           pair<int, int> c,
           pair<int, int> d); // to change
    OBlock();
    OBlock(std::shared_ptr<Board> cells);
    ~OBlock() override = default;

    virtual char getChar(int x, int y) const override;
    virtual char getType() const override;
    // void drop() override;
};

#endif