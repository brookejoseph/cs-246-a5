#ifndef BLOCKL_H
#define BLOCKL_H
#include <vector>
#include <tuple>
#include <iostream>
#include <ostream>
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
    // void drop() override;
    vector<pair<int, int>> getCoord() override;
};

#endif