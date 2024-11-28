#include "level1.h"
#include "../block/blockJ.h"
#include "../block/blockI.h"
#include "../block/blockS.h"
#include "../block/blockO.h"
#include "../block/blockL.h"
#include "../block/blockT.h"
#include "../block/blockZ.h"

Level1::Level1(): Level() {}

int Level1::getLevel() const { return 1; }

Block* Level1::createBlock()
{
    Block *nextBlock;
    int x = rand() % 12;

    if (x == 0)
    {
        nextBlock = new SBlock();
    }
    else if (x == 1)
    {
        nextBlock = new ZBlock();
    }
    else if (x == 2 || x == 3)
    {
        nextBlock = new IBlock();
    }
    else if (x == 4 || x == 5)
    {
       nextBlock = new JBlock();
    }
    else if (x == 6 || x == 7)
    {
        nextBlock = new LBlock();
    }
    else if (x == 8 || x == 9)
    {
        nextBlock = new OBlock();
    }
    else if (x == 10 || x == 11)
    {
        nextBlock = new TBlock();
    }

    nextBlock->setLevel(1);
    return nextBlock;
}
