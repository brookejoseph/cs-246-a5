
#include <vector>
#include <tuple>
#include <iostream>
#include <ostream>
#include "block.h"
#include "blockO.h"

using namespace std;

OBlock::OBlock(std::shared_ptr<Board> cells,
               pair<int, int> a,
               pair<int, int> b,
               pair<int, int> c,
               pair<int, int> d) : Block(cells, a, b, c, d) {}

OBlock::OBlock() : Block(nullptr, {0, 3}, {1, 3}, {0, 4}, {1, 4}) {}

OBlock::OBlock(std::shared_ptr<Board> cells) : Block(cells, {0, 3}, {1, 3}, {0, 4}, {1, 4}) {}

char OBlock::getChar(int x, int y) const
{
    if (((x == a.first) && (y == a.second)) || ((x == b.first) && (y == b.second)) || ((x == c.first) && (y == c.second)) || ((x == d.first) && (y == d.second))) // Fixed parentheses
    {
        return 'O';
    }
    else
    {
        return cells->getChar(x, y);
    }
}

char OBlock::getType() const
{
    return 'O';
}
