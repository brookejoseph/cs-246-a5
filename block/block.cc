#include <vector>
#include <tuple>
#include <iostream>
#include <ostream>
#include "cell/cell.h" // to add
#include "block.h"
#include "board/board.h"

using namespace std;

Block::Block(Board *cells) : cells{cells} {};

Block::~Block() = default;