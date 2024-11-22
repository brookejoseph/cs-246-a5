
#include <vector>
#include <tuple>
#include <iostream>
#include <ostream>
#include "cell/cell.h" // to add
#include "block.h"
#include "blockS.h"
#include "cell/cell.h"
#include "board/board.h"


using namespace std;


SBlock::SBlock(Cell *cell,
               pair<int, int> a,
               pair<int, int> b,
               pair<int, int> c,
               pair<int, int> d): Block(cell), a{a}, b{b}, c{c}, d{d} {};

char SBlock::getChar(int x, int y){
    if(((x == a.first) && (y == a.second)) || ((x == b.first) && (y == b.second)) || ((x == c.first) && (y == c.second)) || ((x == d.first)) && (y == d.second)){
        return 'S';
    };
    else{
        return cell->getChar(x, y);
    };
};

char SBlock::getType(){
    return 'S';
};