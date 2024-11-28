#ifndef LEVEL2_H
#define LEVEL2_H
#include "level.h"

class Level2: public Level {
    public:
        Level2();
        ~Level2() = default;

        virtual int getLevel() const override;
        virtual Block* createBlock() override;
};

#endif
