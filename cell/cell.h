#ifndef CELL_H
#define CELL_H

class Cell
{
public:
    virtual ~Cell();
    virtual char getValue(int x, int y) = 0;
};

#endif
