#ifndef TEXTDISPLAY_H
#define TEXTDISPLAY_H
#include "observer.h"
#include "board.h"
#include <memory>

class TextDisplay: public Observer {
    std::weak_ptr<Board> player1;
    std::weak_ptr<Board> player2;

    void printBoardHeaders() const;
    void printBoards() const;
    void printNextBlocks() const;

    public:
        TextDisplay(std::shared_ptr<Board> player1, std::shared_ptr<Board> player2);
        ~TextDisplay();
        virtual void notify() override;
}

#endif
