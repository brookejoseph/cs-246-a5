#include "gameengine.h"
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

bool GameEngine::blockRemoved()
{
    return baseBoard->blockRemoved();
};

int GameEngine::grabCurrentScore()
{
    map<int, int> currentS = {
        {1, player1Score},
        {2, player2Score},
    };
    return currentS[currentPlayer];
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
    int level = returnCurrentBoard()->getCurrentLevelVal();
    int numLines = returnCurrentBoard()->checkClearLine();
    int points = std::pow(level + numLines, 2);
    int newPoints = 0;

    if (blockRemoved())
    {
        newPoints = pow(level + 1, 2);
    };
    int current = grabCurrentScore();
    current = current + points + newPoints;
    updateHighScore();
}

void GameEngine::restartGame()
{
    player1Score = 0;
    player2Score = 0;
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

GameEngine::~GameEngine()
{
    delete baseBoard;
}

/// above is the newly add stuff

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
        {"levelup", [this](int amount)
         { baseBoard->levelUp(amount); }},
        {"leveldown", [this](int amount)
         { baseBoard->levelDown(amount); }},
        {"zBlock", [this](int)
         { Block *newBlock = new ZBlock();
           baseBoard->setCurrentBlock(newBlock); }},
        {"tBlock", [this](int)
         { Block *newBlock = new TBlock();
           baseBoard->setCurrentBlock(newBlock); }},
        {"jBlock", [this](int)
         { Block *newBlock = new JBlock();
           baseBoard->setCurrentBlock(newBlock); }},
        {"iBlock", [this](int)
         { Block *newBlock = new IBlock();
           baseBoard->setCurrentBlock(newBlock); }},
        {"sBlock", [this](int)
         { Block *newBlock = new SBlock();
           baseBoard->setCurrentBlock(newBlock); }},
        {"oBlock", [this](int)
         { Block *newBlock = new OBlock();
           baseBoard->setCurrentBlock(newBlock); }},
        {"lBlock", [this](int)
         { Block *newBlock = new LBlock();
           baseBoard->setCurrentBlock(newBlock); }},
    };
}

Board *GameEngine::getPlayer1()
{
    return player1;
}
Board *GameEngine::getPlayer2()
{
    return player2;
}

Board *GameEngine::returnCurrentBoard()
{
    return baseBoard;
};

GameEngine::GameEngine(int x, int y)
    : baseBoard(new Board(x, y)),
      player1(new Board(x, y)),
      player2(new Board(x, y)),
      currentLevel(0), currentChar(' ') {}

void GameEngine::executeCommand(const std::string &command, int amount)
{
    if (commandMap.empty())
    {
        initializeCommandMap();
    }

    auto it = commandMap.find(command);

    if (it != commandMap.end())
    {
        it->second(amount);
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
