#include "gameengine.h"
#include "../block/block.h"
#include "../block/blockZ.h"
#include "../block/blockJ.h"
#include "../block/blockO.h"
#include "../block/blockI.h"
#include "../block/blockT.h"
#include "../block/blockS.h"
#include "../block/blockL.h"
#include "../level/level.h"
#include "../level/level.h"
#include "../level/level0.h"
#include "../level/level1.h"
#include "../level/level2.h"
#include "../level/level3.h"
#include "../level/level4.h"

#include <iostream>
#include <memory>
#include <vector>
#include <utility>
#include <map>
#include <cmath>

using namespace std;

GameEngine::GameEngine(int x, int y) : player1(std::make_shared<Board>(x, y)),
                                       player2(std::make_shared<Board>(x, y)),
                                       currentPlayer(1),
                                       highScore(0),
                                       currentChar(' ')
{
}

int GameEngine::grabCurrentScore()
{
    return (currentPlayer == 1) ? player1Score : player2Score;
}

int GameEngine::grabPlayer()
{
    return currentPlayer;
}

void GameEngine::updateHighScore()
{
    highScore = std::max({highScore, player1Score, player2Score});
}

void GameEngine::calScore()
{

    int level = currentBoard()->getLevel();
    int numLines = currentBoard()->checkClearLine();
    int numBlocks = currentBoard()->checkClearBlock();
    cout << "number of lines cleared" << numLines << endl;

    int blockPoints = 0;
    int linePoints = 0;
    int totalPoints = 0;

    if (numLines > 0 || numBlocks > 0)
    {
        blockPoints = numBlocks * std::pow(level + 1, 2);
        linePoints = std::pow(level + numLines, 2);
        totalPoints = linePoints + blockPoints;

        if (currentPlayer == 1)
        {
            player1Score += totalPoints;
        }
        else
        {
            player2Score += totalPoints;
        }

        updateHighScore();
    }
}

std::shared_ptr<Board> GameEngine::currentBoard()
{
    return (currentPlayer == 1) ? player1 : player2;
}

void GameEngine::setPlayer()
{
    currentPlayer = (currentPlayer == 1) ? 2 : 1;
}

void GameEngine::restartGame()
{
    player1Score = 0;
    player2Score = 0;
    player1->restart();
    player2->restart();
}

int GameEngine::getCurrentScore()
{
    return grabCurrentScore();
}

int GameEngine::getHighScore() const
{
    return highScore;
}

int GameEngine::getPlayer1Score() const
{
    return player1Score;
}

int GameEngine::getPlayer2Score() const
{
    return player2Score;
}

std::shared_ptr<Board> GameEngine::getPlayer1() const
{
    return player1;
}

std::shared_ptr<Board> GameEngine::getPlayer2() const
{
    return player2;
}

void GameEngine::executeCommand(const std::string &command, int amount)
{
    if (amount < 0)
    {
        std::cerr << "Invalid multiplier: " << amount << std::endl;
        return;
    }

    if (commandMap.empty())
    {
        initializeCommandMap();
    }

    auto it = commandMap.find(command);

    if (it != commandMap.end())
    {
        if (command == "drop")
        {
            it->second(amount);
            calScore();
            notifyObservers();
        }
        else
        {
            it->second(amount);
            notifyObservers();
        }
    }
    else
    {
        std::cerr << "Invalid command: " << command << std::endl;
    }
}

std::string blockTypeToString(int blockType)
{
    switch (blockType)
    {
    case 1:
        return "Z";
    case 2:
        return "T";
    case 3:
        return "J";
    case 4:
        return "I";
    case 5:
        return "S";
    case 6:
        return "O";
    case 7:
        return "L";
    default:
        throw std::invalid_argument("Invalid BlockType");
    }
}

void GameEngine::applyForce(int b)
{
    string blockType = blockTypeToString(b);
    executeCommand(blockType);
};

void GameEngine::initializeCommandMap()
{
    commandMap = {
        {"left", [this](int amount)
         { currentBoard()->left(amount); }},
        {"right", [this](int amount)
         { currentBoard()->right(amount); }},
        {"down", [this](int amount)
         { currentBoard()->down(amount); }},
        {"drop", [this](int)
         { currentBoard()->drop(); }},
        {"counterclockwise", [this](int amount)
         { currentBoard()->ccw(amount); }},
        {"clockwise", [this](int amount)
         { currentBoard()->cw(amount); }},
        {"levelup", [this](int amount)
         { currentBoard()->levelUp(); }},
        {"leveldown", [this](int amount)
         { currentBoard()->levelDown(); }},

        {"heavy", [this](int)
         { currentBoard()->setHeavy(true); }},
        {"force", [this](int letter)
         { applyForce(letter);
            currentBoard()->setForce(true); }},
        {"blind", [this](int)
         { currentBoard()->setBlind(true); }},

        {"Z", [this](int)
         { currentBoard()->setCurrentBlock(std::make_shared<ZBlock>()); }},
        {"T", [this](int)
         { currentBoard()->setCurrentBlock(std::make_shared<TBlock>()); }},
        {"J", [this](int)
         { currentBoard()->setCurrentBlock(std::make_shared<JBlock>()); }},
        {"I", [this](int)
         { currentBoard()->setCurrentBlock(std::make_shared<IBlock>()); }},
        {"S", [this](int)
         { currentBoard()->setCurrentBlock(std::make_shared<SBlock>()); }},
        {"O", [this](int)
         { currentBoard()->setCurrentBlock(std::make_shared<OBlock>()); }},
        {"L", [this](int)
         { currentBoard()->setCurrentBlock(std::make_shared<LBlock>()); }},
    };
}

// if ((currentBoard()->getBlind()) && (currentBoard()->checkClearLine() < 2))
// {
//     currentBoard()->removeBlind();
// };

// if (player1->gameOver() || player2->gameOver()) {
//     notifyObservers();
//     std::cout << "Game over! High Score: " << highScore << '\n';
//     restartGame();
// }