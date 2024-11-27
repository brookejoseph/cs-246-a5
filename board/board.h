
#ifndef BOARD_H // Add this line
#define BOARD_H // Add this line
#include <vector>
#include <tuple>
#include <iostream>
#include <ostream>
#include <memory>
#include "../level/level.h"
#include "../observer/subject.h"

class Block; // forward declaration

class Board : public Subject
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

public:
    Board(int x, int y) noexcept;
    ~Board() = default;

    bool isValidMove();
    int findScore();

    void levelDown();
    void levelUp();
    Level getLevelPtr();
    int getLevel() const;

    void left(int amount);  // done
    void right(int amount); // done
    void down(int amount);  // done
    void cw(int amount);    // done
    void ccw(int amount);   // done
    void drop();            // done

    void saveGame(); //??
    void restart();  // done
    void loadGame();
    // virtual char getState(int x, int y) const override;

    void eraseBlock();          // whats the difference between this and restart idk
    void addCell(Block &block); // done
    void addToTurnCount();
    int getTurnCount();
    virtual void setDimX(int x);
    virtual void setDimY(int y);

    void setCurrentBlock(Block *block);
    void setNextBlock(Block *block);
    void convertNextToCurrent();

    void setValue(char newValue, int x, int y);
    virtual char getValue(int x, int y) override;
};

#endif