#include "level.h"

Level::Level(std::vector<char> sequence): sequence{sequence} {}

Level::Level(std::vector<char> sequence, bool isRandom): sequence{sequence}, random{isRandom} {}

Level::~Level() {}

void Level::setRandom(bool isRandom) { random = isRandom; }

void Level::setSequence(std::vector<char> seq) { sequence = seq; }
