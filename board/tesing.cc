#include "../board/board.h"
#include "../block/blockZ.h"
#include "../block/blockJ.h"
#include "../cell/cell.h"
#include "../cell/cell.cc"

#include <iostream>
#include <memory>
#include <vector>
#include <utility>

using namespace std;

int main()
{
    pair<int, int> coordA = {0, 0};
    pair<int, int> coordB = {0, 1};
    pair<int, int> coordC = {1, 1};
    pair<int, int> coordD = {1, 2};
    Board *newCell = new Cell(18, 18);
    newCell = new ZBlock(newCell, coordA, coordB, coordC, coordD);
    newCell = new ZBlock(newCell, coordA, coordB, coordC, coordD);
    return 0;
}