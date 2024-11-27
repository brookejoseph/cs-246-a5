#include "../block/blockZ.h"
#include "../block/blockJ.h"
#include "../cell/cell.h"
#include "../cell/cell.cc"

#include <iostream>
#include <memory>
#include <vector>
#include <utility>

using namespace std;

void printBoard(Board *board, int dimX, int dimY)
{
    cout << "Current Board State:\n";
    for (int y = dimY - 1; y >= 0; --y)
    {
        for (int x = 0; x < dimX; ++x)
        {
            cout << board->getValue(x, y) << " ";
        }
        cout << endl;
    }
}

int main()
{
    pair<int, int> coordA = {0, 1};
    pair<int, int> coordB = {1, 1};
    pair<int, int> coordC = {1, 2};
    pair<int, int> coordD = {2, 2};

    Board *baseBoard = new Board(18, 18);

    ZBlock *zBlock = new ZBlock(baseBoard, coordA, coordB, coordC, coordD);
    baseBoard->setCurrentBlock(zBlock);

    cout << "Initial coordinates: " << coordA.first << ", " << coordA.second << endl;

    baseBoard->ccw(2);

    vector<pair<int, int>> coords = zBlock->getCoord();
    for (auto &coord : coords)
    {
        cout << "Dropped coordinate: " << coord.first << ", " << coord.second << endl;
    }

    printBoard(baseBoard, 18, 18);
    delete baseBoard;
    delete zBlock;
    return 0;
}

/*
int main()
{
    // Dimensions for the board
    int rows = 18, cols = 18;

    // Initialize the Board
    Board *baseBoard = new Board(rows, cols);

    pair<int, int> coordA = {0, 1};
    pair<int, int> coordB = {1, 1};
    pair<int, int> coordC = {1, 2};
    pair<int, int> coordD = {2, 2};

    ZBlock *zBlock = new ZBlock(baseBoard, coordA, coordB, coordC, coordD);

    // Assign the ZBlock to the Board's currentBlock
    baseBoard->setCurrentBlock(zBlock);
    cout << coordA.first << " " << coordA.second << endl;

    zBlock->drop();
    cout << coordA.first << " " << coordA.second << endl;


        baseBoard->setValue(zBlock->getType(), coordA.first, coordA.second);
        baseBoard->setValue(zBlock->getType(), coordB.first, coordB.second);
        baseBoard->setValue(zBlock->getType(), coordC.first, coordC.second);
        baseBoard->setValue(zBlock->getType(), coordD.first, coordD.second);

        baseBoard->addCell(*zBlock);

    cout << "Initial Board State with ZBlock:\n";
    // printBoard(baseBoard, cols, rows);
    delete baseBoard;

    return 0;
}

*/
