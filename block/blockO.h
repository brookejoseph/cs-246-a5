#ifndef BLOCKO_H
#define BLOCKO_H

// the main block interface file
#include <vector>
#include <tuple>
#include <iostream>
#include <ostream>
#include "block.h"

class OBlock : public Block {
    public:
        OBlock(Board *cell,
            pair<int, int> a,
            pair<int, int> b,
            pair<int, int> c,
            pair<int, int> d); // to change
        OBlock();
        OBlock(Board *cell);
        ~OBlock() override = default;

        void rotateccw() override;
        void rotatecw() override;
        char getValue(int x, int y) override;
        char getType() override;
        void left() override;
        void right() override;
        void down() override;
        // void drop() override;
};

#endif