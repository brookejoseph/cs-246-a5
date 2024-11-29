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
    std::shared_ptr<Board> player1;
    std::shared_ptr<Board> player2;
    std::string currentCommand;
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
    ~GameEngine() = default;
    void applyForce(int b);

    void executeCommand(const std::string &command, int amount = 1);

    int grabCurrentScore();
    void calScore();
    void restartGame();

    std::shared_ptr<Board> getPlayer1() const;
    std::shared_ptr<Board> getPlayer2() const;

    int getPlayer1Score() const;
    int getPlayer2Score() const;

    int getCurrentScore();
    int getHighScore() const;
    void setPlayer();
    std::shared_ptr<Board> currentBoard();
    int grabPlayer();
};

#endif