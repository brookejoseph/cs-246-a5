#include <vector>
#include <tuple>
#include <iostream>
#include <ostream>
#include "cell/cell.h" // to add
//#include "block.h"
#include "blockI.h"

using namespace std;

IBlock::IBlock(
    vector<tuple<pair<int, int>>> a,
    vector<tuple<pair<int, int>>> b,
    vector<tuple<pair<int, int>>> c,
    vector<tuple<pair<int, int>>> d)
    : cells{{make_pair(0, 0), make_pair(1, 0), make_pair(2, 0), make_pair(2, 1)}} {};

char IBlock::getChar()
{
    return 'I';
};


void IBlock::rotateccw()
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
            const auto &[x, y] = i == 0 ? get<0>(t) :
                                i == 1 ? get<1>(t) :
                                i == 2 ? get<2>(t) : get<3>(t);

            int new_x = y;
            int new_y = -x;

            if (i == 0) get<0>(transformed_tuple) = {new_x, new_y};
            if (i == 1) get<1>(transformed_tuple) = {new_x, new_y};
            if (i == 2) get<2>(transformed_tuple) = {new_x, new_y};
            if (i == 3) get<3>(transformed_tuple) = {new_x, new_y};
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

    //x = x - |(new_min_x - old_min_x)|
    //y = y + |(new_max_y - old_max_y)|
    for (auto &t : transformed_cells)
    {
        for (int i = 0; i < 4; ++i)
        {
            auto &[x, y] = i == 0 ? get<0>(t) :
                          i == 1 ? get<1>(t) :
                          i == 2 ? get<2>(t) : get<3>(t);
            x = x - abs(new_min_x - old_min_x);
            y = y + abs(new_max_y - old_max_y);
        }
    }
    this->cells = transformed_cells;
}

void IBlock::rotatecw() {
    this->rotateccw();
    this->rotateccw();
    this->rotateccw();
}