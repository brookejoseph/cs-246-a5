#include "level3.h"
#include "../block/blockJ.h"
#include "../block/blockI.h"
#include "../block/blockS.h"
#include "../block/blockO.h"
#include "../block/blockL.h"
#include "../block/blockT.h"
#include "../block/blockZ.h"

Level3::Level3() : Level() {}

int Level3::getLevel() const { return 3; }

std::shared_ptr<Block> Level3::createBlock()
{
    std::shared_ptr<Block> nextBlock;

    if (random)
    { // if block generation is random
        int x = rand() % 9;

        if (x == 0 || x == 1)
        {
            nextBlock = std::make_shared<SBlock>();
        }
        else if (x == 2 || x == 3)
        {
            nextBlock = std::make_shared<ZBlock>();
        }
        else if (x == 4)
        {
            nextBlock = std::make_shared<IBlock>();
        }
        else if (x == 5)
        {
            nextBlock = std::make_shared<JBlock>();
        }
        else if (x == 6)
        {
            nextBlock = std::make_shared<LBlock>();
        }
        else if (x == 7)
        {
            nextBlock = std::make_shared<OBlock>();
        }
        else if (x == 8)
        {
            nextBlock = std::make_shared<TBlock>();
        }
        else
        {
            throw std::runtime_error("Invalid random value generated for block creation");
        }
    }
    else
    { // generate from sequence file
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
        default:
            throw std::invalid_argument("Invalid block type in sequence");
        }

        // Increment position in sequence file
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
