#include "graphicdisplay.h"
#include <map>

std::map<char, int> charMap = {{'I', Xwindow::Blue},
                               {'J', Xwindow::Purple},
                               {'L', Xwindow::Orange},
                               {'O', Xwindow::Yellow},
                               {'S', Xwindow::Green},
                               {'Z', Xwindow::Red},
                               {'T', Xwindow::Magenta},
                               {' ', Xwindow::White}};

GraphicDisplay::GraphicDisplay(std::shared_ptr<GameEngine> game, int dimX, int dimY):
    game{game}, dimX{dimX}, dimY{dimY} {
    int width = (dimX * (pixelSize + pixelPadding) * 2) + sep + (8 * buffer);
    int height = (dimY * (pixelSize + pixelPadding)) + (16 * buffer);
    window = std::make_unique<Xwindow>(width, height);

    int player1X = buffer * 8;
    int player1Y = buffer * 4;

    int player2X = player1X + dimX * (pixelSize + pixelPadding) + sep;
    int player2Y = player1Y;

    window->fillRectangle(0, 0, width, height, Xwindow::Black);
    window->fillRectangle(player1X, player1Y, dimX * (pixelSize + pixelPadding), dimY * (pixelSize + pixelPadding), Xwindow::White);
    window->fillRectangle(player2X, player2Y, dimX * (pixelSize + pixelPadding), dimY * (pixelSize + pixelPadding), Xwindow::White);

    /*
    window->drawString("BIQUADRIS")

    window->drawString("High Score:")

    window->drawString("Level:")
    window->drawString("Level:")

    window->drawString("Level:")
    window->drawString("Level:")

    window->drawString("Next:")
    window->drawString("Next:")
    */
}

std::shared_ptr<GameEngine> GraphicDisplay::getGame() const {
    return game.lock();
}

void GraphicDisplay::drawValue(int x, int y, int val) {
    window->fillRectangle(x, y, pixelSize * 2, Xwindow::White);
    window->drawString(x, y, std::to_string(val));
}

void GraphicDisplay::drawCell(int x, int y, char c) {
    auto it = charMap.find(c);
    if (it != charMap.end()) {
        int colour = it->second;
        window->fillRectangle(x, y, pixelSize, pixelSize, colour);
    }
}

void GraphicDisplay::drawBoard() {
    std::vector<std::pair<int, int>> currentCoord = getGame()->currentBoard()->getCurrentBlockCoord();
    char currentBlockType = getGame()->currentBoard()->getCurrentBlockType();
    int x = buffer * 4;
    int y = buffer * 8;
    if (getGame()->grabPlayer() == 2) { x += dimX * (pixelSize + pixelPadding) + sep; }

    for (int j = 0; j < dimY; ++j) {
        for (int i = 0; i < dimX; ++i) {
            if (std::find(currentCoord.begin(), currentCoord.end(), std::make_pair(i, j)) != currentCoord.end()) {
                drawCell(x + i * (pixelSize + pixelPadding), y + j * (pixelSize + pixelPadding), currentBlockType);
            } else {
                drawCell(x + i * (pixelSize + pixelPadding), y + j * (pixelSize + pixelPadding), getGame()->currentBoard()->getChar(i, j));
            }
        }
    }
}

void GraphicDisplay::drawNextBlock() {
    char nextBlock = getGame()->currentBoard()->getNextBlockType();
    int x = buffer * 4;
    int y = dimY * (pixelSize + pixelPadding) + (8 * buffer);
    if (getGame()->grabPlayer() == 2) { x += dimX * (pixelSize + pixelPadding) + sep; }
    
    for (int j = 0; j < 2; ++j) {
        for (int i = 0; i < 4; ++i) {
            int xCoord = x + i * (pixelSize + pixelPadding);
            int yCoord = y + j * (pixelSize + pixelPadding);
            drawCell(xCoord, yCoord, nextBlock);
        }
    }

}

void GraphicDisplay::notify() {
    drawBoard();
    drawNextBlock();
}
