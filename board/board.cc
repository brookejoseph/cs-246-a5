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

void Board::setCurrentBlock(std::shared_ptr<Block> block)
{
    currentBlock = block;
};

void Board::setNextBlock(std::shared_ptr<Block> block)
{
    nextBlock = block;
};

void Board::convertNextToCurrent()
{
    currentBlock = nextBlock;
};

int Board::getDimX()
{
    return dimX;
}

int Board::getDimY()
{
    return dimY;
}

Board::Board(int x, int y) noexcept: grid(x, std::vector<char>(y, ' ')), level(0), score(0), highScore(0), numLinesCleared(0), noClearCount(0) {

}

char Board::getValue(int x, int y) { return grid->getValue(x, y); }

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
        if (grid->getValue(t.first, t.second) != ' ')
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
    currentLevelPtr = levelList[level + amount];
    level += amount;
};

void Board::levelDown(int amount)
{
    currentLevelPtr = levelList[level - amount];
    level -= amount;
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

void Board::updateClearLines()
{
    cout << "within the updateClearlines" << endl;
    int linesCleared = 0;
    //cout << "*" << grid[12][10];
    bool cleared = true;
    while (cleared) {
        cleared = false;
        ++linesCleared;
        ++numLinesCleared;
        for (int row = 17; row > 0; --row) {
            vector<char> selectedRow;
            for (int col = 0; col < 11; ++col) {
                selectedRow.push_back(grid[col][row]);
            }

            if (all_of(selectedRow)) {
                cleared = true;
                for (int col = 0; col < 11; ++col) {
                    grid->getValue(col, row) = ' ';  
                }

                for (int row2 = row; row2 > 0; --row2) {
                    for (int col = 0; col < 11; ++col) {
                        grid[col][row2] = grid[col][row2 - 1];
                    }
                }

                for (int col = 0; col < 11; ++col) {
                    grid[col][0] = ' ';
                }

            }

        }

    }

}

void Board::setSequence(const std::vector<char> &seq) {
    for (auto lvl: levelList) {
        lvl->setSequence(seq);
    }
}


std::shared_ptr<Level> Board::getLevelPtr() const
{
    return currentLevelPtr;
}

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

std::shared_ptr<Block> Board::getNextBlock() const {
    return nextBlock;
}
