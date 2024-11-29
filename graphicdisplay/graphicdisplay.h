#ifndef GRAPHICDISPLAY_H
#define GRAPHICDISPLAY_H
#include "../observer/observer.h"
#include "../gameengine/gameengine.h"
#include "window.h"
#include <string>
#include <memory>

class GraphicDisplay: public Observer {
    private:
        std::weak_ptr<GameEngine> game;

        int dimX;
        int dimY;

        const int pixelSize = 20;
        const int pixelPadding = 1;
        const int buffer = 20;
        const int sep = 160;

        std::unique_ptr<Xwindow> window;

        std::shared_ptr<GameEngine> getGame() const;

        void drawValue(int x, int y, int val);
        void drawCell(int x, int y, char c);
        void drawBoard();
        void drawNextBlock();

    public:
        GraphicDisplay(std::shared_ptr<GameEngine> game, int dimX, int dimY);
        ~GraphicDisplay() = default;
        virtual void notify() override;
};


#endif
