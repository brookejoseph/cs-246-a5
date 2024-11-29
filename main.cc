#include "board/board.h"
#include "textdisplay/textdisplay.h"
// #include "graphicdisplay/graphicdisplay.h"
#include <string>
#include <vector>
#include <memory>
#include <fstream>
#include <sstream>
#include <stdexcept>
using namespace std;

// Default game options
bool textOnly = false;
int seed = 416;
string sequenceFile1 = "sequence1.txt";
string sequenceFile2 = "sequence2.txt";
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
    "Z", "T", "J", "I", "S", "O", "L", "blind", "force", "heavy"};

int charToBlockEnum(char blockType)
{
    switch (blockType)
    {
    case 'Z':
        return 1;
    case 'T':
        return 2;
    case 'J':
        return 3;
    case 'I':
        return 4;
    case 'S':
        return 5;
    case 'O':
        return 6;
    case 'L':
        return 7;
    default:
        throw std::invalid_argument("Invalid BlockType");
    }
}

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
            auto it = find(blockTypes.begin(), blockTypes.end(), c);
            if (it != blockTypes.end())
                sequence.push_back(c);
        }
    }
    else
    { // file is unable to open
        throw logic_error{"Error opening sequence file: " + string(sequenceFile)};
    }

    // unable to parse given file
    if (sequence.size() == 0)
    {
        throw logic_error{"Invalid sequence file provided: " + string(sequenceFile)};
    }

    return sequence;
}

void executeSequence(const string &sequenceFile, shared_ptr<GameEngine> game)
{
    ifstream file{sequenceFile};

    if (file.is_open())
    {
        string line;

        while (getline(file, line))
        {
            istringstream iss{line};
            string subCommand;

            while (iss >> subCommand)
            {
                auto [subCmd, subMult] = parseCommand(subCommand);

                if (subCmd != "invalid")
                {
                    if (subCmd == "drop")
                    {
                        game->executeCommand("drop");
                        if (!(game->getSpecial()))
                            game->setPlayer();
                        game->notifyObservers();
                    }
                    else
                    {
                        game->executeCommand(subCmd, subMult);
                    }
                }
            }
        }
    }
    else
    { // file is unable to open
        throw logic_error{"Invalid sequence file provided: " + string(sequenceFile)};
    }
}

