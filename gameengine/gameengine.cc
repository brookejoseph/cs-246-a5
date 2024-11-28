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

GameEngine::GameEngine(int x, int y)
    : player1(std::make_shared<Board>(x, y)),
      player2(std::make_shared<Board>(x, y)),
      currentPlayer(1),
      highScore(0),
      currentChar(' ') {}

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

    int linePoints = std::pow(level + numLines, 2);
    int blockPoints = numBlocks * std::pow(level + 1, 2);
    int totalPoints = linePoints + blockPoints;

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
        it->second(amount);
        if (command == "drop")
        {
            calScore();
        }
    }
    else
    {
        std::cerr << "Invalid command: " << command << std::endl;
    }
}

/*
GameEngine::GameEngine(int x, int y)
{
    baseBoard = new Board(11, 18);
    initializeCommandMap();
};

GameEngine::~GameEngine()
{
    delete baseBoard;
};



void GameEngine::executeCommand(const std::string &command, int amount)
{
    auto it = commandMap.find(command);
    if (it != commandMap.end())
    {
        it->second(amount);
    }
    else
    {
        std::cerr << "Invalid command: " << command << std::endl;
    }
};
*/

/*
void GameEngine::initializeCommandMap()
{
    commandMap = {
        {"left", [this](int amount)
         { baseBoard->left(amount); }},
        {"right", [this](int amount)
         { baseBoard->right(amount); }},
        {"down", [this](int amount)
         { baseBoard->down(amount); }},
        {"drop", [this](int)
         { baseBoard->drop(); }},
        {"counterclockwise", [this](int amount)
         { baseBoard->ccw(amount); }},
        {"clockwise", [this](int amount)
         { baseBoard->cw(amount); }},
        {"validMove", [this](int)
         { baseBoard->isValidMove(); }},
        {"levelup", [this](int)
         { ++currentLevel; }},
        {"leveldown", [this](int)
         { --currentLevel; }},
        {"zBlock", [this](int)
         { ZBlock *newBlock = new ZBlock();
           baseBoard->setCurrentBlock(newBlock); }},
        {"tBlock", [this](int)
         { TBlock *newBlock = new TBlock();
           baseBoard->setCurrentBlock(newBlock); }},
        {"jBlock", [this](int)
         { JBlock *newBlock = new JBlock();
           baseBoard->setCurrentBlock(newBlock); }},
        {"iBlock", [this](int)
         { IBlock *newBlock = new IBlock();
           baseBoard->setCurrentBlock(newBlock); }},
        {"sBlock", [this](int)
         { SBlock *newBlock = new SBlock();
           baseBoard->setCurrentBlock(newBlock); }},
        {"oBlock", [this](int)
         { OBlock *newBlock = new OBlock();
           baseBoard->setCurrentBlock(newBlock); }},
        {"lBlock", [this](int)
         { LBlock *newBlock = new LBlock();
           baseBoard->setCurrentBlock(newBlock); }},
    };
}*/
