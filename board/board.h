
#ifndef BOARD_H
#define BOARD_H
#include <vector>
#include <tuple>
#include <iostream>
#include <ostream>
#include <memory>

#include "../level/level.h"
#include "../level/level0.h"
#include "../level/level1.h"
#include "../level/level2.h"
#include "../level/level3.h"
#include "../level/level4.h"

#include "../observer/subject.h"

class Block; // forward declaration

class Board
{
private:
    std::vector<std::vector<char>> grid;

    Block *currentBlock;
    Block *nextBlock;

    int noClearCount;
    

protected:
    int dimX = 11;
    int dimY = 18;
    int noBlocksCleared = 0;
    int numLinesCleared;

    std::vector<Block *> addedBlocks;

    int level;
    Level *parameter[5] = {new Level0(),
                           new Level1(),
                           new Level2(),
                           new Level3(),
                           new Level4()};

public:
    Board(int x, int y) noexcept;
    ~Board() = default;

    void levelUp();
    void levelDown();
    int getLevel() const;

    int checkClearLine();
    void updateClearLines();

    bool isValidMove();

    void addBlockToVec(Block *blockVal);
    void removeIncr(int row);
    void blockRemoved();

    void left(int amount);  // done
    void right(int amount); // done
    void down(int amount);  // done
    void cw(int amount);    // done
    void ccw(int amount);   // done
    void drop();            // done

    void restart(); // done

    void addCell(Block &block); // done
    void addToTurnCount();
    int getTurnCount();
    int checkClearBlock();
    virtual void setDimX(int x);
    virtual void setDimY(int y);

    void setLvlSequence(const std::vector<char> &seq); // added this <<<<
    void setCurrentBlock(Block *block);
    void setNextBlock(Block *block);
    char getNextBlockType() const;
    void convertNextToCurrent();

    void setValue(char newValue, int x, int y);
    virtual char getChar(int x, int y) const;
};

#endif
