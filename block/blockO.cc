
#include <vector>
#include <tuple>
#include <iostream>
#include <ostream>
#include "cell/cell.h" // to add
#include "block.h"


using namespace std;


OBlock::OBlock(Cell *cell,
               pair<int, int> a,
               pair<int, int> b,
               pair<int, int> c,
               pair<int, int> d): Block(cell), a{a}, b{b}, c{c}, d{d} {};

char OBlock::getChar(int x, int y){
    if(((x == a.first) && (y == a.second)) || ((x == b.first) && (y == b.second)) || ((x == c.first) && (y == c.second)) || ((x == d.first)) && (y == d.second)){
        return 'O';
    };
    else{
        return cell->getChar(x, y);
    };
};

char OBlock::getType(){
    return 'O';
};