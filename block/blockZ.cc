
#include <vector>
#include <tuple>
#include <iostream>
#include <ostream>
#include "cell/cell.h" // to add
#include "block.h"
#include "blockZ.h"
#include "cell/cell.h"
#include "board/board.h"

using namespace std;

ZBlock::ZBlock(Board *cell,
               pair<int, int> a,
               pair<int, int> b,
               pair<int, int> c,
               pair<int, int> d) : Block(cell), a{a}, b{b}, c{c}, d{d} {};

char ZBlock::getChar(int x, int y)
{
    if (((x == a.first) && (y == a.second)) || ((x == b.first) && (y == b.second)) || ((x == c.first) && (y == c.second)) || ((x == d.first) && (y == d.second))) // Fixed parentheses
    {
        return 'Z';
    }
    else
    {
        return cell->getChar(x, y);
    };
};

char ZBlock::getType()
{
    return 'Z';
};

void ZBlock::left()
{
    --a.first;
    --b.first;
    --c.first;
    --d.first;
};

void ZBlock::right()
{
    ++a.first;
    ++b.first;
    ++c.first;
    ++d.first;
};

void ZBlock::down()
{
    ++a.second;
    ++b.second;
    ++c.second;
    ++d.second;
};