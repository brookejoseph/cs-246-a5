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
    Board *player1;
    Board *player2;
    string currentCommand;
    int currentLevel;
    char currentChar;

    int currentScore = 0;
    int highScore = 0;

    std::map<std::string, std::function<void(int)>> commandMap;

    void initializeCommandMap();

    void updateHighScore();

public:
    GameEngine(int x, int y);
    ~GameEngine();

    void executeCommand(const std::string &command, int amount = 1);

    Board *returnCurrentBoard();

    void clearLines(int linesCleared);
    void clearBlock();
    void restartGame();

    Board *getPlayer1();
    Board *getPlayer2();

    int getCurrentScore() const;
    int getHighScore() const;
};

#endif
