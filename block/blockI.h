
// the main block interface file
#include <vector>
#include <tuple>
#include <iostream>
#include <ostream>
#include "cell/cell.h" // to add
#include "block.h"

using namespace std;

enum state
{
    ccw,
    cw,
    left,
    right,
    rotate
};

class IBlock : public Block
{
private:
    vector<tuple<pair<int, int>, pair<int, int>, pair<int, int>, pair<int, int>>> cells;
    state state;

public:
    void virtual rotateccw();
    void virtual rotatecw();
};
