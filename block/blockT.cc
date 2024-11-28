
#include <vector>
#include <tuple>
#include <iostream>
#include <ostream>
#include "block.h"
#include "blockT.h"

using namespace std;

TBlock::TBlock(std::shared_ptr<Board> cells,
               pair<int, int> a,
               pair<int, int> b,
               pair<int, int> c,
               pair<int, int> d) : Block(cells, a, b, c, d) {}

TBlock::TBlock() : Block(nullptr, {1, 4}, {0, 4}, {2, 4}, {1, 3}) {}

TBlock::TBlock(std::shared_ptr<Board> cells) : Block(cells, {1, 4}, {0, 4}, {2, 4}, {1, 3}) {}

char TBlock::getChar(int x, int y) const
{
    if (((x == a.first) && (y == a.second)) || ((x == b.first) && (y == b.second)) || ((x == c.first) && (y == c.second)) || ((x == d.first) && (y == d.second))) // Fixed parentheses
    {
        return 'T';
    }
    else
    {
        return cells->getChar(x, y);
    };
};

char TBlock::getType() const
{
    return 'T';
}
