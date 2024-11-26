#include "textdisplay.h"
#include "../board/board.h"
#include <memory>

const int dimX = 11;
const int dimY = 18;

int main() {
    std::shared_ptr<Board> player1(new Board(dimX, dimY));
    std::shared_ptr<Board> player2(new Board(dimX, dimY));

    TextDisplay td{player1, player2, dimX, dimY};

    player1->notifyObservers();
}