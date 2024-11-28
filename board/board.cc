#include <vector>
#include <tuple>
#include <iostream>
#include <ostream>
#include "../block/block.h"
#include "../cell/cell.h"
#include "../level/level.h"
#include "../level/level0.h"
#include "../level/level1.h"
#include "../level/level2.h"
#include "../level/level3.h"
#include "../level/level4.h"

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

void Board::levelUp(int amount)
{
    currentPtr = parameter[currentLevel + amount];
    currentLevel += amount;
};

void Board::levelDown(int amount)
{
    currentPtr = parameter[currentLevel - amount];
    currentLevel -= amount;
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
    addCell(*currentBlock);
    this->updateClearLines();
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

bool all_of(vector<char> row)
{
    for (auto it = row.begin(); it != row.end(); it++)
    {
        if (*it == ' ')
        {
            return false;
        }
    }
    return true;
}

void Board::updateClearLines()
{
    int linesCleared = 0;
    bool cleared = true;
    while (cleared)
    {
        cleared = false;
        ++linesCleared;
        ++numLinesCleared;
        for (int row = 17; row > 0; --row)
        {
            vector<char> selectedRow;
            for (int col = 0; col < 11; ++col)
            {
                selectedRow.push_back(grid[col][row]);
            }

            if (all_of(selectedRow))
            {
                cleared = true;
                removeIncr(row);
                for (int col = 0; col < 11; ++col)
                {
                    grid[col][row] = ' ';
                }

                for (int row2 = row; row2 > 0; --row2)
                {
                    for (int col = 0; col < 11; ++col)
                    {
                        grid[col][row2] = grid[col][row2 - 1];
                    }
                }

                for (int col = 0; col < 11; ++col)
                {
                    grid[col][0] = ' ';
                }
            }
        }
    }
}

bool Board::blockRemoved()
{
    int acc = 0;
    for (auto k : addedBlocks)
    {
        for (auto i : k->getCoord())
        {
            if ((i.second == -1) && (i.first == -1))
            {
                ++acc;
            };
        }
        if (acc == 4)
        {
            return true;
        };
    };
    return false;
};

void Board::removeIncr(int row)
{
    for (auto i : addedBlocks)
    {
        for (auto k : i->getCoord())
        {
            if (k.second == row)
            {
                k.first = -1;
                k.second = -1;
            };
            if (k.second == row - 1)
            {
                ++k.second;
            };
        };
    };
}

void Board::addBlockToVec(Block *block)
{
    addedBlocks.emplace_back(block);
};

// for use in game engine
// void setSequence(const std::vector<char> &seq) {
//    for (auto lvl: levelList) {
//        lvl->setSequence(seq);
//    }
//}

int Board::getCurrentLevelVal()
{
    cout << "grabbing the current val in board" << currentLevel << endl;
    return currentLevel;
};

Level *Board::getCurrentLevelPtr()
{
    return currentPtr;
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
