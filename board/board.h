
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

protected:
    std::vector<std::vector<char>> backupGrid;
    int dimX = 11;
    int dimY = 18;
    int noBlocksCleared = 0;
    int temp_score = 0;
    int numLinesCleared;
    int noClearCount;
    int level;
    bool shouldDrop;
    bool blind;
    bool heavy;
    bool force;

    std::vector<std::vector<std::pair<int, int>>> addedBlocks;
    std::array<std::shared_ptr<Level>, 5> parameter = {
        std::make_shared<Level0>(),
        std::make_shared<Level1>(),
        std::make_shared<Level2>(),
        std::make_shared<Level3>(),
        std::make_shared<Level4>()};

public:
    Board(int x, int y) noexcept;
    ~Board() = default;

    void setLevel(int lvl);
    int getLevel() const;
    void setRandom(bool isRandom);

    int checkClearLine();
    void updateClearLines();
    void removeIncr(int row);

    void left(int amount);
    void right(int amount);
    void down(int amount);
    void cw(int amount);
    void ccw(int amount);
    void drop();

    void restart();
    bool gameOver();

    void addCell(Block &block);
    int checkClearBlock();

    void setDimX(int x);
    void setDimY(int y);
    void setHeavy(bool val);
    bool getHeavy();
    void setBlind(bool val);
    bool getBlind();
    void setForce(bool val);
    bool getForce();

    void getNextBlock();
    char getNextBlockType() const;
    char getCurrentBlockType() const;
    void initBlocks();

    void setValue(char newValue, int x, int y);
    virtual char getChar(int x, int y) const;

    void addBlockToVec(const std::shared_ptr<Block> &blockVal);
    void setLvlSequence(const std::vector<char> &seq);
    void setCurrentBlock(const std::shared_ptr<Block> &block);
    std::vector<std::pair<int, int>> getCurrentBlockCoord() const;
    std::vector<std::vector<char>> getGrid();
};

#endif
