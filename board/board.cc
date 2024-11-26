#include <vector>
#include <tuple>
#include <iostream>
#include <ostream>
#include "../block/block.h"
#include "../cell/cell.h"
#include "../level/level.h"

void Board::setCurrentBlock(Block *block)
{
    currentBlock = block;
};

void Board::setDimX(int x)
{
    dimX = x;
}

void Board::setDimY(int y)
{
    dimY = y;
}

Board::Board(int x, int y) noexcept : dimX(x), dimY(y), grid(x, std::vector<char>(y, ' ')), level(0), score(0), highScore(0), noClearCount(0) {}

void Board::setValue(char newValue, int x, int y)
{
    grid[x][y] = newValue;
};

/*
    if (x < 0 || x >= dimX || y < 0 || y >= dimY)
    {
        throw std::out_of_range("Coordinates out of bounds");
    }
*/

char Board::getValue(int x, int y)
{
    return grid[x][y];
};

bool Board::isValidMove()
{
    for (auto &t : currentBlock->getCoord())
    {
        if ((t.first > dimX) || (t.first < 0))
        {
            return false;
        }
        if (t.second > dimY)
        {
            return false;
        }
        if (grid[t.first][t.second] != ' ')
        {
            return false;
        }
    }
    return true;
}

void Board::left(int amount)
{
    for (int i = 0; i < amount; i++)
    {
        currentBlock->left();
    };
    addCell(*currentBlock);
};

void Board::right(int amount)
{
    for (int i = 0; i < amount; i++)
    {
        currentBlock->right();
    };
    addCell(*currentBlock);
};

void Board::down(int amount)
{
    for (int i = 0; i < amount; i++)
    {
        currentBlock->down();
    };
};

void Board::ccw(int amount)
{
    for (int i = 0; i < amount; i++)
    {
        currentBlock->rotateccw();
    };
    addCell(*currentBlock);
};

void Board::cw(int amount)
{
    for (int i = 0; i < amount; i++)
    {
        currentBlock->rotatecw();
    };
    addCell(*currentBlock);
};

// LOGIC NEEDS TO BE FIXED HERE
// um I just need someone to here to help me make sure that we're putting in the proper letters for all the values
void Board::addCell(Block &thisBlock)
{
    for (auto &t : thisBlock.getCoord())
    {
        char letter = thisBlock.getType();
        setValue(letter, t.first, t.second);
    };
};

void Board::drop()
{
    for (auto &t : currentBlock->getCoord())
    {
        // negation of the condition is required
        while (getValue(t.first, t.second) != ' ')
        {
            ++t.second;
        };
    };
    addCell(*currentBlock);
};

/*
void Board::drop()
{
    while (isValidMove())
    {
        currentBlock->down(); // Move the block down by one unit
    }
    addCell(*currentBlock); // Add the block to the grid
}
*/

void Board::restart()
{
    grid.clear();
};

int Board::findScore()
{
    return score;
};
