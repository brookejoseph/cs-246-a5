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

void Board::setNextBlock(Block *block)
{
    nextBlock = block;
};

void Board::convertNextToCurrent()
{
    currentBlock = nextBlock;
    nextBlock = nullptr;
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
    if (x < 0 || x >= dimX || y < 0 || y >= dimY)
    {
        throw std::out_of_range("Coordinates out of bounds");
    }
    grid[x][y] = newValue;
};

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

void Board::addCell(Block &thisBlock)
{
    for (auto &t : thisBlock.getCoord())
    {
        char letter = thisBlock.getType();
        setValue(letter, t.first, t.second);
    };
};

/*
void Board::drop()
{

    for (auto &t : currentBlock->getCoord())
    {
        cout << "current Block's get corrd";
        cout << t.first << " ";
        cout << t.second << endl;
        while (t.second != dimY)
        {
            ++t.second;
        };
        cout << "within the drop method ";
        cout << t.second << endl;
    };

    addCell(*currentBlock);
};


*/
void Board::drop()
{
    auto coords = currentBlock->getCoord();

    while ((coords.at(0).second != dimY) && (coords.at(1).second != dimY) && (coords.at(2).second != dimY) && (coords.at(3).second != dimY))
    {
        ++coords.at(0).second;
        ++coords.at(1).second;
        ++coords.at(2).second;
        ++coords.at(3).second;
    }

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

int Board::getLevel() const
{
    return level;
}