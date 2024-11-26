#include <vector>
#include <tuple>
#include <iostream>
#include <ostream>
#include "../block/block.h"
#include "../cell/cell.h"
#include "../level/level.h"
#include "../observer/subject.h"

Board::Board() noexcept {};

void Board::setValue(char newValue, int x, int y)
{
    grid[x][y] = newValue;
};

char Board::getValue(int x, int y)
{
    return grid[x][y];
};

bool Board::isValidMove()
{
    // for loop is unnecessary -- can be removed later, because we are only moving one block at a time
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
};

void Board::right(int amount)
{
    for (int i = 0; i < amount; i++)
    {
        currentBlock->right();
    };
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
};

void Board::cw(int amount)
{
    for (int i = 0; i < amount; i++)
    {
        currentBlock->rotatecw();
    };
};

// LOGIC NEEDS TO BE FIXED HERE
// um I just need someone to here to help me make sure that we're putting in the proper letters for all the values
void Board::addCell(Block &thisBlock)
{
    for (auto &t : thisBlock.getCoord())
    {
        char letter = thisBlock.getType();
        setValue(t.first, t.second, letter);
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

void Board::restart()
{
    grid.clear();
};

int Board::findScore()
{
    return score;
};
