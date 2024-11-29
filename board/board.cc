#include <vector>
#include <tuple>
#include <iostream>
#include <ostream>
#include "../block/block.h"
#include "../level/level.h"
#include "../level/level0.h"
#include "../level/level1.h"
#include "../level/level2.h"
#include "../level/level3.h"
#include "../level/level4.h"

#include <map>

// helpers
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

// method implementations
Board::Board(int x, int y) noexcept
    : dimX(x), dimY(y), grid(x, std::vector<char>(y, ' ')), level(0), noClearCount(0), numLinesCleared(0) {}

void Board::setLevel(int lvl)
{
    if (lvl < 0)
    {
        level = 0;
    }
    else if (lvl > 4)
    {
        level = 4;
    }
    else
    {
        level = lvl;
    }
}

int Board::getLevel() const
{
    return level;
}

void Board::setRandom(bool isRandom)
{
    parameter[level]->setRandom(isRandom);
}

int Board::checkClearLine()
{
    int temp = numLinesCleared;
    numLinesCleared = 0;
    return temp;
}

void Board::updateClearLines()
{
    int linesCleared = 0;
    bool cleared = true;
    while (cleared)
    {
        cleared = false;

        for (int row = dimY - 1; row > 0; --row)
        {
            vector<char> selectedRow;
            for (int col = 0; col < dimX; ++col)
            {
                selectedRow.push_back(grid[col][row]);
            }
            if (std::all_of(selectedRow.begin(), selectedRow.end(), [](char c)
                            { return c != ' '; }))
            {
                cleared = true;
                ++linesCleared;
                ++numLinesCleared;
                removeIncr(row);
                for (int col = 0; col < dimX; ++col)
                {
                    grid[col][row] = ' ';
                }

                for (int row2 = row; row2 > 0; --row2)
                {
                    for (int col = 0; col < dimX; ++col)
                    {
                        grid[col][row2] = grid[col][row2 - 1];
                    }
                }

                for (int col = 0; col < dimX; ++col)
                {
                    grid[col][0] = ' ';
                }
            }
        }
    }
}

void Board::removeIncr(int row)
{
    for (auto it = addedBlocks.begin(); it != addedBlocks.end(); it++)
    {
        int counter = 0;
        for (auto &coord : *it)
        {
            if (counter > 4)
            {
                break;
            }
            if (coord.second == row)
            {
                coord.first = -1;
                coord.second = -1;
            }
            if (coord.second <= row - 1 && coord.second >= 0)
            {
                coord.second++;
            }

            counter++;
        }
    }

    for (auto it = addedBlocks.begin(); it != addedBlocks.end();)
    {
        if (((*it).at(0).first == -1) && ((*it).at(0).second == -1) && (((*it).at(1).first == -1) && ((*it).at(1).second == -1)) && (((*it).at(2).first == -1) && ((*it).at(2).second == -1)) && (((*it).at(3).first == -1) && ((*it).at(3).second == -1)))
        {
            noBlocksCleared += 1;
            temp_score += ((*it).at(4).first + 1) * ((*it).at(4).first + 1);

            it = addedBlocks.erase(it);
        }
        else
        {
            it++;
        }
    }
}

void Board::left(int amount)
{
    for (int i = 0; i < amount; i++)
    {
        currentBlock->left();
    };
    if (shouldDrop)
    {
        drop();
        shouldDrop = false;
    }
};

void Board::right(int amount)
{
    for (int i = 0; i < amount; i++)
    {
        currentBlock->right();
    };
    if (shouldDrop)
    {
        drop();
        shouldDrop = false;
    }
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
    if (shouldDrop)
    {
        drop();
        shouldDrop = false;
    }
};

void Board::cw(int amount)
{
    for (int i = 0; i < amount; i++)
    {
        currentBlock->rotatecw();
    };
    if (shouldDrop)
    {
        drop();
        shouldDrop = false;
    }
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
    addBlockToVec(currentBlock);
    this->updateClearLines();

    setHeavy(false);
    setBlind(false);

    setCurrentBlock(nextBlock);
    getNextBlock();
}

void Board::restart()
{
    for (auto &row : grid)
    {
        std::fill(row.begin(), row.end(), ' ');
    }
}

bool Board::gameOver()
{
    auto coord = nextBlock->getCoord();
    if (!(grid[coord.at(0).first][coord.at(0).second] == ' ') ||
        !(grid[coord.at(1).first][coord.at(1).second] == ' ') ||
        !(grid[coord.at(2).first][coord.at(2).second] == ' ') ||
        !(grid[coord.at(3).first][coord.at(3).second] == ' '))
    {
        return true;
    };

    return false;
}

void Board::addCell(Block &thisBlock)
{
    for (auto &t : thisBlock.getCoord())
    {
        char letter = thisBlock.getType();
        setValue(letter, t.first, t.second);
    };
};

int Board::checkClearBlock()
{
    int temp = temp_score;
    temp_score = 0;
    return temp;
}

void Board::setDimX(int x)
{
    dimX = x;
}

void Board::setDimY(int y)
{
    dimY = y;
}

void Board::setHeavy(bool val)
{
    heavy = val;
}

bool Board::getHeavy()
{
    return heavy;
}

void Board::setBlind(bool val)
{
    blind = val;
}

bool Board::getBlind()
{
    return blind;
}

void Board::setForce(bool val)
{
    force = val;
}
bool Board::getForce()
{
    return force;
};

void Board::getNextBlock()
{
    nextBlock = std::shared_ptr<Block>(parameter[level]->createBlock());
};

char Board::getNextBlockType() const { return nextBlock->getType(); }

char Board::getCurrentBlockType() const { return currentBlock->getType(); }

void Board::initBlocks()
{
    getNextBlock();
    setCurrentBlock(nextBlock);
    getNextBlock();
}

void Board::setValue(char newValue, int x, int y)
{
    if (x < 0 || x >= dimX || y < 0 || y >= dimY)
    {
        throw std::out_of_range("Coordinates out of bounds");
    }
    grid[x][y] = newValue;
};

char Board::getChar(int x, int y) const
{
    return grid[x][y];
};

void Board::addBlockToVec(const std::shared_ptr<Block> &block)
{
    auto temp = block->getCoord();
    vector<pair<int, int>> new_vec;
    int level = block->getLevel();
    for (auto i : temp)
    {
        new_vec.emplace_back(i);
    }
    new_vec.emplace_back(level, 0);
    addedBlocks.emplace_back(new_vec);
}

void Board::setLvlSequence(const std::vector<char> &seq)
{
    for (int i = 0; i <= 4; ++i)
    {
        parameter[i]->setSequence(seq);
    }
}

void Board::setCurrentBlock(const std::shared_ptr<Block> &block)
{
    currentBlock = block;
}

std::vector<std::pair<int, int>> Board::getCurrentBlockCoord() const
{
    return currentBlock->getCoord();
}

std::vector<std::vector<char>> Board::getGrid()
{
    return grid;
}