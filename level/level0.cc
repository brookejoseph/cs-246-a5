#include "level0.h"
#include "../block/blockJ.h"
#include "../block/blockI.h"
#include "../block/blockS.h"
#include "../block/blockO.h"
#include "../block/blockL.h"
#include "../block/blockT.h"
#include "../block/blockZ.h"

Level0::Level0() : Level() {}

int Level0::getLevel() const { return 0; }

Block* Level0::createBlock()
{
    Block *nextBlock;
    char blockType = sequence.at(position);

    switch (blockType)
    {
    case 'I':
        nextBlock = new IBlock();
        break;
    case 'J':
        nextBlock = new JBlock();
        break;
    case 'L':
        nextBlock = new LBlock();
        break;
    case 'O':
        nextBlock = new OBlock();
        break;
    case 'S':
        nextBlock = new SBlock();
        break;
    case 'Z':
        nextBlock = new ZBlock();
        break;
    case 'T':
        nextBlock = new TBlock();
        break;
    }

    // increment position in sequence file
    if (position < sequence.size() - 1)
    {
        ++position;
    }
    else
    {
        position = 0;
    }

    nextBlock->setLevel(0);
    return nextBlock;
}