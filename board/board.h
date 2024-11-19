#include <vector>
#include <tuple>
#include <iostream>
#include <ostream>
#include "block/block.h"
#include "level/level.h"

class Board
{
private:
    Block *current_block;
    Level *current_level;
}