#include <vector>
#include <tuple>
#include <iostream>
#include <ostream>
#include "block/block.h"
#include "level/level.h"
#include "cell/cell.h"
#include "observer/subject.h"

class Board : public Subject
{
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

    void left(int amount) {};  // done
    void right(int amount) {}; // done
    void down(int amount) {};  // done
    void cw(int amount) {};    // done
    void ccw(int amount) {};   // done
    void drop() {};            // done

    void saveGame() {}; //??
    void restart() {};  // done
    void loadGame() {};
    char getChar(int x, int y) {};

    void eraseBlock() {};          // whats the difference between this and restart idk
    void addCell(Board &block) {}; // done
    void addToTurnCount() {};
    int getTurnCount() {};
};