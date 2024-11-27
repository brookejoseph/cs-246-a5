#include <vector>
#include <tuple>
#include <iostream>
#include <ostream>
#include "block.h"
#include "../cell/cell.h"
#include "blockI.h"

using namespace std;

vector<pair<int, int>> IBlock::getCoord()
{
    return {a, b, c, d};
};

IBlock::IBlock(Board *cell,
               pair<int, int> a,
               pair<int, int> b,
               pair<int, int> c,
               pair<int, int> d) : Block(cell), a{a}, b{b}, c{c}, d{d} {};

IBlock::IBlock() : Block(nullptr),
                   a{0, 3}, b{1, 3}, c{2, 3}, d{3, 3} {};

char IBlock::getChar(int x, int y)
{
    if (((x == a.first) && (y == a.second)) || ((x == b.first) && (y == b.second)) || ((x == c.first) && (y == c.second)) || ((x == d.first) && (y == d.second))) // Fixed parentheses
    {
        return 'I';
    }
    else
    {
        return cell->getValue(x, y);
    };
};

char IBlock::getType()
{
    return 'I';
};

void IBlock::left()
{
    --a.first;
    --b.first;
    --c.first;
    --d.first;
};

void IBlock::right()
{
    ++a.first;
    ++b.first;
    ++c.first;
    ++d.first;
};

void IBlock::down()
{
    ++a.second;
    ++b.second;
    ++c.second;
    ++d.second;
};

void IBlock::rotateccw()
{
    int old_min_x = min({a.first, b.first, c.first, d.first});
    int old_max_y = max({a.second, b.second, c.second, d.second});

    // (x, y) --> (y, -x)
    int temp_a_x = a.second, temp_a_y = -a.first;
    int temp_b_x = b.second, temp_b_y = -b.first;
    int temp_c_x = c.second, temp_c_y = -c.first;
    int temp_d_x = d.second, temp_d_y = -d.first;

    a.first = temp_a_x;
    a.second = temp_a_y;
    b.first = temp_b_x;
    b.second = temp_b_y;
    c.first = temp_c_x;
    c.second = temp_c_y;
    d.first = temp_d_x;
    d.second = temp_d_y;

    int new_min_x = min({a.first, b.first, c.first, d.first});
    int new_max_y = max({a.second, b.second, c.second, d.second});

    // x = x - |(new_min_x - old_min_x)|
    // y = y + |(new_max_y - old_max_y)|
    int shift_x = abs(new_min_x - old_min_x);
    int shift_y = abs(new_max_y - old_max_y);

    a.first -= shift_x;
    a.second += shift_y;
    b.first -= shift_x;
    b.second += shift_y;
    c.first -= shift_x;
    c.second += shift_y;
    d.first -= shift_x;
    d.second += shift_y;
}

void IBlock::rotatecw()
{
    this->rotateccw();
    this->rotateccw();
    this->rotateccw();
}