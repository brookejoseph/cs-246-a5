#ifndef TEXTDISPLAY_H
#define TEXTDISPLAY_H
#include "../observer/observer.h"
#include "../board/board.h"
#include <string>
#include <memory>

class TextDisplay : public Observer
{
private:
    std::weak_ptr<Board> player1;
    std::weak_ptr<Board> player2;

    int dimX;
    int dimY;
    int sep = 7; // how many chars to seperate boards
    
    std::shared_ptr<Board> getBoard(std::weak_ptr<Board> board) const;
    void printHeaders(const std::string &text) const;
    void printValues(const std::string &text, int value1, int value2) const;
    void printDashes() const;
    void printBoards() const;
    void printNextBlocks() const;

public:
    TextDisplay(std::shared_ptr<Board> player1, std::shared_ptr<Board> player2, int dimX, int dimY);
    ~TextDisplay();
    virtual void notify() override;
};

#endif
