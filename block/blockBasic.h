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
