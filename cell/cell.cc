#include <vector>
#include <tuple>
#include <iostream>
#include <ostream>
#include "cell.h"
class Cell
{
private:
    char c;

public:
    virtual char charAt(int x, int y);
    Cell(char initialValue = ' ') : c(initialValue) {}

    void setValue(char newValue)
    {
        c = newValue;
    }

    char getValue() const
    {
        return c;
    }
};