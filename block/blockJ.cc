
#include <vector>
#include <tuple>
#include <iostream>
#include <ostream>
#include "cell/cell.h" // to add
#include "block.h"
#include "blockJ.h"
#include "cell/cell.h"
#include "board/board.h"

using namespace std;

JBlock::JBlock(Board *cell,
               pair<int, int> a,
               pair<int, int> b,
               pair<int, int> c,
               pair<int, int> d) : Block(cell), a{a}, b{b}, c{c}, d{d} {};

char JBlock::getChar(int x, int y)
{
    if (((x == a.first) && (y == a.second)) || ((x == b.first) && (y == b.second)) || ((x == c.first) && (y == c.second)) || ((x == d.first) && (y == d.second))) // Fixed parentheses
    {
        return 'J';
    }
    else
    {
        return cell->getChar(x, y);
    };
};

char JBlock::getType()
{
    return 'J';
};

void JBlock::left()
{
    --a.first;
    --b.first;
    --c.first;
    --d.first;
};

void JBlock::right()
{
    ++a.first;
    ++b.first;
    ++c.first;
    ++d.first;
};

void JBlock::down()
{
    ++a.second;
    ++b.second;
    ++c.second;
    ++d.second;
};