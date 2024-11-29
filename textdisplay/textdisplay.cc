#include "textdisplay.h"
#include <iostream>
#include <string>
#include <tuple>
#include <map>

std::map<char, std::pair<std::string, std::string>> blockConfig = {{'I', {"    ", "IIII"}},
                                                                   {'J', {"J   ", "JJJ "}},
                                                                   {'L', {"   L", " LLL"}},
                                                                   {'O', {"OO  ", "OO  "}},
                                                                   {'S', {"  SS", "SS  "}},
                                                                   {'Z', {"ZZ  ", "  ZZ"}},
                                                                   {'T', {"TTT ", " T  "}}};

// HELPER FUNCTIONS

int numDigits(int x) {
    if (x == 0) return 1;
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
    // dynamically print current block position
    std::vector<std::pair<int, int>> currentCoord = getGame()->currentBoard()->getCurrentBlockCoord();
    char currentBlockType = getGame()->currentBoard()->getNextBlockType();
    int currentPlayer = getGame()->grabPlayer();

    for (int j = 0; j < dimY; ++j) {
        for (int i = 0; i < dimX; ++i) {
            if (currentPlayer == 1 && std::find(currentCoord.begin(), currentCoord.end(), std::make_pair(i, j)) != currentCoord.end()) {
                std::cout << currentBlockType;
            } else {
                std::cout << getGame()->getPlayer1()->getChar(i, j);
            }
        }
        printChar(' ', sep);
        for (int i = 0; i < dimX; ++i) {
            if (currentPlayer == 2 && std::find(currentCoord.begin(), currentCoord.end(), std::make_pair(i, j)) != currentCoord.end()) {
                std::cout << currentBlockType;
            } else {
                std::cout << getGame()->getPlayer2()->getChar(i, j);
            }
        }
        std::cout << '\n';
    }
}

void TextDisplay::printNextBlocks() const {
    char nextBlock1 = getGame()->getPlayer1()->getNextBlockType();
    char nextBlock2 = getGame()->getPlayer2()->getNextBlockType();
    std::cout << blockConfig[nextBlock1].first;
    printChar(' ', dimX + sep - 4);
    std::cout << blockConfig[nextBlock2].first;
    std::cout << '\n';
    std::cout << blockConfig[nextBlock1].second;
    printChar(' ', dimX + sep - 4);
    std::cout << blockConfig[nextBlock2].second;
    std::cout << '\n';
}

void TextDisplay::notify() {
    //printValue("High Score", getGame()->getHighScore());
    printValues("Level", getGame()->getPlayer1()->getLevel(), getGame()->getPlayer2()->getLevel());
    printValues("Score", getGame()->getPlayer1Score(), getGame()->getPlayer2Score());
    printDashes();
    printBoards();
    printDashes();
    printHeaders("Next");
    printNextBlocks();
    std::cout << '\n';
}


