#include <vector>
#include <tuple>
#include <iostream>
#include <ostream>
#include "cell/cell.h" // to add
#include "block.h"
#include "board/board.h"

using namespace std;

class Block
{
private:
    // vector<tuple<pair<int, int>, pair<int, int>, pair<int, int>, pair<int, int>>> cells;
    Board *cells;

public:
    Block(vector<tuple<pair<int, int>, pair<int, int>, pair<int, int>, pair<int, int>>> a) {} // done;
    ~Block() = default;                                                                       // done
    Block(Block const &other) {};                                                             // done
    Block(Block &&other) {};                                                                  // done
    Block &operator=(const Block &other) {};
    Block &operator+=(const Block &other) {}; // potentially useful for merging the board and block
    Block &operator-=(const Block &other) {};

    bool getHeavy();
    void setHeavy();
    virtual char getChar() = 0;

    void heavy();
    void virtual rotateccw();
    void virtual rotatecw();
    void left();  // done
    void right(); // done
    void down();  // done
    void drop();
};

Block::Block(vector<tuple<pair<int, int>, pair<int, int>, pair<int, int>, pair<int, int>>> a) : cells{a} {};

vector<tuple<pair<int, int>, pair<int, int>, pair<int, int>, pair<int, int>>> Block::getCoord()
{
    return cells;
};

Block::~Block() = default;
Block::Block(Block const &other)
{
    cells = other.cells;
};
Block::Block(Block &&other)
{
    cells = other.cells;
    other.cells.clear();
};

void Block::left()
{
    for (auto &t : this->cells)
    {
        auto &[p1, p2, p3, p4] = t;
        p1.first -= 1;
        p2.first -= 1;
        p3.first -= 1;
        p4.first -= 1;
    };
};

void Block::right()
{
    for (auto &t : this->cells)
    {
        auto &[p1, p2, p3, p4] = t;
        p1.first += 1;
        p2.first += 1;
        p3.first += 1;
        p4.first += 1;
    };
};

void Block::down()
{
    for (auto &t : this->cells)
    {
        auto &[p1, p2, p3, p4] = t;
        p1.second -= 1;
        p2.second -= 1;
        p3.second -= 1;
        p4.second -= 1;
    };
}