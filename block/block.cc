#include <vector>
#include <tuple>
#include <iostream>
#include <ostream>
#include "../block/block.h"
#include "../board/board.h"

using namespace std;

// Block::Block(Board *cells) : Board(dimX, dimY), cells{cells} {};
Block::Block(Board *cells,
            pair<int, int> a,
            pair<int, int> b,
            pair<int, int> c,
            pair<int, int> d) : Board(11, 18), cells(cells), a{a}, b{b}, c{c}, d{d} {}

Block::Block(Board *cells): Board(11, 18), cells(cells) {}

// Block::~Block() { delete cells; };

Block::~Block() {}

int Block::getLevel() const { return levelCreated; }

void Block::setLevel(int lvl) { levelCreated = lvl; }

vector<pair<int, int>> Block::getCoord() const { return {a, b, c, d}; }

void Block::left()
{
    --a.first;
    --b.first;
    --c.first;
    --d.first;
    if (getLevel() >= 3) {
        down();
    }
}

void Block::right()
{
    ++a.first;
    ++b.first;
    ++c.first;
    ++d.first;
    //cout << "get level: " << getLevel() << endl;
    if (getLevel() >= 3) {
        down();
    }
}

void Block::down()
{
    ++a.second;
    ++b.second;
    ++c.second;
    ++d.second;
    //cout << "down triggered" << endl;
}

void Block::rotateccw()
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
    if (getLevel() >= 3) {
        down();
    }
}

void Block::rotatecw()
{
    this->rotateccw();
    this->rotateccw();
    this->rotateccw();
    if (getLevel() >= 3) {
        down();
    }
}
