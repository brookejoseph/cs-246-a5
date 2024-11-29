#include <vector>
#include <tuple>
#include <iostream>
#include <ostream>
#include "../block/block.h"
// #include "../cell/cell.h"
#include "../level/level.h"
#include "../level/level0.h"
#include "../level/level1.h"
#include "../level/level2.h"
#include "../level/level3.h"
#include "../level/level4.h"

#include <map>

Board::Board(int x, int y) noexcept
    : dimX(x), dimY(y), grid(x, std::vector<char>(y, ' ')), level(0), numLinesCleared(0), noClearCount(0) {}

void Board::setCurrentBlock(const std::shared_ptr<Block> &block)
{
    currentBlock = block;
}

void Board::getNextBlock()
{
    nextBlock = std::shared_ptr<Block>(parameter[level]->createBlock());
};

void Board::initBlocks()
{
    getNextBlock();
    setCurrentBlock(nextBlock);
    getNextBlock();
}

void Board::setDimX(int x)
{
    dimX = x;
}

void Board::setDimY(int y)
{
    dimY = y;
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

std::vector<std::vector<char>> Board::getGrid()
{
    return grid;
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
    ++level;
};

void Board::levelDown()
{
    --level;
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

    // setCurrentBlock(nextBlock);
    // getNextBlock();
}

void Board::restart()
{
    grid.clear();
};

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

int Board::checkClearBlock()
{
    int temp = noBlocksCleared;
    noBlocksCleared = 0;
    return temp;
}

bool all_of(vector<char> row)
{
    for (auto it = row.begin(); it != row.end(); it++)
    {
        cout << *it;
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
    // cout << "*" << grid[12][10];
    bool cleared = true;
    while (cleared)
    {
        cleared = false;

        for (int row = 17; row > 0; --row)
        {
            vector<char> selectedRow;
            for (int col = 0; col < 11; ++col)
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

void Board::setLvlSequence(const std::vector<char> &seq)
{
    for (int i = 0; i <= 4; ++i)
    {
        parameter[i]->setSequence(seq);
    }
}

void Board::addBlockToVec(const std::shared_ptr<Block> &block)
{
    addedBlocks.emplace_back(block);
}

char Board::getNextBlockType() const { return nextBlock->getType(); }

char Board::getCurrentBlockType() const { return currentBlock->getType(); }

// addedBlocks = [[(-1,-1), (4,4), (5,6), (7,8)], 
//                 [(3,4), (4,5), (5,6), (7,8)]]
void Board::removeIncr(int row)
{
    for (auto it = addedBlocks.begin(); it != addedBlocks.end();)
    {
        Block *block = it->get();

        auto coords = block->getCoord();

        int cellRemoved = 0;
        for (auto &coord : coords)
        {
            if (coord.second == row)
            {
                coord.second = -1;
                coord.first = -1;
                cout << "cond 1" << endl;
            }
            if (coord.second <= row - 1)
            {
                coord.second += 1;
                cout << "cond 2" << endl;
            }
            if (coord.first == -1 && coord.second == -1 ) {
                cellRemoved++;
                cout << "cond 3" << endl;
                cout << "total cells removed cond 3: " << cellRemoved << endl;
            }
            cout << "total cells removed: " << cellRemoved << endl;

        }
        //auto temp = it;
        if (cellRemoved == 4) {
            cout << "block removed" << endl;
            noBlocksCleared++;
            addedBlocks.erase(it);
            it = addedBlocks.erase(it);
        }
        ++it;
    }
}

void Board::blockRemoved()
{
    int clearedCount = 0;
    for (int x = 0; x < dimX; ++x)
    {
        for (int y = 0; y < dimY; ++y)
        {
            if (grid[x][y] == ' ')
            {
                ++clearedCount;
            }
        }
    }
    noBlocksCleared += clearedCount;
}

std::vector<std::pair<int, int>> Board::getCurrentBlockCoord() const
{
    return currentBlock->getCoord();
}
