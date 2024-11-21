#include "textdisplay.h"

TextDisplay::TextDisplay(std::shared_ptr<Board> subject): subject{subject} {}

TextDisplay::~TextDisplay() {}

void TextDisplay::printBoardHeader() const {

}

void TextDisplay::printBoardGrid() const {

}

void TextDisplay::printNextBlock() const {

}

void TextDisplay::notify() {
    printBoardHeader();
    printBoardGrid();
    printNextBlock();
}
