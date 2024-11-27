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

using namespace std;
class GameEngine
{
public:
    Board *baseBoard;

    GameEngine()
    {
        baseBoard = new Board(11, 18);

        char blockType = chooseBlockType();

        switch (blockType)
        {
        case 'I':
        {
            IBlock *iBlock = new IBlock();
            baseBoard->setCurrentBlock(iBlock);
            break;
        }
        case 'J':
        {
            JBlock *jBlock = new JBlock();
            baseBoard->setCurrentBlock(jBlock);
            break;
        }
        case 'L':
        {
            LBlock *lBlock = new LBlock();
            baseBoard->setCurrentBlock(lBlock);
            break;
        }
        case 'O':
        {
            OBlock *oBlock = new OBlock();
            baseBoard->setCurrentBlock(oBlock);
            break;
        }
        case 'S':
        {
            SBlock *sBlock = new SBlock();
            baseBoard->setCurrentBlock(sBlock);
            break;
        }
        case 'Z':
        {
            ZBlock *zBlock = new ZBlock();
            baseBoard->setCurrentBlock(zBlock);
            break;
        }
        case 'T':
        {
            TBlock *tBlock = new TBlock();
            baseBoard->setCurrentBlock(tBlock);
            break;
        }
        default:
            std::cerr << "Invalid block type!" << std::endl;
            break;
        }
    }

    ~GameEngine()
    {
        delete baseBoard;
    }

private:
    char chooseBlockType()
    {
        std::srand(std::time(nullptr));
        int randomNum = std::rand() % 7;

        switch (randomNum)
        {
        case 0:
            return 'I';
        case 1:
            return 'J';
        case 2:
            return 'L';
        case 3:
            return 'O';
        case 4:
            return 'S';
        case 5:
            return 'Z';
        case 6:
            return 'T';
        }
        return 'Z';
    }
};