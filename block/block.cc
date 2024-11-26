#include <vector>
#include <tuple>
#include <iostream>
#include <ostream>
#include "../block/block.h"
#include "../board/board.h"

using namespace std;

Block::Block(Board *cells) : Board(dimX, dimY), cells{cells} {};

Block::~Block() = default;
