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
    Board board(12, 12);

    pair<int, int> coordA = {0, 0};
    pair<int, int> coordB = {0, 1};
    pair<int, int> coordC = {1, 1};
    pair<int, int> coordD = {1, 2};

    ZBlock zblock(&board, coordA, coordB, coordC, coordD);

    cout << "Initial coordinates: ";
    printCoords(zblock.getCoord());
    cout << "Initial type: " << zblock.getType() << endl;

    zblock.left();
    cout << "After moving left: ";
    printCoords(zblock.getCoord());

    zblock.right();
    cout << "After moving right: ";
    printCoords(zblock.getCoord());

    zblock.down();
    cout << "After moving down: ";
    printCoords(zblock.getCoord());

    zblock.rotatecw();
    cout << "After rotating clockwise: ";
    printCoords(zblock.getCoord());

    zblock.rotateccw();
    cout << "After rotating counterclockwise: ";
    printCoords(zblock.getCoord());

    cout << "Final coordinates: ";
    printCoords(zblock.getCoord());

    return 0;
}
