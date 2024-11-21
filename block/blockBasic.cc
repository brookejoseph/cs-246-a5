#include <vector>
#include <tuple>
#include <iostream>
#include <ostream>
#include "block.h"
#include "../cell/cell.h"
#include "blockDec.h"

using namespace std;

class blockBasic : public Block
{
public:
    vector<tuple<pair<int, int>, pair<int, int>, pair<int, int>, pair<int, int>>> getCoord();
    char getChar() override;
};
// remove the above later

char blockBasic::getChar()
{
    return ' ';
};

vector<tuple<pair<int, int>, pair<int, int>, pair<int, int>, pair<int, int>>> blockBasic::getCoord()
{
    return vector<tuple<pair<int, int>, pair<int, int>, pair<int, int>, pair<int, int>>>{
        make_tuple(make_pair(0, 0), make_pair(0, 0), make_pair(0, 0), make_pair(0, 0))};
};
