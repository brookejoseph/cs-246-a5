#ifndef LEVEL_H
#define LEVEL_H
// #include "../block/block.h"
#include <vector>
#include <memory>
#include <cstdlib>

class Block;

class Level
{
protected:
    bool random = false;
    std::vector<char> sequence;

public:
    Level() = default; // default ctor
    virtual ~Level() = 0; // default dtor

    void setRandom(bool isRandom);           // set random generation
    void setSequence(std::vector<char> seq); // set block sequence

    virtual int getLevel() const = 0;                 // get the level number
    virtual std::shared_ptr<Block> createBlock() = 0; // generate a Block
};

#endif
