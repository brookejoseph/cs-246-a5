#include "../gameengine/gameengine.h"
#include "../block/blockZ.h"
#include "../block/blockJ.h"
#include "../block/blockO.h"
#include "../block/blockI.h"
#include "../block/blockT.h"
#include "../block/blockS.h"
#include "../block/blockL.h"

#include <string>
#include <iostream>
#include <sstream>
#include <vector>
#include <fstream>

using namespace std;

void printBoard(const std::shared_ptr<Board> &board, int dimX, int dimY)
{
    std::cout << "Current Board State:\n";
    for (int y = 0; y < dimY; ++y)
    {
        for (int x = 0; x < dimX; ++x)
        {
            std::cout << board->getChar(x, y) << " ";
        }
        std::cout << std::endl;
    }
}

void test1()
{
    GameEngine gameEngine(11, 18);
    // Player 1's turn
    cout << "Current player before drop: " << gameEngine.grabPlayer() << endl;
    gameEngine.executeCommand("O");
    gameEngine.executeCommand("drop");
    cout << "Player 1 score: " << gameEngine.grabCurrentScore() << endl;
    cout << "High score: " << gameEngine.getHighScore() << endl;
    auto board = gameEngine.currentBoard();
    printBoard(board, 11, 18);

    cout << "Current player before drop: " << gameEngine.grabPlayer() << endl;
    gameEngine.executeCommand("O");
    gameEngine.executeCommand("right", 2);
    gameEngine.executeCommand("drop");
    cout << "Player 1 score: " << gameEngine.grabCurrentScore() << endl;
    cout << "High score: " << gameEngine.getHighScore() << endl;
    // auto board = gameEngine.currentBoard();
    printBoard(board, 11, 18);

    cout << "Current player before drop: " << gameEngine.grabPlayer() << endl;
    gameEngine.executeCommand("O");
    gameEngine.executeCommand("right", 4);
    gameEngine.executeCommand("drop");
    cout << "Player 1 score: " << gameEngine.grabCurrentScore() << endl;
    cout << "High score: " << gameEngine.getHighScore() << endl;
    // auto board = gameEngine.currentBoard();
    printBoard(board, 11, 18);

    cout << "Current player before drop: " << gameEngine.grabPlayer() << endl;
    gameEngine.executeCommand("O");
    gameEngine.executeCommand("right", 6);
    gameEngine.executeCommand("drop");
    cout << "Player 1 score: " << gameEngine.grabCurrentScore() << endl;
    cout << "High score: " << gameEngine.getHighScore() << endl;
    // board = gameEngine.currentBoard();
    printBoard(board, 11, 18);

    cout << "Current player before drop: " << gameEngine.grabPlayer() << endl;
    gameEngine.executeCommand("O");
    gameEngine.executeCommand("right", 8);
    gameEngine.executeCommand("drop");
    cout << "Player 1 score: " << gameEngine.grabCurrentScore() << endl;
    cout << "High score: " << gameEngine.getHighScore() << endl;
    // auto board = gameEngine.currentBoard();
    printBoard(board, 11, 18);

    cout << "Current player before drop: " << gameEngine.grabPlayer() << endl;
    gameEngine.executeCommand("I");
    gameEngine.executeCommand("clockwise", 1);
    gameEngine.executeCommand("right", 10);
    gameEngine.executeCommand("drop");
    cout << "Player 1 score: " << gameEngine.grabCurrentScore() << endl;
    cout << "High score: " << gameEngine.getHighScore() << endl;
    // auto board = gameEngine.currentBoard();
    printBoard(board, 11, 18);
    //     cout << "Player 1 score: " << gameEngine.grabCurrentScore() << endl;
    //     cout << "High score: " << gameEngine.getHighScore() << endl;
}

