#include "../gameengine/gameengine.h"
#include "../block/blockZ.h"
#include "../block/blockJ.h"
#include "../block/blockO.h"
#include "../block/blockI.h"
#include "../block/blockT.h"
#include "../block/blockS.h"
#include "../block/blockL.h"

#include <iostream>

using namespace std;

void printBoard(Board *board, int dimX, int dimY)
{

    cout << "Current Board State:\n";
    for (int y = 0; y <= dimY - 1; ++y)
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
    GameEngine gameEngine(11, 18);

    gameEngine.executeCommand("oBlock");
    gameEngine.executeCommand("right", 2);
    gameEngine.executeCommand("validMove");
    gameEngine.executeCommand("drop");

    gameEngine.executeCommand("zBlock");
    gameEngine.executeCommand("right", 5);
    gameEngine.executeCommand("left", 2);
    gameEngine.executeCommand("validMove");
    gameEngine.executeCommand("drop");

    gameEngine.executeCommand("zBlock");
    gameEngine.executeCommand("ccw", 1);
    gameEngine.executeCommand("right", 5);
    gameEngine.executeCommand("left", 3);
    gameEngine.executeCommand("validMove");
    gameEngine.executeCommand("drop");

    Board *current = gameEngine.returnCurrentBoard();
    printBoard(current, 11, 18);

    return 0;
};
