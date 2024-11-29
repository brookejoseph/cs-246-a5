#ifndef BLOCKI_H
#define BLOCKI_H
// the main block interface file
#include <vector>
#include <tuple>
#include <iostream>
#include <ostream>
#include "block.h"
#include <memory>

using namespace std;

class IBlock : public Block
{
public:
    IBlock(std::shared_ptr<Board> cells,
           pair<int, int> a,
           pair<int, int> b,
           pair<int, int> c,
           pair<int, int> d); // to change
    IBlock();
    IBlock(std::shared_ptr<Board> cells);
    ~IBlock() override = default;

    virtual char getChar(int x, int y) const override;
    virtual char getType() const override;
    // void drop() override;
};

#endif
