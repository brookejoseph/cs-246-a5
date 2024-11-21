#include <vector>
#include <tuple>
#include <iostream>
#include <ostream>
#include "block.h"
#include "../cell/cell.h"
#include "blockDec.h"

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

BlockDec::BlockDec(Block *blockDec) : blockDec(blockDec) {}

char BlockDec::getChar()
{
    return blockDec->getChar();
};

virtual vector<tuple<pair<int, int>, pair<int, int>, pair<int, int>, pair<int, int>>> getCoord();
virtual ~BlockDec() = default;