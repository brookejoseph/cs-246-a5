#include "../textdisplay/textdisplay.h"
#include "../observer/subject.h"
#include "../observer/observer.h"
#include <iostream>

TextDisplay::TextDisplay(std::shared_ptr<Board> player1, std::shared_ptr<Board> player2, int dimX, int dimY) : player1{player1}, player2{player2}, dimX{dimX}, dimY{dimY}
{
    player1->attach(this);
    player2->attach(this);
}

TextDisplay::~TextDisplay()
{
    player1->detach(this);
    player2->detach(this);
}

int TextDisplay::numDigits(int x) const
{
    int digits = 0;
    while (x)
    {
        x /= 10;
        ++digits;
    }
    return digits;
}

void TextDisplay::printHeader(const string &text) const
{
    std::cout << text << ":";
    for (int i = 1; i < dimX - text.length() + space; ++i)
    {
        std::cout << " ";
    }
    std::cout << text << ":\n";
}

void TextDisplay::printValues(const string &text, int value1, int value2) const
{
    std::cout << text << ":";
    for (int i = 1; i < dimX - text.length() - numDigits(value1); ++i)
    {
        std::cout << " ";
    }
    std::cout << value1;
    for (int i = 0; i < space; ++i)
    {
        std::cout << " ";
    }
    std::cout << text << ":";
    for (int i = 1; i < dimX - text.length() - numDigits(value2); ++i)
    {
        std::cout << " ";
    }
    std::cout << value2 << "\n";
}

void TextDisplay::printDashes() const
{
    for (int i = 0; i < dimX; ++i)
    {
        std::cout << "-";
    }
    for (int i = 0; i < space; ++i)
    {
        std::cout << " ";
    }
    for (int i = 0; i < dimX; ++i)
    {
        std::cout << "-";
    }
    std::cout << "\n";
}

void TextDisplay::printBoards() const
{
    for (int i = 0; i < dimY; ++i)
    {
        for (int j = 0; j < dimX; ++j)
        {
            std::cout << player1->getState(i, j);
        }

        for (int k = 0; k < space; ++k)
        {
            std::cout << " ";
        }

        for (int j = 0; j < dimX; ++j)
        {
            std::cout << player2->getState(i, j) << '\n';
        }
    }
}

void TextDisplay::printNextBlocks() const
{
    // need to figure out logic to print out next blocks
    // likely need some sort of getNextBlock method for Board

    // std::shared_ptr<Block> nextBlock1 = player1->getNextBlock();
    // std::shared_ptr<Block> nextBlock2 = player2->getNextBlock();
}

void TextDisplay::notify()
{
    printValues("Level", player1->getLevel(), player2->getLevel());
    printValues("Score", player1->findScore(), player2->findScore());
    printDashes();
    printBoards();
    printDashes();
    printHeaders("Next");
    printNextBlocks();
}