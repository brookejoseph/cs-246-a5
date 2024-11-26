#ifndef SUBJECT_H
#define SUBJECT_H
#include <vector>
#include "../board/board.h"

class Observer; // forward declaration

class Subject : public Board
{
    std::vector<Observer *> observers;

public:
    void attach(Observer *o);            // done
    void detach(Observer *o);            // done
    void notifyObservers();              // done
    virtual char getState(int x, int y); // done
    virtual ~Subject() = default;        // done
};

#endif
