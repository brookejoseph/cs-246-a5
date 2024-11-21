#include <vector>
#include <tuple>
#include <iostream>
#include <ostream>
// #include "cell/cell.h" // to add

using namespace std;

class Block
{
private:
    vector<tuple<pair<int, int>, pair<int, int>, pair<int, int>, pair<int, int>>> cells;

public:
    Block(
        vector<tuple<pair<int, int>>> a,
        vector<tuple<pair<int, int>>> b,
        vector<tuple<pair<int, int>>> c,
        vector<tuple<pair<int, int>>> d);
    ~Block();
    Block(Block const &other) {};
    Block(Block &&other) {};
    Block &operator=(const Block &other) {};
    Block &operator+=(const Block &other) {}; // potentially useful for merging the board and block
    Block &operator-=(const Block &other) {};

    bool getHeavy();
    void setHeavy();
    virtual char getChar() = 0;

    void heavy();
    void virtual rotateccw();
    void virtual rotatecw();
    void left();
    void right();
    void down();
    void drop();

    vector<tuple<pair<int, int>, pair<int, int>, pair<int, int>, pair<int, int>>> getCoord()
    {
        return this->cells;
    };
};