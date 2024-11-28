#include "../board/board.h"
#include "../textdisplay/textdisplay.h"
#include "../graphicdisplay/graphicdisplay.h"
#include <string>
#include <vector>
#include <memory>
#include <fstream>
#include <stdexcept>
// all the includes

// Default game options
bool textOnly = false;
int seed = 416;
std::string sequenceFile1 = "sequence1.txt";
std::string sequenceFile2 = "sequence2.txt";
int startLevel = 0;

// Default board dimensions
const int dimX = 11;
const int dimY = 18;

// Valid block types
const std::vector<char> blockTypes = {'I', 'J', 'L', 'O', 'S', 'Z', 'T'};

// in gameEngine:
// if command is norandom
// try {
//  newSequence = parseSequence(file);
//  board->setSequence(newSequence);
// }
// and then catch...
// setSequence would do setSequence for each of the levels in levelList

std::vector<char> parseSequence(std::string sequenceFile, const std::vector<char> &blockTypes)
{
    std::ifstream file{sequenceFile};
    std::vector<char> sequence;

    if (file.is_open())
    {
        char c;
        while (file >> c)
        {
            auto it = std::find(blockTypes.begin(); blockTypes.end(), c);
            if (it != blockTypes.end())
                sequence.push_back(c);
        }
    }
    else
    { // file is unable to open
        throw std::logic_error{"Error opening sequence file: " + sequenceFile};
    }

    // unable to parse given file
    if (sequence.size() == 0)
    {
        throw std::logic_error{"Invalid sequence file provided: " + sequenceFile};
    }

    return sequence;
}

int main(int argc, const char *argv[])
{

    // instantiate game and players
    GameEngine game{dimX, dimY};

    // try reading command-line arguments
    try
    {
        for (int i = 1; i < argc; ++i)
        {
            // - text
            if (argv[i] == "-text")
            {
                textOnly = true;

                // -seed
            }
            else if (argv[i] == "-seed")
            {
                if (i + 1 >= argc)
                {
                    throw std::logic_error{"Missing value for -seed"};
                }

                try
                {
                    seed = std::stoi(argv[++i]);
                    game->setSeed(seed);
                }

                catch (...)
                {
                    throw std::logic_error{"Missing value for -seed: must be an integer value"};
                }

                // -scriptfile1
            }
            else if (argv[i] == "-scriptfile1")
            {
                if (i + 1 >= argc)
                {
                    throw std::logic_error{"Missing value for -scriptfile1"};
                }

                sequenceFile1 = argv[++i];
                game->getPlayer1()->setSequence(game->parseSequence(sequenceFile1));

                // -scriptfile2
            }
            else if (argv[i] == "-scriptfile2")
            {
                if (i + 1 >= argc)
                {
                    throw std::logic_error{"Missing value for -scriptfile2"};
                }

                sequenceFile2 = argv[++i];
                game->getPlayer1()->setSequence(game->parseSequence(sequenceFile2));

                // -startlevel
            }
            else if (argv[i] == "-startlevel")
            {
                if (i + 1 >= argc)
                {
                    throw std::logic_error{"Missing value for -startlevel"};
                }

                try
                {
                    startLevel = std::stoi(argv[++i]);
                    if (startLevel < 0 || startLevel > 4)
                        throw std::logic_error();
                    game->getPlayer1()->setLevel(startLevel);
                    game->getPlayer2()->setLevel(startLevel);
                }

                catch (...)
                {
                    throw std::logic_error{"Missing value for -startlevel: must be an integer value 0-4"};
                }

                // invalid input
            }
            else
            {
                throw std::logic_error{"Unknown command-line argument: " + argv[i]};
            }
        }
    }

    // quit game if invalid command-line input
    catch (std::logic_error &e)
    {
        std::cout << e.what() << "\n";
        std::cout << "Usage: ./biquadris [-text] [-seed xxx] [-scriptfile1 xxx] [-scriptfile2 xxx] [-startlevel n]" << std::endl;
        return 1;
    }

    // make text observers
    std::shared_ptr<TextDisplay> textView = std::make_shared<TextDisplay>(game, dimX, dimY);
    game->attach(textView);

    // make graphical observers if not textOnly
    if (!textOnly)
    {
        std::shared_ptr<GraphicDisplay> graphicView = std::make_shared<GraphicDisplay>(game, dimX, dimY);
        game->attach(graphicView);
    }

    // play game
    game->start();

    // when game is over, detach observers
    game->detach(textView);
    if (!textOnly) { game->detach(graphicView); }

    return 0;

} // main