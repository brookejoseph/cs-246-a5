#include <vector>
#include <tuple>
#include <iostream>
#include <ostream>

class Cell
{
private:
    char c;

public:
    virtual char charAt(int x, int y) = 0;
    virtual ~Cell();
};