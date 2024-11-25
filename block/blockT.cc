
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


void TBlock::rotateccw()
{
    int old_min_x = 0, old_max_y = 0;
    for (const auto &t : this->cells)
    {
        for (const auto &[x, y] : {get<0>(t), get<1>(t), get<2>(t), get<3>(t)})
        {
            old_min_x = min(old_min_x, x);
            old_max_y = max(old_max_y, y);
        }
    }
    // (x, y) --> (y, -x)
    vector<tuple<pair<int, int>, pair<int, int>, pair<int, int>, pair<int, int>>> transformed_cells;
    for (auto &t : this->cells)
    {
        tuple<pair<int, int>, pair<int, int>, pair<int, int>, pair<int, int>> transformed_tuple;

        for (int i = 0; i < 4; ++i)
        {
            const auto &[x, y] = i == 0 ? get<0>(t) : i == 1 ? get<1>(t)
                                                  : i == 2   ? get<2>(t)
                                                             : get<3>(t);

            int new_x = y;
            int new_y = -x;

            if (i == 0)
                get<0>(transformed_tuple) = {new_x, new_y};
            if (i == 1)
                get<1>(transformed_tuple) = {new_x, new_y};
            if (i == 2)
                get<2>(transformed_tuple) = {new_x, new_y};
            if (i == 3)
                get<3>(transformed_tuple) = {new_x, new_y};
        }

        transformed_cells.push_back(transformed_tuple);
    }

    int new_min_x = 0, new_max_y = 0;
    for (const auto &t : transformed_cells)
    {
        for (const auto &[x, y] : {get<0>(t), get<1>(t), get<2>(t), get<3>(t)})
        {
            new_min_x = min(new_min_x, x);
            new_max_y = max(new_max_y, y);
        }
    }

    // x = x - |(new_min_x - old_min_x)|
    // y = y + |(new_max_y - old_max_y)|
    for (auto &t : transformed_cells)
    {
        for (int i = 0; i < 4; ++i)
        {
            auto &[x, y] = i == 0 ? get<0>(t) : i == 1 ? get<1>(t)
                                            : i == 2   ? get<2>(t)
                                                       : get<3>(t);
            x = x - abs(new_min_x - old_min_x);
            y = y + abs(new_max_y - old_max_y);
        }
    }
    this->cells = transformed_cells;
}

void TBlock::rotatecw()
{
    this->rotateccw();
    this->rotateccw();
    this->rotateccw();
}

