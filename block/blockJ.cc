
#include <vector>
#include <tuple>
#include <iostream>
#include <ostream>
#include "block.h"
#include "blockJ.h"
// #include "board/board.h"

using namespace std;

JBlock::JBlock(std::shared_ptr<Board> cells,
               pair<int, int> a,
               pair<int, int> b,
               pair<int, int> c,
               pair<int, int> d) : Block(cells, a, b, c, d) {}

// JBlock::JBlock() : Block(nullptr, {0, 4}, {1, 4}, {1, 3}, {1, 2}) {}
JBlock::JBlock() : Block(nullptr, {0, 3}, {0, 4}, {1, 4}, {2, 4}) {}

JBlock::JBlock(std::shared_ptr<Board> cells) : Block(cells, {0, 3}, {0, 4}, {1, 3}, {2, 3}) {}

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