int main(int argc, const char *argv[])
{

    // instantiate game and players
    shared_ptr<GameEngine> game = make_shared<GameEngine>(dimX, dimY);

    // try reading command-line arguments
    try
    {
        for (int i = 1; i < argc; ++i)
        {
            string arg = argv[i];
            // - text
            if (arg == "-text")
            {
                textOnly = true;

                // -seed
            }
            else if (arg == "-seed")
            {
                if (i + 1 >= argc)
                {
                    throw logic_error{"Missing value for -seed"};
                }

                try
                {
                    seed = stoi(argv[++i]);
                }

                catch (...)
                {
                    throw logic_error{"Missing value for -seed: must be an integer value"};
                }

                // -scriptfile1
            }
            else if (arg == "-scriptfile1")
            {
                if (i + 1 >= argc)
                {
                    throw logic_error{"Missing value for -scriptfile1"};
                }

                sequenceFile1 = argv[++i];

                // -scriptfile2
            }
            else if (arg == "-scriptfile2")
            {
                if (i + 1 >= argc)
                {
                    throw logic_error{"Missing value for -scriptfile2"};
                }

                sequenceFile2 = argv[++i];

                // -startlevel
            }
            else if (arg == "-startlevel")
            {
                if (i + 1 >= argc)
                {
                    throw logic_error{"Missing value for -startlevel"};
                }

                try
                {
                    startLevel = stoi(argv[++i]);
                    if (startLevel < 0 || startLevel > 4)
                        throw logic_error{"Missing value for -startlevel: must be an integer value 0-4"};
                    game->getPlayer1()->setLevel(startLevel);
                    game->getPlayer2()->setLevel(startLevel);
                }

                catch (...)
                {
                    throw logic_error{"Missing value for -startlevel: must be an integer value 0-4"};
                }

                // invalid input
            }
            else
            {
                throw logic_error{"Unknown command-line argument: " + string(argv[i])};
            }
        }

        srand(seed);
        game->getPlayer1()->setLvlSequence(parseSequence(sequenceFile1));
        game->getPlayer2()->setLvlSequence(parseSequence(sequenceFile2));
    }

    // quit game if invalid command-line input
    catch (logic_error &e)
    {
        cerr << e.what() << "\n";
        cerr << "Usage: ./biquadris [-text] [-seed xxx] [-scriptfile1 xxx] [-scriptfile2 xxx] [-startlevel n]" << endl;
        return 1;
    }

    // make text observers
    shared_ptr<TextDisplay> textView = make_shared<TextDisplay>(game, dimX, dimY);
    game->attach(textView);

    // make graphical observers if not textOnly
    if (!textOnly)
    {
        // std::shared_ptr<GraphicDisplay> graphicView = std::make_shared<GraphicDisplay>(game, dimX, dimY);
        // game->attach(graphicView);
    }

    // generate first blocks
    game->getPlayer1()->initBlocks();
    game->getPlayer2()->initBlocks();

    // game loop
    cout << "\nPlayer 1 sequence file: " << sequenceFile1 << "\n";
    cout << "Player 2 sequence file: " << sequenceFile2 << "\n";
    cout << "Random seed: " << seed << "\n";

    game->notifyObservers();

    bool continueGame = true;
    string input;

    while (continueGame)
    {
        if (game->getSpecial())
        {
            cout << "Player " << game->grabPlayer() << "'s turn, enter special action: ";
        }
        else
        {
            cout << "Player " << game->grabPlayer() << "'s turn, enter move: ";
        }
        if (!(cin >> input))
        {
            cout << "Exiting game . . .\n";
            continueGame = false;
            break;
        }
        auto [command, multiplier] = parseCommand(input);
        cout << "B: " << command << endl;

        if (command == "invalid")
        {
            cerr << "Invalid command: " << command << endl;
            // continue;
        }
        if (game->getSpecial() && command == "force")
        {
            char forceBlock;
            cin >> forceBlock;

            try
            {
                game->setPlayer();
                game->executeCommand(command, charToBlockEnum(forceBlock));
                game->setSpecial(false);
                game->notifyObservers();
            }

            catch (...)
            {

                cerr << "Invalid block type for force" << endl;
            }

            continue;
        }
        else if (game->getSpecial() && command == "heavy")
        {
            game->setPlayer();
            game->executeCommand(command);
            game->setSpecial(false);
            game->notifyObservers();
            continue;
        }
        else if (game->getSpecial() && command == "blind")
        {
            game->setPlayer();
            game->executeCommand(command);
            game->setSpecial(false);
            game->notifyObservers();
            continue;
        }
        else if (command == "drop")
        {
            game->executeCommand("drop");
            if (!(game->getSpecial()))
                game->setPlayer();
            game->notifyObservers();
            continue;

            // sequence
        }
        else if (input == "sequence")
        {
            string file;
            cin >> file;

            try
            {
                executeSequence(file, game);
            }

            catch (logic_error &e)
            {
                cerr << e.what() << endl;
            }

            continue;

            // norandom
        }
        else if (command == "norandom")
        {
            string file;
            cin >> file;

            try
            {
                game->currentBoard()->setLvlSequence(parseSequence(file));
                game->currentBoard()->setRandom(false);
            }

            catch (logic_error &e)
            {
                cerr << e.what() << endl;
            }

            continue;

            // random
        }
        else if (command == "random")
        {
            game->currentBoard()->setRandom(true);
            continue;

            // restart
        }
        else if (command == "restart")
        {
            game->executeCommand(command);
            continue;

            // special actions out of turn
        }
        else if ((!(game->getSpecial())) && command == "heavy" || command == "force" || command == "blind")
        {
            cerr << "Cannot trigger special action: " + command << "\n";
            continue;
        }

        game->executeCommand(command, multiplier);
    } // while

    // when game is over, detach observers
    game->detach(textView);
    // if (!textOnly) { game->detach(graphicView); }

    return 0;

} // main
