#ifndef LEVEL4_H
#define LEVEL4_H
#include "level.h"

class Level4: public Level {
    unsigned int position; // position in sequence file

    public:
        Level4();
        ~Level4();

        virtual int getLevel() const override;
        virtual std::shared_ptr<Block> createBlock() override;
};

#endif
