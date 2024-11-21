#ifndef LEVEL_H
#define LEVEL_H
#include "block.h"
#include <vector>
#include <memory>

class Level {
    protected:
        bool random;
        std::vector<char> sequence;

    public:
        Level() = default; // default ctor
        explicit Level(std::vector<char> sequence);
        virtual ~Level() = 0; // default dtor

        void setRandom(bool isRandom); // set random generation
        void setSequence(std::vector<char> seq); // set block sequence

        virtual int getLevel() const = 0; // get the level number
        virtual std::shared_ptr<Block> createBlock() = 0; // generate a Block

};

#endif
