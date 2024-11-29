#include "graphicdisplay.h"

GraphicDisplay::GraphicDisplay(std::shared_ptr<Board> player1, std::shared_ptr<Board> player2, int dimX, int dimY):
    player1{player1}, player2{player2}, dimX{dimX}, dimY{dimY} {
    //int width = 
    //int height = 
    //window = std::make_unique<XWindow>(new XWindow{width, height});
}

void GraphicDisplay::notify() {

}
