#include "level0.h"
#include "../block/blockJ.h"
#include "../block/blockI.h"
#include "../block/blockS.h"
#include "../block/blockO.h"
#include "../block/blockL.h"
#include "../block/blockT.h"
#include "../block/blockZ.h"

Level0::Level0(): Level() {}

int Level0::getLevel() const { return 0; }

std::shared_ptr<Block> Level0::createBlock()
{
    std::shared_ptr<Block> nextBlock;
    char blockType = sequence.at(position);

    switch (blockType)
    {
    case 'I':
        nextBlock = std::make_shared<IBlock>();
        break;
    case 'J':
        nextBlock = std::make_shared<JBlock>();
        break;
    case 'L':
        nextBlock = std::make_shared<LBlock>();
        break;
    case 'O':
        nextBlock = std::make_shared<OBlock>();
        break;
    case 'S':
        nextBlock = std::make_shared<SBlock>();
        break;
    case 'Z':
        nextBlock = std::make_shared<ZBlock>();
        break;
    case 'T':
        nextBlock = std::make_shared<TBlock>();
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