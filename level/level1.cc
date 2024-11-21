#include "level1.h"
#include <vector>
#include <cstdlib>

Level1::Level1(int seed): seed{seed} { srand(seed); }

Level1::~Level1() {}

int Level1::getLevel() const { return 1; }

std::shared_ptr<Block> Level1::createBlock() {
    std::shared_ptr<Block> nextBlock;
    int x = rand() % 12;

    if (x == 0) {
        nextBlock = std::make_shared<SBlock>();
    } else if (x == 1) {
        nextBlock = std::make_shared<ZBlock>();
    } else if (x == 2 || x == 3) {
        nextBlock = std::make_shared<IBlock>();
    } else if (x == 4 || x == 5) {
        nextBlock = std::make_shared<JBlock>();
    } else if (x == 6 || x == 7) {
        nextBlock = std::make_shared<LBlock>();
    } else if (x == 8 || x == 9) {
        nextBlock = std::make_shared<OBlock>();
    } else if (x == 10 || x == 11) {
        nextBlock = std::make_shared<TBlock>();
    }

    return nextBlock;
}
