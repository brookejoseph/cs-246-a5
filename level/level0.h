#ifndef LEVEL0_H
#define LEVEL0_H
#include "level.h"

class Level0: public Level {
    public:
        Level0() = default;
        ~Level0() = default;

        virtual int getLevel() const override;
        virtual std::shared_ptr<Block> createBlock() override;
};

#endif