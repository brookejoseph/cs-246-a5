#include "level2.h"

Level2::Level2(int seed): seed{seed} { srand(seed); }

Level2::~Level2() {}

int Level2::getLevel() const { return 2; }

std::shared_ptr<Block> Level2::createBlock() {
    std::shared_ptr<Block> nextBlock;
    int x = rand() % 7;

    switch(x) {
        case 0:
            nextBlock = std::make_shared<IBlock>();
            break;
        case 1:
            nextBlock = std::make_shared<JBlock>();
            break;
        case 2:
            nextBlock = std::make_shared<LBlock>();
            break;
        case 3:
            nextBlock = std::make_shared<OBlock>();
            break;
        case 4:
            nextBlock = std::make_shared<SBlock>();
            break;
        case 5:
            nextBlock = std::make_shared<ZBlock>();
            break;
        case 6:
            nextBlock = std::make_shared<TBlock>();
            break;
    }

    return nextBlock;
}
