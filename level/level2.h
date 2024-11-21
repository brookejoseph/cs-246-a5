#ifndef LEVEL2_H
#define LEVEL2_H
#include "level.h"

class Level2: public Level {
    int seed; // seed for random generation

    public:
        explicit Level2(int seed);
        ~Level2();

        virtual int getLevel() const override;
        virtual std::shared_ptr<Block> createBlock() override;
};

#endif
