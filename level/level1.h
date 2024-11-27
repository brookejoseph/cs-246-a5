#ifndef LEVEL1_H
#define LEVEL1_H
#include "level.h"

class Level1 : public Level
{
public:
    Level1() = default;
    ~Level1() = default;

    virtual int getLevel() const override;
    virtual std::shared_ptr<Block> createBlock() override;
};

#endif
