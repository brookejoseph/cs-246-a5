#ifndef GAMEENGINE_H
#define GAMEENGINE_H
#include "board.h"
#include "commandcontroller.h"
#include <memory>

class GameEngine
{
private:
    std::shared_ptr<Board> player1;
    std::shared_ptr<Board> player2;
    string currentCommand; // done
    int amount;            // done
    char currentChar;      // done
    Board *baseBoard;
    std::unordered_map<std::string, void (Board::*)()> commandMap;

public:
    void start();  // done
    GameEngine();  // done
    ~GameEngine(); // done
    void initializeCommandMap();
};

#endif