void test2()
{
    GameEngine gameEngine(11, 18);
    // Player 1's turn
    cout << "Current player before drop: " << gameEngine.grabPlayer() << endl;
    gameEngine.executeCommand("levelup");
    gameEngine.executeCommand("O");
    gameEngine.executeCommand("drop");
    cout << "Player 1 score: " << gameEngine.grabCurrentScore() << endl;
    cout << "High score: " << gameEngine.getHighScore() << endl;
    auto board = gameEngine.currentBoard();
    printBoard(board, 11, 18);

    cout << "Current player before drop: " << gameEngine.grabPlayer() << endl;

    gameEngine.executeCommand("O");
    gameEngine.executeCommand("right", 2);
    gameEngine.executeCommand("drop");
    cout << "Player 1 score: " << gameEngine.grabCurrentScore() << endl;
    cout << "High score: " << gameEngine.getHighScore() << endl;
    board = gameEngine.currentBoard();
    printBoard(board, 11, 18);

    cout << "Current player before drop: " << gameEngine.grabPlayer() << endl;

    gameEngine.executeCommand("O");
    gameEngine.executeCommand("right", 4);
    gameEngine.executeCommand("drop");
    cout << "Player 1 score: " << gameEngine.grabCurrentScore() << endl;
    cout << "High score: " << gameEngine.getHighScore() << endl;
    board = gameEngine.currentBoard();
    printBoard(board, 11, 18);

    cout << "Current player before drop: " << gameEngine.grabPlayer() << endl;

    gameEngine.executeCommand("O");
    gameEngine.executeCommand("right", 6);
    gameEngine.executeCommand("drop");
    cout << "Player 1 score: " << gameEngine.grabCurrentScore() << endl;
    cout << "High score: " << gameEngine.getHighScore() << endl;
    board = gameEngine.currentBoard();
    printBoard(board, 11, 18);

    cout << "Current player before drop: " << gameEngine.grabPlayer() << endl;

    gameEngine.executeCommand("O");
    gameEngine.executeCommand("right", 8);
    gameEngine.executeCommand("drop");
    cout << "Player 1 score: " << gameEngine.grabCurrentScore() << endl;
    cout << "High score: " << gameEngine.getHighScore() << endl;
    board = gameEngine.currentBoard();
    printBoard(board, 11, 18);

    gameEngine.executeCommand("O");
    gameEngine.executeCommand("right", 10);
    gameEngine.executeCommand("drop");
    cout << "Player 1 score: " << gameEngine.grabCurrentScore() << endl;
    cout << "High score: " << gameEngine.getHighScore() << endl;
    board = gameEngine.currentBoard();
    printBoard(board, 11, 18);

    gameEngine.executeCommand("I");
    gameEngine.executeCommand("right", 10);
    gameEngine.executeCommand("drop");
    cout << "Player 1 score: " << gameEngine.grabCurrentScore() << endl;
    cout << "High score: " << gameEngine.getHighScore() << endl;
    board = gameEngine.currentBoard();
    printBoard(board, 11, 18);
}

void test3()
{
    GameEngine gameEngine(11, 18);
    // Player 1's turn
    cout << "Current player before drop: " << gameEngine.grabPlayer() << endl;
    gameEngine.executeCommand("levelup");
    gameEngine.executeCommand("O");
    gameEngine.executeCommand("drop");
    cout << "Player 1 score: " << gameEngine.grabCurrentScore() << endl;
    cout << "High score: " << gameEngine.getHighScore() << endl;
    auto board = gameEngine.currentBoard();
    printBoard(board, 11, 18);

    cout << "Current player before drop: " << gameEngine.grabPlayer() << endl;

    gameEngine.executeCommand("O");
    gameEngine.executeCommand("right", 2);
    gameEngine.executeCommand("drop");
    cout << "Player 1 score: " << gameEngine.grabCurrentScore() << endl;
    cout << "High score: " << gameEngine.getHighScore() << endl;
    board = gameEngine.currentBoard();
    printBoard(board, 11, 18);

    cout << "Current player before drop: " << gameEngine.grabPlayer() << endl;

    gameEngine.executeCommand("O");
    gameEngine.executeCommand("right", 4);
    gameEngine.executeCommand("drop");
    cout << "Player 1 score: " << gameEngine.grabCurrentScore() << endl;
    cout << "High score: " << gameEngine.getHighScore() << endl;
    board = gameEngine.currentBoard();
    printBoard(board, 11, 18);

    cout << "Current player before drop: " << gameEngine.grabPlayer() << endl;

    gameEngine.executeCommand("O");
    gameEngine.executeCommand("right", 6);
    gameEngine.executeCommand("drop");
    cout << "Player 1 score: " << gameEngine.grabCurrentScore() << endl;
    cout << "High score: " << gameEngine.getHighScore() << endl;
    board = gameEngine.currentBoard();
    printBoard(board, 11, 18);

    cout << "Current player before drop: " << gameEngine.grabPlayer() << endl;

    gameEngine.executeCommand("O");
    gameEngine.executeCommand("right", 8);
    gameEngine.executeCommand("drop");
    cout << "Player 1 score: " << gameEngine.grabCurrentScore() << endl;
    cout << "High score: " << gameEngine.getHighScore() << endl;
    board = gameEngine.currentBoard();
    printBoard(board, 11, 18);

    gameEngine.executeCommand("I");
    gameEngine.executeCommand("clockwise", 1);
    gameEngine.executeCommand("right", 10);
    gameEngine.executeCommand("drop");
    cout << "Player 1 score: " << gameEngine.grabCurrentScore() << endl;
    cout << "High score: " << gameEngine.getHighScore() << endl;
    board = gameEngine.currentBoard();
    printBoard(board, 11, 18);
}

