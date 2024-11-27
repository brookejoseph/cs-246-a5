#ifndef GAMEENGINE_H
#define GAMEENGINE_H
#include "../board/board.h"
#include "../commandcontroller/commandcontroller.h"
#include <memory>
#include <map>
#include <functional>

using namespace std;

class GameEngine
{
private:
    Board *baseBoard;
    std::shared_ptr<Board> player1;
    std::shared_ptr<Board> player2;
    string currentCommand; // done
    int amount;            // done
    char currentChar;      // done
    std::map<std::string, std::function<void(int)>> commandMap;

    void initializeCommandMap();

public:
    GameEngine(int x, int y);
    ~GameEngine();
    void executeCommand(const std::string &command, int amount = 1);

    Board *returnCurrentBoard();
};

#endif
