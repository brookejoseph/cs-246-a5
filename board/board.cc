#include <vector>
#include <tuple>
#include <iostream>
#include <ostream>
#include "../block/block.h"
#include "../cell/cell.h"
#include "../level/level.h"

#include <map>

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

Board::Board(int x, int y) noexcept : dimX(x), dimY(y), grid(x, std::vector<char>(y, ' ')), level(0), score(0), highScore(0), numLinesCleared(0), currentLevel(0), noClearCount(0) {}

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

void Board::levelUp()
{
    static std::map<int, Level *> levelMap = {
        {0, new Level0()}, // to fix
        {1, new Level1()},
        {2, new Level2()},
        {3, new Level3()},  // to fix
        {4, new Level4()}}; // to fix

    if (levelMap.find(currentLevel) != levelMap.end())
    {
        levelsPtr = levelMap[++currentLevel];
        ++currentLevel;
    };
};

void Board::levelDown()
{
    static std::map<int, Level *> levelMap = {
        {0, new Level0()}, // to fix
        {1, new Level1()},
        {2, new Level2()},
        {3, new Level3()},  // to fix
        {4, new Level4()}}; // to fix

    if (levelMap.find(currentLevel) != levelMap.end())
    {
        levelsPtr = levelMap[--currentLevel];
        --currentLevel;
    };
};

void Board::drop()
{
    auto coords = currentBlock->getCoord();

    while (((coords.at(0).second != dimY - 1) && (coords.at(1).second != dimY - 1) && (coords.at(2).second != dimY - 1) && (coords.at(3).second != dimY - 1)) &&
           ((grid[coords.at(0).first][coords.at(0).second + 1] == ' ') && (grid[coords.at(1).first][coords.at(1).second + 1] == ' ') && (grid[coords.at(2).first][coords.at(2).second + 1] == ' ') && (grid[coords.at(3).first][coords.at(3).second + 1] == ' ')))
    {
        currentBlock->down();
        coords = currentBlock->getCoord();
    }
    this->updateClearLines();

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

int Board::checkClearLine()
{
    return numLinesCleared;
}

void Board::updateClearLines()
{
    cout << "within the updateClearlines";
    int linesCleared = 0;

    for (int row = grid.size() - 1; row >= 0; --row)
    {
        if (all_of(grid[row].begin(), grid[row].end(), [](char c)
                   { return c != ' '; }))
        {
            ++linesCleared;
            ++numLinesCleared;

            for (int r = row; r > 0; --r)
            {
                grid[r] = grid[r - 1];
            }

            grid[0] = vector<char>(grid[0].size(), ' ');

            ++row;
        }
    }
}

int Board::getCurrentLevelVal()
{
    return currentLevel;
};

Level *Board::getCurrentLevelPtr()
{
    return levelsPtr;
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