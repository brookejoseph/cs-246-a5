
#include <vector>
#include <tuple>
#include <iostream>
#include <ostream>
#include "block.h"
#include "blockT.h"

using namespace std;

TBlock::TBlock(Board *cell,
               pair<int, int> a,
               pair<int, int> b,
               pair<int, int> c,
               pair<int, int> d) : Block(cell, a, b, c, d) {}

TBlock::TBlock() : Block(nullptr, {1, 4}, {0, 4}, {2, 4}, {1, 3}) {}

TBlock::TBlock(Board *cell) : Block(cell, {1, 4}, {0, 4}, {2, 4}, {1, 3}) {}

char TBlock::getChar(int x, int y) const
{
    if (((x == a.first) && (y == a.second)) || ((x == b.first) && (y == b.second)) || ((x == c.first) && (y == c.second)) || ((x == d.first) && (y == d.second))) // Fixed parentheses
    {
        return 'T';
    }
    else
    {
        return cells->getValue(x, y);
    };
};

char TBlock::getType() const
{
    return 'T';
}