void test4()
{

    GameEngine gameEngine(11, 18);
    // gameEngine.currentBoard()->initBlocks();
    //  Player 1's turn
    cout << "Current player before drop: " << gameEngine.grabPlayer() << endl;
    gameEngine.executeCommand("levelup");
    gameEngine.executeCommand("L");
    // gameEngine.executeCommand("clockwise", 3);
    gameEngine.executeCommand("drop");
    cout << "Player 1 score: " << gameEngine.grabCurrentScore() << endl;
    cout << "High score: " << gameEngine.getHighScore() << endl;
    auto board = gameEngine.currentBoard();
    printBoard(board, 11, 18);

    cout << "Current player before drop: " << gameEngine.grabPlayer() << endl;
    // gameEngine.executeCommand("levelup");
    gameEngine.executeCommand("O");
    // gameEngine.executeCommand("right", 2);
    gameEngine.executeCommand("drop");
    cout << "Player 1 score: " << gameEngine.grabCurrentScore() << endl;
    cout << "High score: " << gameEngine.getHighScore() << endl;
    board = gameEngine.currentBoard();
    printBoard(board, 11, 18);

    cout << "Current player before drop: " << gameEngine.grabPlayer() << endl;
    // gameEngine.executeCommand("levelup");
    gameEngine.executeCommand("O");
    gameEngine.executeCommand("counterclockwise", 1);
    gameEngine.executeCommand("right", 3);
    gameEngine.executeCommand("drop");
    cout << "Player 1 score: " << gameEngine.grabCurrentScore() << endl;
    cout << "High score: " << gameEngine.getHighScore() << endl;
    board = gameEngine.currentBoard();
    printBoard(board, 11, 18);

    gameEngine.executeCommand("S");
    // gameEngine.executeCommand("counterclockwise", 1);
    gameEngine.executeCommand("right", 5);
    gameEngine.executeCommand("drop");
    cout << "Player 1 score: " << gameEngine.grabCurrentScore() << endl;
    cout << "High score: " << gameEngine.getHighScore() << endl;
    board = gameEngine.currentBoard();
    printBoard(board, 11, 18);

    // gameEngine.executeCommand("leveldown");
    gameEngine.executeCommand("J");
    gameEngine.executeCommand("right", 7);
    gameEngine.executeCommand("down", 12);
    gameEngine.executeCommand("counterclockwise", 1);
    gameEngine.executeCommand("drop");
    cout << "Player 1 score: " << gameEngine.grabCurrentScore() << endl;
    cout << "High score: " << gameEngine.getHighScore() << endl;
    board = gameEngine.currentBoard();
    printBoard(board, 11, 18);

    gameEngine.executeCommand("I");
    // gameEngine.executeCommand("right", );
    gameEngine.executeCommand("counterclockwise", 1);
    gameEngine.executeCommand("right", 5);
    gameEngine.executeCommand("drop");
    cout << "Player 1 score: " << gameEngine.grabCurrentScore() << endl;
    cout << "High score: " << gameEngine.getHighScore() << endl;
    board = gameEngine.currentBoard();
    printBoard(board, 11, 18);

    gameEngine.executeCommand("T");
    // gameEngine.executeCommand("right", );
    gameEngine.executeCommand("counterclockwise", 2);
    gameEngine.executeCommand("right", 2);
    gameEngine.executeCommand("drop");
    cout << "Player 1 score: " << gameEngine.grabCurrentScore() << endl;
    cout << "High score: " << gameEngine.getHighScore() << endl;
    board = gameEngine.currentBoard();
    printBoard(board, 11, 18);

    gameEngine.executeCommand("Z");
    // gameEngine.executeCommand("right", );
    gameEngine.executeCommand("clockwise", 1);
    gameEngine.executeCommand("right", 2);
    gameEngine.executeCommand("drop");
    cout << "Player 1 score: " << gameEngine.grabCurrentScore() << endl;
    cout << "High score: " << gameEngine.getHighScore() << endl;
    board = gameEngine.currentBoard();
    printBoard(board, 11, 18);

    gameEngine.executeCommand("O");
    // gameEngine.executeCommand("right", );
    gameEngine.executeCommand("clockwise", 1);
    // gameEngine.executeCommand("right", 2);
    gameEngine.executeCommand("drop");
    cout << "Player 1 score: " << gameEngine.grabCurrentScore() << endl;
    cout << "High score: " << gameEngine.getHighScore() << endl;
    board = gameEngine.currentBoard();
    printBoard(board, 11, 18);

    gameEngine.executeCommand("I");
    // gameEngine.executeCommand("right", );
    gameEngine.executeCommand("clockwise", 1);
    gameEngine.executeCommand("right", 4);
    gameEngine.executeCommand("drop");
    cout << "Player 1 score: " << gameEngine.grabCurrentScore() << endl;
    cout << "High score: " << gameEngine.getHighScore() << endl;
    board = gameEngine.currentBoard();
    printBoard(board, 11, 18);

    gameEngine.executeCommand("J");
    // gameEngine.executeCommand("right", );
    gameEngine.executeCommand("clockwise", 2);
    gameEngine.executeCommand("right", 6);
    gameEngine.executeCommand("drop");
    cout << "Player 1 score: " << gameEngine.grabCurrentScore() << endl;
    cout << "High score: " << gameEngine.getHighScore() << endl;
    board = gameEngine.currentBoard();
    printBoard(board, 11, 18);

    gameEngine.executeCommand("O");
    // gameEngine.executeCommand("right", );
    gameEngine.executeCommand("clockwise", 2);
    gameEngine.executeCommand("right", 10);
    gameEngine.executeCommand("drop");
    cout << "Player 1 score: " << gameEngine.grabCurrentScore() << endl;
    cout << "High score: " << gameEngine.getHighScore() << endl;
    board = gameEngine.currentBoard();
    printBoard(board, 11, 18);

    // gameEngine.executeCommand("O");
    // //gameEngine.executeCommand("right", );
    // gameEngine.executeCommand("clockwise", 2);
    // gameEngine.executeCommand("right", 10);
    // gameEngine.executeCommand("drop");
    // cout << "Player 1 score: " << gameEngine.grabCurrentScore() << endl;
    // cout << "High score: " << gameEngine.getHighScore() << endl;
    // board = gameEngine.currentBoard();
    // printBoard(board, 11, 18);

    // gameEngine.executeCommand("O");
    // //gameEngine.executeCommand("right", );
    // gameEngine.executeCommand("clockwise", 2);
    // gameEngine.executeCommand("right", 10);
    // gameEngine.executeCommand("drop");
    // cout << "Player 1 score: " << gameEngine.grabCurrentScore() << endl;
    // cout << "High score: " << gameEngine.getHighScore() << endl;
    // board = gameEngine.currentBoard();
    // printBoard(board, 11, 18);

    gameEngine.executeCommand("J");
    // gameEngine.executeCommand("right", );
    gameEngine.executeCommand("clockwise", 20);
    gameEngine.executeCommand("right", 10);
    gameEngine.executeCommand("drop");
    cout << "Player 1 score: " << gameEngine.grabCurrentScore() << endl;
    cout << "High score: " << gameEngine.getHighScore() << endl;
    board = gameEngine.currentBoard();
    printBoard(board, 11, 18);
}

