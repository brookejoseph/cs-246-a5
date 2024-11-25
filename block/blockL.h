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

#define BLOCKL_H

// the main block interface file
#include <vector>
#include <tuple>
#include <iostream>
#include <ostream>
#include "cell/cell.h" // to add
#include "block.h"

using namespace std;

class LBlock : public Block
{
private:
    Board *cell;
    pair<int, int> a;
    pair<int, int> b;
    pair<int, int> c;
    pair<int, int> d;

public:
    LBlock(Board *cell,
           pair<int, int> a,
           pair<int, int> b,
           pair<int, int> c,
           pair<int, int> d); // to change
    void rotateccw() override;
    void rotatecw() override;
    char getChar(int x, int y) override;
    char getType() override;
    void left() override;
    void right() override;
    void down() override;
    void drop() override;
};

#endif