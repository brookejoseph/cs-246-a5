#ifndef LEVEL1_H
#define LEVEL1_H
#include "level.h"

class Level1: public Level {
    int seed; // seed for random generation

    public:
        explicit Level1(int seed);
        ~Level1();

        virtual int getLevel() const override;
        virtual std::shared_ptr<Block> createBlock() override;
};

#endif

