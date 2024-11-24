#include <vector>
#include <tuple>
#include <iostream>
#include <ostream>
#include "block/block.h"
#include "cell/cell.h"
#include "level/level.h"
#include "observer/subject.h"

Board::Board(int cols, int rows): grid{rows, vector<Cell>(cols)} {};

bool Board::isValidMove() {
    //make these class variables later
    int dimX = 11;
    int dimY = 15;

    //for loop is unnecessary -- can be removed later, because we are only moving one block at a time
    for (auto &t : current_block->getCoord()) 
    {
        auto &[p1, p2, p3, p4] = t;
        if (((p1.first > dimX) || (p2.first > dimX) || (p3.first > dimX) || (p4.first > dimX)) ||
            ((p1.first < 0) || (p2.first < 0) || (p3.first < 0) || (p4.first < 0))) 
        {
            return false;
        }
        if (((p1.second > dimY) || (p2.second > dimY) || (p3.second > dimY) || (p4.second > dimY))) 
        {
            return false;
        }
        if ((board[p1.first][p1.second].getValue() != ' ') ||
            (board[p2.first][p2.second].getValue() != ' ') ||
            (board[p3.first][p3.second].getValue() != ' ') ||
            (board[p4.first][p4.second].getValue() != ' ')) 
        {
            return false;
        }
    }
    return true;
}

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
        //negation of the condition is required
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
