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
    unsigned int position;

public:
    Level() noexcept;          // default ctor
    virtual ~Level() = default; // default dtor

    void setRandom(bool isRandom);           // set random generation
    void setSequence(const std::vector<char> &seq); // set block sequence
    void setPosition(int n);

    virtual int getLevel() const = 0;                 // get the level number
    virtual Block* createBlock() = 0; // generate a Block
};

#endif
