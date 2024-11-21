#include "level.h"
#include <vector>

Level::Level(std::vector<char> sequence): sequence{sequence} {}

Level::~Level() {}

void Level::setRandom(bool isRandom) { random = isRandom; }

void Level::setSequence(std::vector<char> seq) { sequence = seq; }
