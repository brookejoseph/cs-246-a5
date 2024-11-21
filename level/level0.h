#ifndef LEVEL0_H
#define LEVEL0_H
#include "level.h"
#include "block.h"
#include <vector>
#include <memory>

class Level0: public Level {
    unsigned int position; // position in sequence file

    public:
        explicit Level0(std::vector<char> sequence);
        ~Level0();

        virtual int getLevel() const override;
        virtual std::shared_ptr<Block> createBlock() override;
        void setPosition(int n); // set position to n
};

#endif