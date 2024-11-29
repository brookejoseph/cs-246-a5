
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

    std::shared_ptr<Block> currentBlock;
    std::shared_ptr<Block> nextBlock;

    int noClearCount;

protected:
    std::vector<std::vector<char>> backupGrid;
    int dimX = 11;
    int dimY = 18;
    int noBlocksCleared = 0;
    int temp_score = 0;
    int numLinesCleared;

    int numClearedPerFive;
    bool dropStarFive;


    bool shouldDrop;

    // std::vector<std::shared_ptr<Block>> addedBlocks;
    std::vector<std::vector<std::pair<int, int>>> addedBlocks;

    int level;
    std::array<std::shared_ptr<Level>, 5> parameter = {
        std::make_shared<Level0>(),
        std::make_shared<Level1>(),
        std::make_shared<Level2>(),
        std::make_shared<Level3>(),
        std::make_shared<Level4>()};

    bool blind;

public:
    bool clearedPerFive();
    Board(int x, int y) noexcept;
    virtual ~Board() = default;

    int midVal();
    bool dropStar();
    void setDropStart(bool val);

    void setLevel(int lvl);
    int getLevel() const;
    void setRandom(bool isRandom);
    void setHeavy(bool isHeavy);

    int checkClearLine();
    void updateClearLines();
    std::vector<std::vector<char>> getGrid();

    void addBlockToVec(const std::shared_ptr<Block> &blockVal);
    void removeIncr(int row);

    void left(int amount);  // done
    void right(int amount); // done
    void down(int amount);  // done
    void cw(int amount);    // done
    void ccw(int amount);   // done
    void drop();            // done

    void restart(); // done
    bool gameOver();

    void addCell(Block &block); // done
    int checkClearBlock();
    void setDimX(int x);
    void setDimY(int y);
    void setBlind(bool val);
    bool getBlind();
    // void applyBlind();
    // void removeBlind();

    void setLvlSequence(const std::vector<char> &seq); // added this <<<<
    void setCurrentBlock(const std::shared_ptr<Block> &block);
    std::shared_ptr<Block> getCurrentBlock() const;
    void getNextBlock();
    char getNextBlockType() const;
    std::vector<std::pair<int, int>> getCurrentBlockCoord() const;
    char getCurrentBlockType() const;
    void initBlocks();

    void setValue(char newValue, int x, int y);
    virtual char getChar(int x, int y) const;
};

#endif
