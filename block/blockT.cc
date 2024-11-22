
#include <vector>
#include <tuple>
#include <iostream>
#include <ostream>
#include "cell/cell.h" // to add
#include "block.h"
#include "blockT.h"
#include "cell/cell.h"
#include "board/board.h"

using namespace std;

TBlock::TBlock(Board *cell,
               pair<int, int> a,
               pair<int, int> b,
               pair<int, int> c,
               pair<int, int> d) : Block(cell), a{a}, b{b}, c{c}, d{d} {};

char TBlock::getChar(int x, int y)
{
    if (((x == a.first) && (y == a.second)) || ((x == b.first) && (y == b.second)) || ((x == c.first) && (y == c.second)) || ((x == d.first) && (y == d.second))) // Fixed parentheses
    {
        return 'T';
    }
    else
    {
        return cell->getChar(x, y);
    };
};

char TBlock::getType()
{
    return 'T';
};

void TBlock::left()
{
    --a.first;
    --b.first;
    --c.first;
    --d.first;
};

void TBlock::right()
{
    ++a.first;
    ++b.first;
    ++c.first;
    ++d.first;
};

void TBlock::down()
{
    ++a.second;
    ++b.second;
    ++c.second;
    ++d.second;
};