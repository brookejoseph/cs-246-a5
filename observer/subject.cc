#include "subject.h"
#include "observer.h"

void Subject::attach(std::shared_ptr<Observer> o)
{
    observers.push_back(o);
}

void Subject::detach(std::shared_ptr<Observer> oo)
{
    for (auto it = observers.begin(); it != observers.end(); )
    {
        if (*it == o)
        {
            it = observers.erase(it);
        }
        else
        {
            ++it;
        }
    }
}

void Subject::notifyObservers()
{
    for (auto o: observers)
    {
        o->notify();
    }
}
