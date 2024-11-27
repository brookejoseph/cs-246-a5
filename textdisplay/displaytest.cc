#include "textdisplay.h"
#include "../board/board.h"
#include <memory>

const int dimX = 11;
const int dimY = 18;

int main() {
    std::shared_ptr<Board> player1(new Board(dimX, dimY));
    std::shared_ptr<Board> player2(new Board(dimX, dimY));

    std::shared_ptr<TextDisplay> td(new TextDisplay{player1, player2, dimX, dimY});

    player1->attach(td);
    player2->attach(td);

    player1->notifyObservers();

    player1->setValue('D', 1, 1);

    player2->notifyObservers();

    player1->detach(td);
    player2->detach(td);
}