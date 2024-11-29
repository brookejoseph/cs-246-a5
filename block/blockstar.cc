#include <vector>
#include <tuple>
#include <iostream>
#include <ostream>
#include "blockstar.h"

using namespace std;
BlockStar::BlockStar(std::shared_ptr<Board> cells,
                     pair<int, int> a,
                     pair<int, int> b,
                     pair<int, int> c,
                     pair<int, int> d) : Block(cells, a, b, c, d) {}

BlockStar::BlockStar(int midpoint)
    : Block(nullptr, {midpoint, 0}, {midpoint, 0}, {midpoint, 0}, {midpoint, 0}) {}

// JBlock::JBlock() : Block(nullptr, {0, 4}, {1, 4}, {1, 3}, {1, 2}) {}
BlockStar::BlockStar() : Block(nullptr, {0, 0}, {0, 0}, {0, 0}, {0, 0}) {}

BlockStar::BlockStar(std::shared_ptr<Board> cells) : Block(cells, {0, 0}, {0, 0}, {0, 0}, {0, 0}) {}

char BlockStar::getChar(int x, int y) const
{
    if (((x == a.first) && (y == a.second)) || ((x == b.first) && (y == b.second)) || ((x == c.first) && (y == c.second)) || ((x == d.first) && (y == d.second))) // Fixed parentheses
    {
        return '*';
    }
    else
    {
        return cells->getChar(x, y);
    }
}

char BlockStar::getType() const
{
    return '*';
}
