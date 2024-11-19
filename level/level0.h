#ifndef LEVEL0_H
#define LEVEL0_H
#include "level.h"
#include "block.h"
#include <fstream>
#include <string>

class Level0: public Level {
    const int level = 0;
    const string sequenceFile;
    std::ifstream moves;


    public:
        virtual int getLevel() const override;
        virtual Block *createBlock() override;

        Level0(string sequenceFile);
        ~Level0();
};

#endif