#include <vector>
#include <tuple>
#include <iostream>
#include <ostream>
#include "block.h"

using namespace std;

class BlockStar : public Block
{
public:
    BlockStar(std::shared_ptr<Board> cells,
              pair<int, int> a,
              pair<int, int> b,
              pair<int, int> c,
              pair<int, int> d); // to change
    BlockStar(int midpoint);
    BlockStar();
    BlockStar(std::shared_ptr<Board> cells);
    ~BlockStar() override = default;

    virtual char getChar(int x, int y) const override;
    virtual char getType() const override;
    // void drop() override;
};