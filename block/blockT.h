#ifndef BLOCKT_H
#define BLOCKT_H
// the main block interface file
#include <vector>
#include <tuple>
#include <iostream>
#include <ostream>
#include "block.h"

using namespace std;

class TBlock : public Block
{
public:
    TBlock(std::shared_ptr<Board> cells,
           pair<int, int> a,
           pair<int, int> b,
           pair<int, int> c,
           pair<int, int> d); // to change
    TBlock();
    TBlock(std::shared_ptr<Board> cells);
    ~TBlock() override = default;

    virtual char getChar(int x, int y) const override;
    virtual char getType() const override;
    // void drop() override;
};
#endif
