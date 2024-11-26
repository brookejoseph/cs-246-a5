#include <vector>
#include <tuple>
#include <iostream>
#include <ostream>
#include "cell/cell.h" // to add
#include "../block/block.h"
#include "../board/board.h"

using namespace std;

Block::Block(Board *cells) : Board(), cells{cells} {};

Block::~Block() { delete cells; };
