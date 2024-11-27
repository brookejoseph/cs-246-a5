#ifndef GRAPHICDISPLAY_H
#define GRAPHICDISPLAY_H
#include "../observer/observer.h"
#include "../board/board.h"
#include "window.h"
#include <string>
#include <memory>


class GraphicDisplay: public Observer {
    private:
        std::weak_ptr<Board> player1;
        std::weak_ptr<Board> player2;

        int dimX;
        int dimY;

        int buffer = 20;
        int sep = 40;

        std::unique_ptr<Xwindow> window;

    public:
        GraphicDisplay(std::shared_ptr<Board> player1, std::shared_ptr<Board> player2, int dimX, int dimY);
        ~GraphicDisplay() = default;
        virtual void notify() override;
};


#endif
