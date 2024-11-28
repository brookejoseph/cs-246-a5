#ifndef BLOCKS_H
#define BLOCKS_H

// the main block interface file
#include <vector>
#include <tuple>
#include <iostream>
#include <ostream>
#include "block.h"

class SBlock : public Block {
    public:
        SBlock(Board *cell,
            pair<int, int> a,
            pair<int, int> b,
            pair<int, int> c,
            pair<int, int> d); // to change
        SBlock();
        SBlock(Board *cell);
        ~SBlock() override = default;

        virtual void rotateccw() override;
        virtual void rotatecw() override;
        virtual char getValue(int x, int y) override;
        virtual char getType() override;
        virtual void left() override;
        virtual void right() override;
        virtual void down() override;
        // void drop() override;
};

#endif