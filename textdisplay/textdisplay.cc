#include "textdisplay.h"
#include <iostream>
#include <string>

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
    printChar(' ', space - numDigits(value));
    std::cout << value;
}

// CLASS IMPLEMENTATIONS
TextDisplay::TextDisplay(std::shared_ptr<Board> player1, std::shared_ptr<Board> player2, int dimX, int dimY): 
    player1{player1}, player2{player2}, dimX{dimX}, dimY{dimY} {
    player1->attach(this);
    player2->attach(this);
}

TextDisplay::~TextDisplay() {
    player1->detach(this);
    player2->detach(this);
}

void TextDisplay::printHeaders(const std::string &text) const {
    printHeader(text, dimX - text.length());
    printChar(' ', sep);
    printHeader(text, 0);
    std::cout << '\n';
}

void TextDisplay::printValues(const std::string &text, int value1, int value2) const {
    printValue(text, value1, dimX - text.length());
    printChar(' ', sep);
    printValue(text, value2, dimX - text.length());
    std::cout << '\n';
}

void TextDisplay::printDashes() const {
    printChar('-', dimX);
    printChar(' ', sep);
    printChar('-', dimX);
    std::cout << '\n';
}

void TextDisplay::printBoards() const {
    for (int i = 0; i < dimY; ++i) {
        for (int j = 0; j < dimX; ++j) {
            std::cout << player1->getValue(i, j);
        }
        printChar(' ', sep);
        for (int j = 0; j < dimX; ++j) {
            std::cout << player2->getValue(i, j) << '\n';
        }
    }
}

void TextDisplay::printNextBlocks() const {
    // need to figure out logic to print out next blocks
    // likely need some sort of getNextBlock method for Board

    //std::shared_ptr<Block> nextBlock1 = player1->getNextBlock();
    //std::shared_ptr<Block> nextBlock2 = player2->getNextBlock();
}

void TextDisplay::notify() {
    printValues("Level", player1->getLevel(), player2->getLevel());
    printValues("Score", player1->findScore(), player2->findScore());
    printDashes();
    printBoards();
    printDashes();
    printHeaders("Next");
    printNextBlocks();
}