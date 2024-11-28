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

int GameEngine::grabCurrentScore()
{
    return (currentPlayer == 1) ? player1Score : player2Score;
}

int GameEngine::grabPlayer()
{
    return currentPlayer;
};

void GameEngine::updateHighScore()
{
    if (player1Score > highScore)
    {
        highScore = player1Score;
    }
    else if (player2Score > highScore)
    {
        highScore = player2Score;
    }
}

void GameEngine::calScore()
{
    int level = currentBoard()->getLevel();
    int numLines = currentBoard()->checkClearLine();
    int numBlocks = currentBoard()->checkClearBlock();
    cout << "Number of Lines Cleared: " << numLines << endl;
    cout << "Number of Blocks Cleared: " << numBlocks << endl;

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

Board *GameEngine::currentBoard()
{
    return (currentPlayer == 1) ? player1 : player2;
}

void GameEngine::setPlayer()
{
    if (currentPlayer == 1)
    {
        currentPlayer = 2;
    }
    else
    {
        currentPlayer = 1;
    }
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
    int current = grabCurrentScore();
    return current;
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

GameEngine::~GameEngine()
{
    delete player2;
    delete player1;
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
         {
             Block *newBlock = new ZBlock();
             currentBoard()->setCurrentBlock(newBlock);
         }},
        {"T", [this](int)
         {
             Block *newBlock = new TBlock();
             currentBoard()->setCurrentBlock(newBlock);
         }},
        {"J", [this](int)
         {
             Block *newBlock = new JBlock();
             currentBoard()->setCurrentBlock(newBlock);
         }},
        {"I", [this](int)
         {
             Block *newBlock = new IBlock();
             currentBoard()->setCurrentBlock(newBlock);
         }},
        {"S", [this](int)
         {
             Block *newBlock = new SBlock();
             currentBoard()->setCurrentBlock(newBlock);
         }},
        {"O", [this](int)
         {
             Block *newBlock = new OBlock();
             currentBoard()->setCurrentBlock(newBlock);
         }},
        {"L", [this](int)
         {
             Block *newBlock = new LBlock();
             currentBoard()->setCurrentBlock(newBlock);
         }},
    };
}

Board *GameEngine::getPlayer1() const
{
    return player1;
}
Board *GameEngine::getPlayer2() const
{
    return player2;
}

GameEngine::GameEngine(int x, int y) : player1(new Board(x, y)),
                                       player2(new Board(x, y)),
                                       currentPlayer(1),
                                       highScore(0),
                                       currentChar(' ') {}

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

        // notifyObservers();
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
