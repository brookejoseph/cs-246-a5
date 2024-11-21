#include <vector>
#include <tuple>
#include <iostream>
#include <ostream>
#include "block.h"
#include "../cell/cell.h"

using namespace std;

class BlockDec : public Block
{
protected:
    Block *blockDec;

private:
    explicit BlockDec(Block *blockDec);
    virtual char getChar();
    virtual vector<tuple<pair<int, int>, pair<int, int>, pair<int, int>, pair<int, int>>> getCoord();
    virtual ~BlockDec() = default;
};
