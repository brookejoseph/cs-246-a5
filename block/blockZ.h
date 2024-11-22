

// the main block interface file
#include <vector>
#include <tuple>
#include <iostream>
#include <ostream>
#include "cell/cell.h" // to add
#include "block.h"

using namespace std;

class ZBlock : public Block
{
private:
    Cell *cell;
    pair<int, int> a;
    pair<int, int> b;
    pair<int, int> c;
    pair<int, int> d;

public:
    ZBlock(pair<int, int> a,
           pair<int, int> b,
           pair<int, int> c,
           pair<int, int> d) : Block(), a{make_pair(0, 0)}, b{make_pair(1, 0)}, c{make_pair(2, 0)}, d{make_pair(0, 1)} {}; //to change 
    void rotateccw() overide;
    void rotatecw() override;
    char getChar(int x, int y) override;
    char getType() override;   
};