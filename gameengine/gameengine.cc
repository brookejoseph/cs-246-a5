#include "gameengine.h"
#include "../board/board.h"
#include "../board/board.cc"
#include "../block/blockZ.h"
#include "../block/blockJ.h"
#include "../block/blockO.h"
#include "../block/blockI.h"
#include "../block/blockT.h"
#include "../block/blockS.h"
#include "../block/blockL.h"
#include "../cell/cell.h"
#include "../cell/cell.cc"

#include <iostream>
#include <memory>
#include <vector>
#include <utility>
#include <map>

using namespace std;

void GameEngine::initializeCommandMap()
{
    commandMap = std::map<string, void (Board::*)()>{// Ensure the type is correct
                                                     {"left", &Board::left},
                                                     {"right", &Board::right},
                                                     {"down", &Board::down},
                                                     {"drop", &Board::drop},
                                                     {"ccw", &Board::ccw},
                                                     {"cw", &Board::cw}};
}
GameEngine::GameEngine()
{
    if (currentChar == 'I')
    {
        IBlock *iBlock = new IBlock();
        baseBoard->setCurrentBlock(iBlock);
    }
    else if (currentChar == 'J')
    {
        JBlock *jBlock = new JBlock();
        baseBoard->setCurrentBlock(jBlock);
    }
    else if (currentChar == 'L')
    {
        LBlock *lBlock = new LBlock();
        baseBoard->setCurrentBlock(lBlock);
    }
    else if (currentChar == 'O')
    {
        OBlock *oBlock = new OBlock();
        baseBoard->setCurrentBlock(oBlock);
    }
    else if (currentChar == 'S')
    {
        SBlock *sBlock = new SBlock();
        baseBoard->setCurrentBlock(sBlock);
    }
    else if (currentChar == 'Z')
    {
        ZBlock *zBlock = new ZBlock();
        baseBoard->setCurrentBlock(zBlock);
    }
    else if (currentChar == 'T')
    {
        TBlock *tBlock = new TBlock();
        baseBoard->setCurrentBlock(tBlock);
    }
};

GameEngine::~GameEngine()
{
    delete baseBoard;
};

void GameEngine::start()
{
    baseBoard = new Board(11, 18);
};