#ifndef SUBJECT_H
#define SUBJECT_H
#include <vector>
#include <memory>

class Observer; // forward declaration

class Subject
{
    std::vector<Observer *> observers;

public:
    void attach(Observer *o); // done
    void detach(Observer *o); // done
    void notifyObservers();                   // done
    // virtual char getValue(int x, int y) = 0;  // done
    virtual ~Subject() = default; // done
};

#endif
