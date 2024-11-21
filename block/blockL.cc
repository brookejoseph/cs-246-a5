#include "blockl.h"

LBlock::LBlock(std::weak_ptr<Cell> cell,
            pair<int, int> a,
            pair<int, int> b,
            pair<int, int> c,
            pair<int, int> d):
    Block{cell}, a{a}, b{b}, c{c}, d{d} {}

char LBlock::cellAt(int x, int y) {
    // iterate over a, b, c, d
    // if (x, y) is one of coordinate
        return 'L';
    } else {
        return cell->cellAt(int x, int y);
    }
}

char LBlock::getType() { return 'L'; } 


