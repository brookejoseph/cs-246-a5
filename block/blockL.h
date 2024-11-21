#ifndef BLOCKL_H
#define BLOCK_H
#include "block.h"
#include 

class LBlock: public Block {
    private:
        vector<pair<int, int>> abcd;

    public:
        LBlock(std::weak_ptr<Board> board,
        vector<pair<int, int>> abcd;

    virtual char cellAt(int x, int y) override;
    virtual char getType() override;
};

#endif