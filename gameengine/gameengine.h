#ifndef GAMEENGINE_H
#define GAMEENGINE_H
#include "../board/board.h"
#include "../commandcontroller/commandcontroller.h"
#include "../level/level.h"
#include "../level/level0.h"
#include "../level/level1.h"
#include "../level/level2.h"
#include "../level/level3.h"
#include "../level/level4.h"

#include <memory>
#include <map>
#include <functional>

using namespace std;
class GameEngine : public Subject
{
private:
    Board *player1;
    Board *player2;
    string currentCommand;
    int currentLevel;
    char currentChar;

    int currentPlayer;

    int player1Score = 0;
    int player2Score = 0;
    int highScore = 0;

    std::map<std::string, std::function<void(int)>> commandMap;

    void initializeCommandMap();

    void updateHighScore();

public:
    GameEngine(int x, int y);
    ~GameEngine();

    void executeCommand(const std::string &command, int amount = 1);

    // bool blockRemoved();

    int grabCurrentScore();

    void calScore();
    void restartGame();

    Board *getPlayer1();
    Board *getPlayer2();

    int getCurrentScore();
    int getHighScore() const;
    void setPlayer();
    Board *currentBoard();
    int grabPlayer();
};

#endif
