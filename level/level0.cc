#include "level0.h"
#include <fstream>
#include <string>

int Level0::getLevel() const { return level; }

Block *Level0::createBlock() {

}

Level0::Level0(string sequenceFile): sequenceFile{sequenceFile}, moves{sequenceFile} {}
