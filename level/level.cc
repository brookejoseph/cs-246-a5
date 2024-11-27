#include "level.h"

Level::Level(): position{0} {}

Level::~Level() {}

void Level::setRandom(bool isRandom) { random = isRandom; }

void Level::setSequence(std::vector<char> seq) { sequence = seq; position = 0; }

void Level::setPosition(int n) { position = n; }
