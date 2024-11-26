#include <vector>
#include <tuple>
#include <iostream>
#include <ostream>
#include "../block/block.h"
#include "../block/blockZ.h"
#include "../board/board.h"
#include "../cell/cell.cc"

using namespace std;

void printCoords(const vector<pair<int, int>> &coords)
{
    for (const auto &coord : coords)
    {
        cout << "(" << coord.first << ", " << coord.second << ") ";
    }
    cout << endl;
}

int main()
{
    Cell *newGrid = new Cell(11, 15);
    return 0;
}
