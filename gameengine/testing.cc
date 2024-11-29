#include "../gameengine/gameengine.h"
#include "../block/blockZ.h"
#include "../block/blockJ.h"
#include "../block/blockO.h"
#include "../block/blockI.h"
#include "../block/blockT.h"
#include "../block/blockS.h"
#include "../block/blockL.h"

#include <string>
#include <iostream>
#include <sstream>
#include <vector>
#include <fstream>

using namespace std;

void printBoard(const std::shared_ptr<Board> &board, int dimX, int dimY)
{
    std::cout << "Current Board State:\n";
    for (int y = 0; y < dimY; ++y)
    {
        for (int x = 0; x < dimX; ++x)
        {
            std::cout << board->getChar(x, y) << " ";
        }
        std::cout << std::endl;
    }
}

void test1()
{
    GameEngine gameEngine(11, 18);
    gameEngine.executeCommand("T");
    gameEngine.executeCommand("clockwise", 1);
    gameEngine.executeCommand("drop");
    /*

     gameEngine.executeCommand("Z");
     gameEngine.executeCommand("clockwise", 1);
     gameEngine.executeCommand("drop");
    */

    auto board = gameEngine.currentBoard();
    printBoard(board, 11, 18);
}
int main()
{
    test1();
    return 0;
}
