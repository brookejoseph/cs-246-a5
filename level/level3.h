#ifndef LEVEL3_H
#define LEVEL3_H
#include "level.h"

class Level3: public Level {
    unsigned int position; // position in sequence file

    public:
        explicit Level3(std::vector<char> sequence, bool isRandom);
        ~Level3();

        virtual int getLevel() const override;
        virtual std::shared_ptr<Block> createBlock() override;
};

#endif
