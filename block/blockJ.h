#ifndef BLOCKJ_H
#define BLOCKJ_H

// the main block interface file
#include <vector>
#include <tuple>
#include <iostream>
#include <ostream>
#include "block.h"

using namespace std;

class JBlock : public Block
{
public:
    JBlock(std::shared_ptr<Board> cells,
           pair<int, int> a,
           pair<int, int> b,
           pair<int, int> c,
           pair<int, int> d); // to change

    JBlock();
    JBlock(std::shared_ptr<Board> cells);
    ~JBlock() override = default;

    virtual char getChar(int x, int y) const override;
    virtual char getType() const override;
    // void drop() override;
};
#endif
