#ifndef BLOCKI_H
#define BLOCKI_H
// the main block interface file
#include <vector>
#include <tuple>
#include <iostream>
#include <ostream>
#include "block.h"

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

    virtual void rotateccw() override;
    virtual void rotatecw() override;
    virtual char getValue(int x, int y) override;
    virtual char getType() override;
    virtual void left() override;
    virtual void right() override;
    virtual void down() override;
    // void drop() override;
    vector<pair<int, int>> getCoord() override;
};

#endif