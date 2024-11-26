#ifndef SUBJECT_H
#define SUBJECT_H
#include <vector>
#include "../board/board.h"

class Observer; // forward declaration

class Subject : public Board
{
    std::vector<Observer *> observers;

public:
<<<<<<< Updated upstream
    void attach(Observer *o);            // done
    void detach(Observer *o);            // done
    void notifyObservers();              // done
    virtual char getState(int x, int y); // done
    virtual ~Subject() = default;        // done
=======
    void attach(Observer *o);                 // done
    void detach(Observer *o);                 // done
    void notifyObservers();                   // done
    virtual char getValue(int x, int y) = 0;  // done
    virtual ~Subject() = default;             // done
>>>>>>> Stashed changes
};

#endif
