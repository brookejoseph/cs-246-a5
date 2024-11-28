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
    cout << "hello before init of board" << endl;
    GameEngine gameEngine(11, 18);
    cout << "hello after init of board" << endl;

    // gameEngine.executeCommand("oBlock");
    // gameEngine.executeCommand("validMove");
    // gameEngine.executeCommand("drop");
    // cout << "call 1" << endl;

    // gameEngine.executeCommand("oBlock");
    // gameEngine.executeCommand("right", 2);
    // gameEngine.executeCommand("validMove");
    // gameEngine.executeCommand("drop");
    // cout << "call 2" << endl;
    // gameEngine.executeCommand("oBlock");
    // gameEngine.executeCommand("right", 4);
    // gameEngine.executeCommand("validMove");
    // gameEngine.executeCommand("drop");
    // cout << "call 3" << endl;
    // gameEngine.executeCommand("oBlock");
    // gameEngine.executeCommand("right", 6);
    // gameEngine.executeCommand("validMove");
    // gameEngine.executeCommand("drop");
    // cout << "call 4" << endl;
    // gameEngine.executeCommand("oBlock");
    // gameEngine.executeCommand("right", 8);
    // gameEngine.executeCommand("validMove");
    // gameEngine.executeCommand("drop");
    // cout << "call 5" << endl;
    // gameEngine.executeCommand("iBlock");
    // gameEngine.executeCommand("clockwise", 1);
    // gameEngine.executeCommand("right", 10);
    // gameEngine.executeCommand("validMove");
    // gameEngine.executeCommand("drop");
    // cout << "call 5" << endl;

    
    gameEngine.executeCommand("levelup");
    gameEngine.executeCommand("levelup");
    gameEngine.executeCommand("oBlock");
    gameEngine.executeCommand("right", 3);
    gameEngine.executeCommand("validMove");
    gameEngine.executeCommand("drop");


    Board *current = gameEngine.returnCurrentBoard();

    int num = current->checkClearLine();
    printBoard(current, 11, 18);

    return 0;
};
