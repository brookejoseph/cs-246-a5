#ifndef BLOCKO_H
#define BLOCKO_H

// the main block interface file
#include <vector>
#include <tuple>
#include <iostream>
#include <ostream>
#include "block.h"

using namespace std;

class OBlock : public Block
{
private:
    Board *cell;
    pair<int, int> a;
    pair<int, int> b;
    pair<int, int> c;
    pair<int, int> d;

public:
    OBlock(Board *cell,
           pair<int, int> a,
           pair<int, int> b,
           pair<int, int> c,
           pair<int, int> d); // to change
    OBlock();
    OBlock(Board *cell);
    ~OBlock() override = default;
    int getLevel() override;
    void setLevel(int val) override;

    void rotateccw() override;
    void rotatecw() override;
    char getChar(int x, int y) override;
    char getType() override;
    void left() override;
    void right() override;
    void down() override;
    // void drop() override;
    vector<pair<int, int>> getCoord() override;
};

#endif