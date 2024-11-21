#ifndef TEXTDISPLAY_H
#define TEXTDISPLAY_H
#include "observer.h"
#include "board.h"
#include <memory>

class TextDisplay: public Observer {
    std::weak_ptr<Board> subject;

    void printBoardHeader() const;
    void printBoardGrid() const;
    void printNextBlock() const;

    public:
        explicit TextDisplay(std::shared_ptr<Board> subject);
        ~TextDisplay();
        virtual void notify() override;
}

#endif
