
#include <vector>
#include <tuple>
#include <iostream>
#include <ostream>
#include "block.h"
#include "../block/blockS.h"
// #include "../board/board.h"

using namespace std;

SBlock::SBlock(std::shared_ptr<Board> cells,
               pair<int, int> a,
               pair<int, int> b,
               pair<int, int> c,
               pair<int, int> d) : Block(cells, a, b, c, d) {}

SBlock::SBlock() : Block(nullptr, {1, 3}, {2, 3}, {0, 4}, {1, 4}) {}

SBlock::SBlock(std::shared_ptr<Board> cells) : Block(cells, {1, 3}, {2, 3}, {0, 4}, {1, 4}) {}

char SBlock::getChar(int x, int y) const
{
    if (((x == a.first) && (y == a.second)) || ((x == b.first) && (y == b.second)) || ((x == c.first) && (y == c.second)) || ((x == d.first) && (y == d.second))) // Fixed parentheses
    {
        return 'S';
    }
    else
    {
        return cells->getChar(x, y);
    };
};

char SBlock::getType() const
{
    return 'S';
}
