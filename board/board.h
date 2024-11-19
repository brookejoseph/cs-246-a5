#include <vector>
#include <tuple>
#include <iostream>
#include <ostream>
#include "block/block.h"
#include "level/level.h"
#include "cell/cell.h"

class Board
{
private:
    Block *current_block;
    Block *next_block;
    Level *current_level;
    vector<vector<cell>> board;
    int score;

public:
    Board();
    ~Board();
    Board(Board const &other) {};
    Board(Board &&other) {};

    bool isValidMove() {};
    int findScore() {};

    void levelDown() {};
    void levelUp() {};
    Level getLevelPtr() {};

    void left(int amount) {};
    void right(int amount) {};
    void down(int amount) {};
    void cw(int amount) {};
    void ccw(int amount) {};
    void drop(int amount) {};

    void saveGame() {};
    void restart() {};
    void loadGame() {};

    void eraseBlock() {};
    void addCell(Board &block) {};
    void addToTurnCount() {};
    int getTurnCount() {};
};