#include <vector>
#include <tuple>
#include <iostream>
#include <ostream>
#include "cell/cell.h" // to add

using namespace std;

enum state
{
    ccw,
    cw,
    left,
    right,
    rotate
};

class Block
{
private:
    vector<tuple<pair<int, int>, pair<int, int>, pair<int, int>>> cells;
    state state;

public:
    Block();
    ~Block();
    Block(Block const &other) {};
    Block(Block &&other) {};
    Block &operator=(const Block &other) {};
    Block &operator+=(const Block &other) {}; // potentially useful for merging the board and block
    Block &operator-=(const Block &other) {};

    void heavy();
    void virtual rotateccw();
    void virtual rotatecw();
    void left();
    void right();
    void down();
    void drop();
};