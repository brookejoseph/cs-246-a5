#include "textdisplay.h"
#include <iostream>
#include <cmath>

TextDisplay::TextDisplay(std::shared_ptr<Board> player1, std::shared_ptr<Board> player2): 
    player1{player1}, player2{player2} {}

TextDisplay::~TextDisplay() {}

void TextDisplay::printBoardHeaders() const {
    std::cout << "Hi Score: " << player1->HiScore() > player2->HiScore() ? player1->HiScore() : player2->HiScore << '\n';
    std::cout << "Level:    " << player1->getLevel() << "       ";
    std::cout << "Level:    " << player2->getLevel() << '\n';

    std::cout << "Score:    " << player1->findScore() << "       ";
    std::cout << "Score:    " << player2->findScore() << "       ";

    std::cout << "-----------       -----------\n";
}

void TextDisplay::printBoards() const {
    // dont wanna use magic numbers so we need to define col/rows
    // somewhere, could maybe be a getter for Board class
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            std::cout << player1->getState(i, j);
        }

        std::cout << "       ";

        for (int j = 0; j < cols; ++j) {
            std::cout << player2->getState(i, j) << '\n';
        }
    }
}

void TextDisplay::printNextBlocks() const {
    std::cout << "-----------       -----------\n";
    std::cout << "Next:             Next:\n";
    // need to figure out logic to print out next blocks
    // likely need some sort of getNextBlock method for Board
}

void TextDisplay::notify() {
    printBoardHeaders();
    printBoards();
    printNextBlocks();
}