int main()
{
    test4();
    return 0;
}

// int main()
// {
//     GameEngine gameEngine(11, 18);
//     // Player 1's turn
//     cout << "Current player before drop: " << gameEngine.grabPlayer() << endl;
//     gameEngine.executeCommand("oBlock");
//     gameEngine.executeCommand("drop");
//     // Board *player1 = gameEngine.getPlayer1();
//     // printBoard(player1, 11, 18);
//     // cout << "Player 1 score: " << gameEngine.grabCurrentScore() << endl;
//     // cout << "High score: " << gameEngine.getHighScore() << endl;

//     return 0;
// }

/*
// Player 1's turn
cout << "Current player before drop: " << gameEngine.grabPlayer() << endl;
gameEngine.executeCommand("oBlock");
gameEngine.executeCommand("drop");
Board *player1 = gameEngine.getPlayer1();
printBoard(player1, 11, 18);
cout << "Player 1 score: " << gameEngine.grabCurrentScore() << endl;
cout << "High score: " << gameEngine.getHighScore() << endl;

// Switch to Player 2
gameEngine.setPlayer();
cout << "Current player after drop: " << gameEngine.grabPlayer() << endl;
gameEngine.executeCommand("lBlock");
gameEngine.executeCommand("clockwise", 1);
gameEngine.executeCommand("right", 1);
gameEngine.executeCommand("drop");
Board *player2 = gameEngine.getPlayer2();
printBoard(player2, 11, 18);
cout << "Player 2 score: " << gameEngine.grabCurrentScore() << endl;
cout << "High score: " << gameEngine.getHighScore() << endl;

// Player 1's turn again
gameEngine.setPlayer();
gameEngine.executeCommand("oBlock");
gameEngine.executeCommand("right", 2);
gameEngine.executeCommand("drop");
printBoard(player1, 11, 18);
cout << "Player 1 score: " << gameEngine.grabCurrentScore() << endl;
cout << "High score: " << gameEngine.getHighScore() << endl;
*/

