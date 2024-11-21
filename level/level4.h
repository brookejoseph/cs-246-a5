#ifndef LEVEL4_H
#define LEVEL4_H
#include "level.h"

class Level4: public Level {
    unsigned int position; // position in sequence file
    int seed; // seed for random generation

    public:
        explicit Level4(std::vector<char> sequence, bool isRandom, int seed);
        ~Level4();

        virtual int getLevel() const override;
        virtual std::shared_ptr<Block> createBlock() override;
};

#endif
