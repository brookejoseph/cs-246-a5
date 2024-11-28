#include "level.h"

Level::Level() noexcept : position{0} {}

Level::~Level() = default;

void Level::setRandom(bool isRandom) { random = isRandom; }

void Level::setSequence(std::vector<char> seq)
{
    sequence = seq;
    position = 0;
}

void Level::setPosition(int n) { position = n; }
