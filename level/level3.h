#ifndef LEVEL3_H
#define LEVEL3_H
#include "level.h"

class Level3: public Level {
    public:
        Level3() = default;
        ~Level3() = default;

        virtual int getLevel() const override;
        virtual std::shared_ptr<Block> createBlock() override;
};

#endif
