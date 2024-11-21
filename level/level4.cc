#include "level4.h"

Level4::Level4(std::vector<char> sequence, bool isRandom, int seed):
    Level{sequence, isRandom}, position{0}, seed{seed} {
    srand(seed); 
}

Level4::~Level4() {}

int Level4::getLevel() const { return 4; }

std::shared_ptr<Block> Level4::createBlock() {
    std::shared_ptr<Block> nextBlock;

    if (random) { // if block generation is random
        int x = rand() % 9;

        if (x == 0 || x == 1) {
            nextBlock = std::make_shared<SBlock>();
        } else if (x == 2 || x == 3) {
            nextBlock = std::make_shared<ZBlock>();
        } else if (x == 4) {
            nextBlock = std::make_shared<IBlock>();
        } else if (x == 5) {
            nextBlock = std::make_shared<JBlock>();
        } else if (x == 6) {
            nextBlock = std::make_shared<LBlock>();
        } else if (x == 7) {
            nextBlock = std::make_shared<OBlock>();
        } else if (x == 8) {
            nextBlock = std::make_shared<TBlock>();
        }

    } else { // generate from sequence file
        char blockType = sequence.at(position);

        switch (blockType) {
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
        if (position < sequence.size() - 1) {
            ++position;
        } else {
            position = 0;
        }
    }

    return nextBlock;
}
