#ifndef TEXTDISPLAY_H
#define TEXTDISPLAY_H

#include "../observer/observer.h"
#include "../gameengine/gameengine.h"
#include <string>

class TextDisplay : public Observer
{
private:
    std::weak_ptr<GameEngine> game;

    int dimX;
    int dimY;
    int sep = 7; // how many chars to seperate boards

    std::shared_ptr<GameEngine> getGame() const;
    
    void printHeaders(const std::string &text) const;
    void printValues(const std::string &text, int value1, int value2) const;
    void printDashes() const;
    void printBoards() const;
    void printNextBlocks() const;

public:
    TextDisplay(std::shared_ptr<GameEngine> game, int dimX, int dimY);
    ~TextDisplay();
    virtual void notify() override;
};

#endif
