#include "../board/board.h"
#include "../textdisplay/textdisplay.h"
#include "../graphicdisplay/graphicdisplay.h"
#include <string>
#include <vector>
#include <memory>
#include <fstream>
#include <stdexcept>
// all the includes

using namespace std;

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
const vector<char> blockTypes = {'I', 'J', 'L', 'O', 'S', 'Z', 'T'};

// Valid commands from standard input
vector<string> validCommands = {
    "left", "right", "down", "drop", "clockwise", "counterclockwise",
    "levelup", "leveldown", "norandom", "random", "sequence", "restart",
    "Z", "T", "J", "I", "S", "O", "L"};


string findMatchingCommand(const string &input)
{
    string matchedCommand;
    for (const string &cmd : validCommands)
    {
        if (cmd.find(input) == 0)
        {
            if (!matchedCommand.empty())
            {
                return "invalid";
            }
            matchedCommand = cmd;
        }
    }
    return matchedCommand.empty() ? "invalid" : matchedCommand;
}

pair<string, int> parseCommand(const string &input)
{
    int multiplier = 1;
    size_t pos = 0;

    while (pos < input.size() && isdigit(input[pos]))
    {
        pos++;
    }
    if (pos > 0)
    {
        multiplier = stoi(input.substr(0, pos));
    }

    string command = findMatchingCommand(input.substr(pos));
    return {command, multiplier};
}

vector<char> parseSequence(const string &sequenceFile)
{
    ifstream file{sequenceFile};
    vector<char> sequence;

    if (file.is_open())
    {
        char c;
        while (file >> c)
        {
            auto it = find(blockTypes.begin(); blockTypes.end(), c);
            if (it != blockTypes.end())
                sequence.push_back(c);
        }
    }
    else
    { // file is unable to open
        throw logic_error{"Error opening sequence file: " + sequenceFile};
    }

    // unable to parse given file
    if (sequence.size() == 0)
    {
        throw logic_error{"Invalid sequence file provided: " + sequenceFile};
    }

    return sequence;
}

void executeSequence(const string &sequenceFile, const GameEngine &game) {
    ifstream file{sequenceFile};

    if (file.is_open()) {
        string line;

        while(getline(file, line)) {
            istreamstring iss(line);
            string subCommand;

            while (iss >> subCommand) {
                auto [subCmd, subMult] = parseCommand(subCommand);

                if (subCmd != "invalid") {
                    game.executeCommand(subCmd, subMult);
                }
            }
        }
    } else { // file is unable to open
        throw logic_error{"Invalid sequence file provided: " + sequenceFile};
    }
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
                    throw logic_error{"Missing value for -seed"};
                }

                try
                {
                    seed = stoi(argv[++i]);
                    srand(seed);
                }

                catch (...)
                {
                    throw logic_error{"Missing value for -seed: must be an integer value"};
                }

                // -scriptfile1
            }
            else if (argv[i] == "-scriptfile1")
            {
                if (i + 1 >= argc)
                {
                    throw logic_error{"Missing value for -scriptfile1"};
                }

                sequenceFile1 = argv[++i];
                game.getPlayer1()->setSequence(parseSequence(sequenceFile1));

                // -scriptfile2
            }
            else if (argv[i] == "-scriptfile2")
            {
                if (i + 1 >= argc)
                {
                    throw logic_error{"Missing value for -scriptfile2"};
                }

                sequenceFile2 = argv[++i];
                game.getPlayer1()->setSequence(parseSequence(sequenceFile2));

                // -startlevel
            }
            else if (argv[i] == "-startlevel")
            {
                if (i + 1 >= argc)
                {
                    throw logic_error{"Missing value for -startlevel"};
                }

                try
                {
                    startLevel = stoi(argv[++i]);
                    if (startLevel < 0 || startLevel > 4) throw logic_error();
                    game.getPlayer1()->setLevel(startLevel);
                    game.getPlayer2()->setLevel(startLevel);
                }

                catch (...)
                {
                    throw logic_error{"Missing value for -startlevel: must be an integer value 0-4"};
                }

                // invalid input
            }
            else
            {
                throw logic_error{"Unknown command-line argument: " + argv[i]};
            }
        }
    }

    // quit game if invalid command-line input
    catch (std::logic_error &e)
    {
        err << e.what() << "\n";
        err << "Usage: ./biquadris [-text] [-seed xxx] [-scriptfile1 xxx] [-scriptfile2 xxx] [-startlevel n]" << std::endl;
        return 1;
    }

    // make text observers
    std::shared_ptr<TextDisplay> textView = std::make_shared<TextDisplay>(game, dimX, dimY);
    game.attach(textView);

    // make graphical observers if not textOnly
    if (!textOnly)
    {
        //std::shared_ptr<GraphicDisplay> graphicView = std::make_shared<GraphicDisplay>(game, dimX, dimY);
        //game->attach(graphicView);
    }

    // generate first blocks
    game.getPlayer1()->initBlocks();
    game.getPlayer2()->initBlocks();

    // game loop
    game.notifyObservers();

    bool continueGame = true;
    string input;

    while (continueGame) {
        cout << "Player " << game.getCurrentPlayer() << "'s turn, enter move: ";

        // check for EOF and quit game
        if (!(cin >> input)) {
            cout << "Exiting game . . .\n";
            continueGame = false;
            break;
        }

        // run command from input
        auto [command, multiplier] = parseCommand(input);

        if (command == "invalid") {
            cerr << "Invalid command: " << input << endl;
            continue;
        }

        // special cases for drop, sequence, norandom, random, sequence

        // drop
        if (command == "drop") {
            game.executeCommand("drop");
            game.setPlayer();
            continue;

        // sequence
        } else if (input == "sequence") {
            string file;
            cin >> file;

            try {
                parseCommandFile(file);
            }

            catch (logic_error &e) {
                err << e.what() << endl;
            }

            continue;

        // norandom
        } else if (command == "norandom") {
            string file;
            cin >> file;

            try {
                game.currentBoard()->setLvlSequence(parseSequence(file));
                game.currentBoard()->setRandom(false);
            }

            catch (logic_error &e) {
                err << e.what() << endl;
            }

            continue;

        // random
        } else if (command == "random") {
            game.currentBoard()->setRandom(true);
            continue;
        
        // restart
        } else if (command == "restart") {
            game.executeCommand(command);
            continue;
        }
        game.executeCommand(command, multiplier);
    } // while

    // when game is over, detach observers
    game.detach(textView);
    //if (!textOnly) { game->detach(graphicView); }

    return 0;

} // main
