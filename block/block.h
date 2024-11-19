// the main block interface file
#include <vector>
#include "cell/cell.h" // to add

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
    vector<Cell> cells;
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
    void virtual left();
    void virtual right();
    void virtual down();
    void virtual drop();
};
