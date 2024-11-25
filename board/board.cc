#include <vector>
#include <tuple>
#include <iostream>
#include <ostream>
#include "block/block.h"
#include "cell/cell.h"
#include "level/level.h"
#include "observer/subject.h"

Board::Board() {};

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
    for (auto &t : currentblock->getCoord())
    {
        auto &[p1, p2, p3, p4] = t;
        if (((p1.first > dimX) || (p2.first > dimX) || (p3.first > dimX) || (p4.first > dimX)) ||
            ((p1.first < 0) || (p2.first < 0) || (p3.first < 0) || (p4.first < 0)))
        {
            return false;
        }
        if (((p1.second > dimY) || (p2.second > dimY) || (p3.second > dimY) || (p4.second > dimY)))
        {
            return false;
        }
        if ((grid[p1.first][p1.second] != ' ') ||
            (grid[p2.first][p2.second] != ' ') ||
            (grid[p3.first][p3.second] != ' ') ||
            (grid[p4.first][p4.second] != ' '))
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
        auto &[p1, p2, p3, p4] = t;
        char letter = thisBlock.getType();
        setValue(p1.first, p1.second, letter);
        setValue(p2.first, p2.second, letter);
        setValue(p3.first, p3.second, letter);
        setValue(p4.first, p4.second, letter);
    };
};

void Board::drop()
{
    for (auto &t : currentBlock->getCoord())
    {
        auto &[p1, p2, p3, p4] = t;
        // negation of the condition is required
        while ((getValue(p1.first, p1.second) != ' ') ||
               (getValue(p2.first, p2.second) != ' ') ||
               (getValue(p3.first, p3.second) != ' ') ||
               (getValue(p4.first, p4.second) != ' '))
        {
            ++p1.second;
            ++p2.second;
            ++p3.second;
            ++p4.second;
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
