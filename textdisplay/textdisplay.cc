#include "textdisplay.h"
#include <iostream>
#include <string>
#include <tuple>

// HELPER FUNCTIONS

int numDigits(int x) {
    int digits = 0;
    while (x) { x /= 10; ++digits; }
    return digits;
}

void printChar(char c, int n) {
    for (int i = 0; i < n; ++i) { std::cout << c; }
}

void printHeader(const std::string &text, int space) {
    std::cout << text << ":";
    printChar(' ', space);
}

void printValue(const std::string &text, int value, int space) {
    std::cout << text << ":";
    printChar(' ', space - numDigits(value) - 1);
    std::cout << value;
}

// CLASS IMPLEMENTATIONS

TextDisplay::TextDisplay(std::shared_ptr<GameEngine> game, int dimX, int dimY): 
    game{game}, dimX{dimX}, dimY{dimY} {}

TextDisplay::~TextDisplay() {}

std::shared_ptr<GameEngine> TextDisplay::getGame() const {
    return game.lock();
}

void TextDisplay::printHeaders(const std::string &text) const {
    printHeader(text, dimX - text.length() - 1);
    printChar(' ', sep);
    printHeader(text, 0);
    std::cout << '\n';
}

void TextDisplay::printValues(const std::string &text, int value1, int value2) const {
    printValue(text, value1, dimX - text.length() - 1);
    printChar(' ', sep);
    printValue(text, value2, dimX - text.length() - 1);
    std::cout << '\n';
}

void TextDisplay::printDashes() const {
    printChar('-', dimX);
    printChar(' ', sep);
    printChar('-', dimX);
    std::cout << '\n';
}

void TextDisplay::printBoards() const {
    for (int j = 0; j < dimY; ++j) {
        for (int i = 0; i < dimX; ++i) {
            std::cout << getGame()->getPlayer1()->getValue(i, j);
        }
        printChar(' ', sep);
        for (int i = 0; i < dimX; ++i) {
            std::cout << getGame()->getPlayer2()->getValue(i, j);
        }
        std::cout << '\n';
    }
}

void TextDisplay::printNextBlocks() const {
    std::shared_ptr<Block> player1NextBlock = getGame()->getPlayer1()->getNextBlock();
    std::shared_ptr<Block> player2NextBlock = getGame()->getPlayer1()->getNextBlock();

    for (int j = 0; j < 2; ++j) {
        for (int i = 0; i < 4; ++i) {
            std::cout << player1NextBlock->getChar(i, j);
        }

        printChar(' ', dimX + sep - 4);

        for (int i = 0; i < 1; ++i) {
            std::cout << player2NextBlock->getChar(i, j);
        }

        std::cout << '\n';
    }
}

void TextDisplay::notify() {
    //printValue("High Score", getGame()->getHighScore());
    printValues("Level", getGame()->getPlayer1()->getLevel(), getGame()->getPlayer2()->getLevel());
    printValues("Score", getGame()->getPlayer1()->findScore(), getGame()->getPlayer2()->findScore());
    printDashes();
    printBoards();
    printDashes();
    printHeaders("Next");
    printNextBlocks();
}


