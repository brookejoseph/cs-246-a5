#include <vector>
#include <tuple>
#include <iostream>
#include <ostream>
#include "block.h"
#include "blockL.h"
// #include "board/board.h"

using namespace std;

LBlock::LBlock(std::shared_ptr<Board> cells,
               pair<int, int> a,
               pair<int, int> b,
               pair<int, int> c,
               pair<int, int> d) : Block(cells, a, b, c, d) {}

// LBlock::LBlock() : Block(nullptr, {1, 4}, {1, 3}, {1, 2}, {2, 2}) {}

LBlock::LBlock() : Block(nullptr, {0, 4}, {1, 4}, {2, 4}, {2, 3}) {}

LBlock::LBlock(std::shared_ptr<Board> cells) : Block(cells, {0, 4}, {1, 4}, {2, 4}, {2, 3}) {}

char LBlock::getChar(int x, int y) const
{
    if (((x == a.first) && (y == a.second)) || ((x == b.first) && (y == b.second)) || ((x == c.first) && (y == c.second)) || ((x == d.first) && (y == d.second))) // Fixed parentheses
    {
        return 'L';
    }
    else
    {
        return cells->getChar(x, y);
    };
};

char LBlock::getType() const
{
    return 'L';
}
