#include "gameengine.h"
#include "../block/blockZ.h"
#include "../block/blockJ.h"
#include "../block/blockO.h"
#include "../block/blockI.h"
#include "../block/blockT.h"
#include "../block/blockS.h"
#include "../block/blockL.h"

#include <iostream>
#include <memory>
#include <vector>
#include <utility>
#include <map>

using namespace std;
pair<int, int> coordA = {0, 0};
pair<int, int> coordB = {0, 1};
pair<int, int> coordC = {1, 1};
pair<int, int> coordD = {1, 2};
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
        {"ccw", [this](int amount)
         { baseBoard->ccw(amount); }},
        {"cw", [this](int amount)
         { baseBoard->cw(amount); }},
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
}

Board *GameEngine::returnCurrentBoard()
{
    return baseBoard;
};
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
