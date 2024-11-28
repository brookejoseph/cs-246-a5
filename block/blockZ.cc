
#include <vector>
#include <tuple>
#include <iostream>
#include <ostream>
#include "block.h"
#include "blockZ.h"

// #include "../board/board.h"

using namespace std;

ZBlock::ZBlock(Board *cell,
               pair<int, int> a,
               pair<int, int> b,
               pair<int, int> c,
               pair<int, int> d) : Block(cell, a, b, c, d) {}

ZBlock::ZBlock() : Block(nullptr, {0, 3}, {1, 3}, {1, 4}, {2, 4}) {}

ZBlock::ZBlock(Board *cell) : Block(cell, {0, 3}, {1, 3}, {1, 4}, {2, 4}) {}

char ZBlock::getChar(int x, int y) const
{
    if (((x == a.first) && (y == a.second)) || ((x == b.first) && (y == b.second)) || ((x == c.first) && (y == c.second)) || ((x == d.first) && (y == d.second))) // Fixed parentheses
    {
        return 'Z';
    }
    else
    {
        return cells->getValue(x, y);
    };
};

char ZBlock::getType() const
{
    return 'Z';
}

