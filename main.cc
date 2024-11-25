#include "board.h"
#include <string>
// all the includes

// Default sequence files and randomization seed
string defaultSequence1 = "sequence1.txt";
string defaultSequence2 = "sequence2.txt";
int defaultSeed = 416;

// Default board size
const int dimX = 11;
const int dimY = 18;

int main (int argc, const char *argv[]) {
    int startLevel = 0;
    bool textOnly = false;

    if (argc > 1) {
        for (int i = 1; i < argc; ++i) {
            if (argv[i][0] == '-') {

                // -text
                if (argv[i][1] == 't') {
                    textOnly = true;
                }

                // -s
            }
        }
    }

    // instantiate player 1 and player 2
    std::shared_ptr<Board> player1 = make_shared<Board>();
    std::shared_ptr<Board> player2 = make_shared<Board>();



    // parse sequence files


    // make text observers
    std::shared_ptr<TextDisplay> textView = std::make_shared<TextDisplay>(player1, player2, dimX, dimY);

    // make graphical observers if not textonly
    if (!textOnly) {
        std::shared_ptr<GraphicDisplay> graphicView = std::make_shared<GraphicDisplay>(player1, player2);
    }

    // NEED TO IMPLEMENT:
    // connect GameEngine and CommandController objects
} // main