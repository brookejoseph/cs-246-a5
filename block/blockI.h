#ifndef BLOCKI_H
#define BLOCKI_H
// the main block interface file
#include <vector>
#include <tuple>
#include <iostream>
#include <ostream>
#include "cell/cell.h" // to add
#include "block.h"

using namespace std;

class IBlock : public Block
{
private:
    Board *cell;
    pair<int, int> a;
    pair<int, int> b;
    pair<int, int> c;
    pair<int, int> d;

public:
    IBlock(pair<int, int> a,
           pair<int, int> b,
           pair<int, int> c,
           pair<int, int> d) : Block(cell), a{make_pair(0, 0)}, b{make_pair(1, 0)}, c{make_pair(2, 0)}, d{make_pair(0, 1)} {}; // to change
    void rotateccw() override;
    void rotatecw() override;
    char getChar(int x, int y) override;
    char getType() override;
};

#endif