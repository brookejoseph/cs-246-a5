#ifndef LEVEL_H
#define LEVEL_H
#include "block.h

class Level {

    public:
        virtual int getLevel() = 0;
        virtual Block *createBlock() = 0;

        virtual ~Level() = 0;
};

#endif
