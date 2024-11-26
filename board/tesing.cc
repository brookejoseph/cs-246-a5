#include "../board/board.h"
#include "../block/blockZ.h"
#include "../cell/cell.h"
#include <iostream>
#include <memory>
#include <vector>
#include <utility>

using namespace std;

int main()
{
    // Create a basic board
    Cell cell(18, 11);

    ZBlock zBlock(&cell, {0, 16}, {1, 16}, {1, 15}, {2, 15});

    // Test board functionality
    zBlock.setValue('Z', 0, 16);
    zBlock.setValue('Z', 1, 16);
    zBlock.setValue('Z', 1, 15);
    zBlock.setValue('Z', 2, 15);

    // Print the board
    for (int y = 17; y >= 0; --y)
    {
        for (int x = 0; x < 11; ++x)
        {
            std::cout << zBlock.getChar(x, y) << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}