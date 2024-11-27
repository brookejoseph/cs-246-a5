#include "level.h"

Level::~Level() {}

void Level::setRandom(bool isRandom) { random = isRandom; }

void Level::setSequence(std::vector<char> seq) { sequence = seq; }
