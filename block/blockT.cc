
#include <vector>
#include <tuple>
#include <iostream>
#include <ostream>
#include "cell/cell.h" // to add
#include "block.h"

using namespace std;

Block::Block(
    vector<tuple<pair<int, int>>> a,
    vector<tuple<pair<int, int>>> b,
    vector<tuple<pair<int, int>>> c,
    vector<tuple<pair<int, int>>> d)
    : cells{{make_pair(1, 1), make_pair(2, 0), make_pair(2, 1), make_pair(3, 1)}} {};

char Block::getChar()
{
    return 'T';
};
