#ifndef BLOCKI_H
#define BLOCKI_H
// the main block interface file
#include <vector>
#include <tuple>
#include <iostream>
#include <ostream>
#include "cell/cell.h" // to add
#include "block.h"

using namespace std;

class IBlock : public Block
{
private:
    Board *cell;
    pair<int, int> a;
    pair<int, int> b;
    pair<int, int> c;
    pair<int, int> d;

public:
    IBlock(Board *cell,
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
    vector<pair<int, int>> getCoord();
};

#endif