#ifndef LEVEL3_H
#define LEVEL3_H
#include "level.h"

class Level3: public Level {
    unsigned int position; // position in sequence file
    int seed; // seed for random generation

    public:
        explicit Level3(std::vector<char> sequence, bool isRandom, int seed);
        ~Level3();

        virtual int getLevel() const override;
        virtual std::shared_ptr<Block> createBlock() override;
};

#endif
