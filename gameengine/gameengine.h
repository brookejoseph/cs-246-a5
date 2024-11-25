#ifndef GAMEENGINE_H
#define GAMEENGINE_H
#include "board.h"
#include <memory>

class GameEngine {
    private:
        std::shared_ptr<Board> player1;
        std::shared_ptr<Board> player2;

        const bool textOnly;
        

    public:
        void start();
};

#endif
