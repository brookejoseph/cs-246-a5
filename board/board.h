
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
    /*
        int cols = 11;
        int rows = 18;
        std::vector<std::vector<char>> grid; */

    std::vector<std::vector<char>> grid;

    std::shared_ptr<Block> currentBlock;
    std::shared_ptr<Block> nextBlock;

    int level;
    std::vector<std::unique_ptr<Level>> levelList;

    int score;
    int highScore;

    int noClearCount;

protected:
    int dimX;
    int dimY;

public:
    Board() noexcept;
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
    virtual char getChar(int x, int y);

    void eraseBlock();          // whats the difference between this and restart idk
    void addCell(Block &block); // done
    void addToTurnCount();
    int getTurnCount();
    virtual void setDimX(int x);
    virtual void setDimY(int y);

    void setValue(char newValue, int x, int y);
    char getValue(int x, int y);
};

#endif