
#include <vector>
#include <tuple>
#include <iostream>
#include <ostream>
#include "block.h"
#include "blockJ.h"
// #include "board/board.h"

using namespace std;

JBlock::JBlock(Board *cell,
               pair<int, int> a,
               pair<int, int> b,
               pair<int, int> c,
               pair<int, int> d) : Block(cell, a, b, c, d) {}

JBlock::JBlock() : Block(nullptr, {0, 4}, {1, 4}, {1, 3}, {1, 2}) {}

JBlock::JBlock(Board *cell) : Block(cell, {0, 4}, {1, 4}, {1, 3}, {1, 2}) {}

char JBlock::getChar(int x, int y) const
{
    if (((x == a.first) && (y == a.second)) || ((x == b.first) && (y == b.second)) || ((x == c.first) && (y == c.second)) || ((x == d.first) && (y == d.second))) // Fixed parentheses
    {
        return 'J';
    }
    else
    {
        return cells->getChar(x, y);
    }
}

char JBlock::getType() const
{
    return 'J';
}
