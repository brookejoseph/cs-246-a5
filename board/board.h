
#ifndef BOARD_H
#define BOARD_H
#include <vector>
#include <tuple>
#include <iostream>
#include <ostream>
#include <memory>

#include "../cell/cell.h"
#include "../level/level.h"
#include "../level/level0.h"
#include "../level/level1.h"
#include "../level/level2.h"
#include "../level/level3.h"
#include "../level/level4.h"

#include "../observer/subject.h"

class Board: public Cell
{
private:
    std::vector<std::vector<char>> grid;

    std::shared_ptr<Block> currentBlock;
    std::shared_ptr<Block> nextBlock;

    int level;
    std::shared_ptr<Level> currentLevelPtr;
    std::vector<std::shared_ptr<Level>> levelList;

    int score;
    int highScore;

    int noClearCount;

protected:
    int dimX = 11;
    int dimY = 18;
    int numLinesCleared;

public:
    Board(std::shared_ptr<Cell> grid) noexcept;
    ~Board() = default;

    void levelUp(int amount);
    void levelDown(int amount);
    int getCurrentLevelVal();
    std::shared_ptr<Level> getCurrentLevelPtr();

    int checkClearLine();
    void updateClearLines();

    bool isValidMove();
    int findScore();

    std::shared_ptr<Level> getLevelPtr() const;
    int getLevel() const;
    void setSequence(const std::vector<char> &seq); // added this <<<<

    void left(int amount);  // done
    void right(int amount); // done
    void down(int amount);  // done
    void cw(int amount);    // done
    void ccw(int amount);   // done
    void drop();            // done

    void restart(); // done
    void eraseBlock();
    void addCell(Block &block); // done
    void addToTurnCount();
    int getTurnCount();
    int getDimX();
    int getDimY();

    void setCurrentBlock(std::shared_ptr<Block> block);
    void setNextBlock(std::shared_ptr<Block> block);
    std::shared_ptr<Block> getNextBlock() const;
    void convertNextToCurrent();

    void setValue(char newValue, int x, int y);
    virtual char getValue(int x, int y) override;
};

#endif
