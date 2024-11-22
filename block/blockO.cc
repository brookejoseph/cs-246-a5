
#include <vector>
#include <tuple>
#include <iostream>
#include <ostream>
#include "cell/cell.h" // to add
#include "block.h"
#include "blockO.h"

using namespace std;

OBlock::OBlock(Board *cell,
               pair<int, int> a,
               pair<int, int> b,
               pair<int, int> c,
               pair<int, int> d) : Block(cell), a{a}, b{b}, c{c}, d{d} {};

char OBlock::getChar(int x, int y)
{
    if (((x == a.first) && (y == a.second)) || ((x == b.first) && (y == b.second)) || ((x == c.first) && (y == c.second)) || ((x == d.first) && (y == d.second))) // Fixed parentheses
    {
        return 'O';
    }
    else
    {
        return cell->getChar(x, y);
    };
};

char OBlock::getType()
{
    return 'O';
};

void OBlock::left()
{
    --a.first;
    --b.first;
    --c.first;
    --d.first;
};

void OBlock::right()
{
    ++a.first;
    ++b.first;
    ++c.first;
    ++d.first;
};

void OBlock::down()
{
    ++a.second;
    ++b.second;
    ++c.second;
    ++d.second;
};