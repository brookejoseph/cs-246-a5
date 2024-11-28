#ifndef TEXTDISPLAY_H
#define TEXTDISPLAY_H

#include "../observer/observer.h"
#include "../board/board.h"
#include "../gameengine/gameengine.h"
#include <string>
#include <memory>

using namespace std;

class TextDisplay : public Observer
{
private:
    std::weak_ptr<GameEngine> player1;
    std::weak_ptr<GameEngine> player2;

    int dimX;
    int dimY;
    int sep = 7; // how many chars to seperate boards
    
    std::shared_ptr<GameEngine> getPlayer1() const;
    std::shared_ptr<GameEngine> getPlayer2() const;
    
    void printHeaders(const std::string &text) const;
    void printValues(const std::string &text, int value1, int value2) const;
    void printDashes() const;
    void printBoards() const;
    void printNextBlocks() const;

public:
    TextDisplay(std::shared_ptr<GameEngine> player1, std::shared_ptr<GameEngine> player2, int dimX, int dimY);
    ~TextDisplay();
    virtual void notify() override;
};

#endif