// gameEngine.executeCommand("oBlock");
// gameEngine.executeCommand("validMove");
// gameEngine.executeCommand("drop");
// cout << "call 1" << endl;

// gameEngine.executeCommand("oBlock");
// gameEngine.executeCommand("right", 2);
// gameEngine.executeCommand("validMove");
// gameEngine.executeCommand("drop");
// cout << "call 2" << endl;
// gameEngine.executeCommand("oBlock");
// gameEngine.executeCommand("right", 4);
// gameEngine.executeCommand("validMove");
// gameEngine.executeCommand("drop");
// cout << "call 3" << endl;
// gameEngine.executeCommand("oBlock");
// gameEngine.executeCommand("right", 6);
// gameEngine.executeCommand("validMove");
// gameEngine.executeCommand("drop");
// cout << "call 4" << endl;
// gameEngine.executeCommand("oBlock");
// gameEngine.executeCommand("right", 8);
// gameEngine.executeCommand("validMove");
// gameEngine.executeCommand("drop");
// cout << "call 5" << endl;
// gameEngine.executeCommand("iBlock");
// gameEngine.executeCommand("clockwise", 1);
// gameEngine.executeCommand("right", 10);
// gameEngine.executeCommand("validMove");
// gameEngine.executeCommand("drop");
// cout << "call 5" << endl;

// gameEngine.executeCommand("oBlock");
// gameEngine.executeCommand("right", 3);
// cout << "before the drop" << endl;
// gameEngine.executeCommand("drop");

// Board *player1 = gameEngine.currentBoard();

// printBoard(player1, 11, 18);