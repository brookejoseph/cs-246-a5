
#include <vector>
#include <tuple>
#include <iostream>
#include <ostream>
#include "cell/cell.h" // to add
#include "block.h"
#include "blockJ.h"

using namespace std;

JBlock::JBlock(
    vector<tuple<pair<int, int>>> a,
    vector<tuple<pair<int, int>>> b,
    vector<tuple<pair<int, int>>> c,
    vector<tuple<pair<int, int>>> d)
    : cells{{make_pair(0, 0), make_pair(1, 0), make_pair(2, 0), make_pair(0, 1)}} {};

char JBlock::getChar()
{
    return 'J';
};
