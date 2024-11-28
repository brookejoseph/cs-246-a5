#include <vector>
#include <tuple>
#include <iostream>
#include <ostream>
#include "../block/block.h"
#include "../board/board.h"

// Block::Block(Board *cells) : Board(dimX, dimY), cells{cells} {};
Block::Block(std::shared_ptr<Board> cells,
             std::pair<int, int> a,
             std::pair<int, int> b,
             std::pair<int, int> c,
             std::pair<int, int> d): cells{cells}, a{a}, b{b}, c{c}, d{d} {}

Block::~Block() {}

std::vector<std::pair<int, int>> Block::getCoord() { return {a, b, c, d}; }

int Block::getLevel() const { return levelCreated; }

void Block::setLevel(int val) { levelCreated = val; }
