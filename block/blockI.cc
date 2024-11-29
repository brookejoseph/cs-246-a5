#include <vector>
#include <tuple>
#include <iostream>
#include <ostream>
#include "block.h"
#include "blockI.h"

using namespace std;

IBlock::IBlock(std::shared_ptr<Board> cell,
               pair<int, int> a,
               pair<int, int> b,
               pair<int, int> c,
               pair<int, int> d) : Block(cell, a, b, c, d) {};

// IBlock::IBlock() : Block(nullptr, {0, 3}, {1, 3}, {2, 3}, {3, 3}) {}

IBlock::IBlock() : Block(nullptr, {0, 3}, {1, 3}, {2, 3}, {3, 3}) {}

IBlock::IBlock(std::shared_ptr<Board> cell) : Block(cell, {0, 3}, {1, 3}, {2, 3}, {3, 3}) {}

char IBlock::getChar(int x, int y) const
{
    if (((x == a.first) && (y == a.second)) || ((x == b.first) && (y == b.second)) || ((x == c.first) && (y == c.second)) || ((x == d.first) && (y == d.second))) // Fixed parentheses
    {
        return 'I';
    }
    else
    {
        return cells->getChar(x, y);
    }
}

char IBlock::getType() const
{
    return 'I';
}
