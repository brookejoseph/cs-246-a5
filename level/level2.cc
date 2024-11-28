#include "level2.h"
#include "../block/blockJ.h"
#include "../block/blockI.h"
#include "../block/blockS.h"
#include "../block/blockO.h"
#include "../block/blockL.h"
#include "../block/blockT.h"
#include "../block/blockZ.h"

Level2::Level2(): Level() {}

int Level2::getLevel() const { return 2; }

Block* Level2::createBlock()
{
    Block *nextBlock;
    int x = rand() % 7;

    switch (x)
    {
    case 0:
        nextBlock = new IBlock();
        break;
    case 1:
        nextBlock = new JBlock();
        break;
    case 2:
        nextBlock = new LBlock();
        break;
    case 3:
        nextBlock = new OBlock();
        break;
    case 4:
        nextBlock = new SBlock();
        break;
    case 5:
        nextBlock = new ZBlock();
        break;
    case 6:
        nextBlock = new TBlock();
        break;
    }

    nextBlock->setLevel(2);
    return nextBlock;
}
