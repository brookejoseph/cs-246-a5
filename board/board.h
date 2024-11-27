
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

    int level;
    std::vector<std::unique_ptr<Level>> levelList;

    int score;
    int highScore;

    int noClearCount;

protected:
    int dimX = 11;
    int dimY = 18;
    int numLinesCleared;

    int currentLevel;
    Level *currentPtr;
    Level *parameter[5] = {new Level0(),
                           new Level1(),
                           new Level2(),
                           new Level3(),
                           new Level4()};

public:
    Board(int x, int y) noexcept;
    ~Board() = default;

    virtual void levelUp();
    virtual void levelDown();
    virtual int getCurrentLevelVal();
    virtual Level *getCurrentLevelPtr();

    virtual int checkClearLine();
    virtual void updateClearLines();

    bool isValidMove();
    int findScore();

    Level getLevelPtr();
    int getLevel() const;

    void left(int amount);  // done
    void right(int amount); // done
    void down(int amount);  // done
    void cw(int amount);    // done
    void ccw(int amount);   // done
    void drop();            // done

    void saveGame();
    void restart(); // done
    void loadGame();
    // virtual char getState(int x, int y) const override;

    void eraseBlock();
    void addCell(Block &block); // done
    void addToTurnCount();
    int getTurnCount();
    virtual void setDimX(int x);
    virtual void setDimY(int y);

    void setSequence(const std::vector<char> &seq); // added this <<<<
    void setCurrentBlock(Block *block);
    void setNextBlock(Block *block);
    void convertNextToCurrent();

    void setValue(char newValue, int x, int y);
    virtual char getValue(int x, int y);
};

#endif
