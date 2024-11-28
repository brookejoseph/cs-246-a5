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
    if ((a.first > 0) && (b.first > 0) && (c.first > 0) && (d.first > 0) &&
        (getGrid()[a.first - 1][a.second] == ' ') && (getGrid()[b.first - 1][b.second] == ' ') && (getGrid()[c.first - 1][c.second] == ' ') && (getGrid()[d.first - 1][d.second] == ' ')) {
        --a.first;
        --b.first;
        --c.first;
        --d.first;
        if (getLevel() >= 3) {
            down();
        }
    }
}

void Block::right()
{
    if (((a.first < dimX - 1) && (b.first < dimX - 1) && (c.first < dimX - 1) && (d.first < dimX - 1)) &&
        (getGrid()[a.first + 1][a.second] == ' ') && (getGrid()[b.first + 1][b.second] == ' ') && (getGrid()[c.first + 1][c.second] == ' ') && (getGrid()[d.first + 1][d.second] == ' ')) {
        ++a.first;
        ++b.first;
        ++c.first;
        ++d.first;
        if (getLevel() >= 3) {
            down();
        }
    }
}

void Block::down()
{
    // ++a.second;
    // ++b.second;
    // ++c.second;
    // ++d.second;

    if (((a.second < dimY - 1) && (b.second < dimY - 1) && (c.second < dimY - 1) && (d.second < dimY - 1)) &&
        (getGrid()[a.first][a.second + 1] == ' ') && (getGrid()[b.first][b.second + 1] == ' ') && (getGrid()[c.first][c.second + 1] == ' ') && (getGrid()[d.first][d.second + 1] == ' ')) {
        ++a.second;
        ++b.second;
        ++c.second;
        ++d.second;
    }
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

    // a.first = temp_a_x;
    // a.second = temp_a_y;
    // b.first = temp_b_x;
    // b.second = temp_b_y;
    // c.first = temp_c_x;
    // c.second = temp_c_y;
    // d.first = temp_d_x;
    // d.second = temp_d_y;

    int new_min_x = min({a.first, b.first, c.first, d.first});
    int new_max_y = max({a.second, b.second, c.second, d.second});

    // x = x - |(new_min_x - old_min_x)|
    // y = y + |(new_max_y - old_max_y)|
    int shift_x = abs(new_min_x - old_min_x);
    int shift_y = abs(new_max_y - old_max_y);

    temp_a_x -= shift_x;
    temp_a_y += shift_y;
    temp_b_x -= shift_x;
    temp_b_y += shift_y;
    temp_c_x -= shift_x;
    temp_c_y += shift_y;
    temp_d_x -= shift_x;
    temp_d_y += shift_y;

    if (((temp_a_y <= dimY - 1) && (temp_b_y <= dimY - 1) && (temp_c_y <= dimY - 1) && (temp_d_y <= dimY - 1)) &&
        ((temp_a_x >= 0) && (temp_b_x > 0) && (temp_c_x >= 0) && (temp_d_x >= 0)) &&
        (getGrid()[temp_a_x][temp_a_y] == ' ') && (getGrid()[temp_b_x][temp_b_y] == ' ') && (getGrid()[temp_c_x][temp_c_y] == ' ') && (getGrid()[temp_d_x][temp_d_y] == ' ')) {
            a.first = temp_a_x;
            a.second = temp_a_y;
            b.first = temp_b_x;
            b.second = temp_b_y;
            c.first = temp_c_x;
            c.second = temp_c_y;
            d.first = temp_d_x;
            d.second = temp_d_y;
            if (getLevel() >= 3) {
                down();
            }
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
