#include "level3.h"
#include "../block/blockJ.h"
#include "../block/blockI.h"
#include "../block/blockS.h"
#include "../block/blockO.h"
#include "../block/blockL.h"
#include "../block/blockT.h"
#include "../block/blockZ.h"

Level3::Level3(): Level() {}

int Level3::getLevel() const { return 3; }

Block* Level3::createBlock()
{
    Block *nextBlock;

    if (random)
    { // if block generation is random
        int x = rand() % 9;

        if (x == 0 || x == 1)
        {
            nextBlock = new SBlock();
        }
        else if (x == 2 || x == 3)
        {
            nextBlock = new ZBlock();
        }
        else if (x == 4)
        {
            nextBlock = new IBlock();
        }
        else if (x == 5)
        {
            nextBlock = new JBlock();
        }
        else if (x == 6)
        {
            nextBlock = new LBlock();
        }
        else if (x == 7)
        {
            nextBlock = new OBlock();
        }
        else if (x == 8)
        {
            nextBlock = new TBlock();
        }
    }
    else
    { // generate from sequence file
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
    }

    nextBlock->setLevel(3);
    return nextBlock;
}
