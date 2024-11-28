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
private:

public:
    JBlock(std::shared_ptr<Board> cells,
           pair<int, int> a,
           pair<int, int> b,
           pair<int, int> c,
           pair<int, int> d); // to change

    JBlock();
    JBlock(std::shared_ptr<Board> cells);
    ~JBlock() override = default;

    virtual void rotateccw() override;
    virtual void rotatecw() override;
    virtual char getValue(int x, int y) override;
    virtual char getType() override;
    virtual void left() override;
    virtual void right() override;
    virtual void down() override;
    // void drop() override;
};
#endif