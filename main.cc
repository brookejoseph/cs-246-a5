#include "board/board.h"
#include "textdisplay/textdisplay.h"
#include "graphicdisplay/graphicdisplay.h"
#include <string>
#include <vector>
#include <memory>
#include <fstream>
#include <stdexcept>
// all the includes

// Sequence files and randomization seed
std::string sequenceFile1 = "sequence1.txt";
std::string sequenceFile2 = "sequence2.txt";
int seed = 416;

// Default board size
const int dimX = 11;
const int dimY = 18;

// Valid command-line arguments
const std::vector<std::string> commands = {"text", "seed", "scriptfile1", "scriptfile2", "startlevel"};

// Block types
const std::vector<char> blockTypes = {'I', 'J', 'L', 'O', 'S', 'Z', 'T'};


// in gameEngine:
// if command is norandom
// try {
//  newSequence = parseSequence(file);
//  board->setSequence(newSequence);
// }
// and then catch...
// setSequence would do setSequence for each of the levels in levelList

std::vector<char> parseSequence(std::string sequenceFile, const std::vector<char> &blockTypes) {
    std::ifstream file {sequenceFile};
    std::vector<char> sequence;

    if (file.is_open()) {
        char c;
        while (f >> c) {
            auto it = std::find(blockType.begin(); blockType.end(), c);
            if (it != blockType.end()) sequence.push_back(c);
        }

    } else { // File is unable to open
        throw std::logic_error{"Error opening sequence file: " + sequenceFile};
    }

    // Unable to parse given file
    if (sequence.length() == 0) {
        throw std::logic_error{"Invalid sequence file provided: " + sequenceFile};
    }

    return sequence;
}


int main(int argc, const char *argv[]) {
    int startLevel = 0;
    bool textOnly = false;

    GameEngine game{dimX, dimY};

    if (argc > 1) {
        try {
            for (int i = 1; i < argc; ++i) {
                if (argv[i][0] == '-') {

                    // -text
                    // textOnly = true;

                    // -seed
                    //

                    // -scriptfile
                    // game->parseSequence(xxx);
                    
                    // -startlevel
                    // throw std::logic_error("Level number must be 0-4");
                }
            }
        }
    }

    // quit game if invalid command-line input
    catch (std::logic_error &e) {
        std::cout << e.what() << std::endl;
        return 0;
    }

    // instantiate player 1 and player 2
    std::shared_ptr<Board> player1 = std::make_shared<Board>();
    std::shared_ptr<Board> player2 = std::make_shared<Board>();


    // parse sequence files


    // make text observers
    std::shared_ptr<TextDisplay> textView = std::make_shared<TextDisplay>(player1, player2, dimX, dimY);
    player1->attach(textView);
    player2->attach(textView);

    // make graphical observers if not textonly
    if (!textOnly) {
        std::shared_ptr<GraphicDisplay> graphicView = std::make_shared<GraphicDisplay>(player1, player2);
        player1->attach(graphicView);
        player2->attach(graphicView);
    }

    // NEED TO IMPLEMENT:
    // connect GameEngine and CommandController objects
    // game->start();

} // main