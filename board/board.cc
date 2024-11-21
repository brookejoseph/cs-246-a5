#include <vector>
#include <tuple>
#include <iostream>
#include <ostream>
#include "block/block.h"
#include "cell/cell.h"
#include "level/level.h"
#include "observer/subject.h"

class Board : public Subject
{
private:
    Block *current_block;
    Block *next_block;
    Level *current_level;
    vector<vector<Cell>> board;
    int score;
    int player;

public:
    Board() : board(11, vector<Cell>(15, Cell())) {};
    ~Board();

    bool isValidMove() {};
    int findScore() {};

    void levelDown() {};
    void levelUp() {};
    Level getLevelPtr() {};

    void left(int amount) {};
    void right(int amount) {};
    void down(int amount) {};
    void cw(int amount) {};
    void ccw(int amount) {};
    void drop() {};

    void saveGame() {};
    void restart() {};
    void loadGame() {};

    void eraseBlock() {};
    void addCell(Block *thisBlock) {};

    void addToTurnCount() {};
    int getTurnCount() {};
};

Board::Board() : board(11, vector<Cell>(15)) {};

bool Board::isValidMove()
{
    for (auto &t : current_block->getCoord())
    {
        auto &[p1, p2, p3, p4] = t;
        if ((p1.first > 11) || (p2.first > 11) || (p3.first > 11) || (p4.first > 11))
        {
            return false;
        };
        if ((p1.second > 15) || (p2.second > 15) || (p3.second > 15) || (p4.second > 15))
        {
            return false;
        };
        return true;
    };
};

void Board::left(int amount)
{
    for (int i = 0; i < amount; i++)
    {
        current_block->left();
    };
};

void Board::right(int amount)
{
    for (int i = 0; i < amount; i++)
    {
        current_block->right();
    };
};

void Board::down(int amount)
{
    for (int i = 0; i < amount; i++)
    {
        current_block->down();
    };
};

void Board::ccw(int amount)
{
    for (int i = 0; i < amount; i++)
    {
        current_block->rotateccw();
    };
};

void Board::cw(int amount)
{
    for (int i = 0; i < amount; i++)
    {
        current_block->rotatecw();
    };
};

// LOGIC NEEDS TO BE FIXED HERE
// um I just need someone to here to help me make sure that we're putting in the proper letters for all the values
void Board::addCell(Block *thisBlock)
{
    for (auto &t : thisBlock->getCoord())
    {
        auto &[p1, p2, p3, p4] = t;
        char letter = thisBlock->getChar();
        board[p1.first][p1.second].setValue(letter);
        board[p2.first][p2.second].setValue(letter);
        board[p3.first][p3.second].setValue(letter);
        board[p4.first][p4.second].setValue(letter);
    };
};

void Board::drop()
{
    for (auto &t : current_block->getCoord())
    {
        auto &[p1, p2, p3, p4] = t;
        while ((board[p1.first][p1.second].getValue() != ' ') ||
               (board[p2.first][p2.second].getValue() != ' ') ||
               (board[p3.first][p3.second].getValue() != ' ') ||
               (board[p4.first][p4.second].getValue() != ' '))
        {
            ++p1.second;
            ++p2.second;
            ++p3.second;
            ++p4.second;
        };
    };
    addCell(current_block);
    if (player == 1)
    {
        player = 0;
    };
    player = 1;
};

void Board::restart()
{
    board.clear();
};

int Board::findScore()
{
    return score;
};
