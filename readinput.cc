#include <string>
#include <iostream>
#include <sstream>
#include <vector>
#include <fstream>
#include "gameengine/gameengine.h"

using namespace std;

vector<string> validCommands = {
    "left", "right", "down", "drop", "clockwise", "counterclockwise",
    "levelup", "leveldown", "norandom", "random", "sequence", "restart",
    "zBlock", "tBlock", "jBlock", "iBlock", "sBlock", "oBlock", "lBlock"};

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

int main()
{
    GameEngine *newGame = new GameEngine(20, 23);
    cout << "game created " << endl;
    string currentVal;

    while (cin >> currentVal)
    {
        auto [command, multiplier] = parseCommand(currentVal);
        cout << "command within main" << command << endl;
        cout << "multipler within main" << multiplier << endl;

        if (command == "invalid")
        {
            cerr << "Invalid command: " << currentVal << endl;
            continue;
        }

        // Special cases for restart, norandom, random, and sequence
        if (command == "sequence")
        {
            cout << " within sequence main" << endl;
            string filename;
            cin >> filename;
            ifstream file(filename);
            if (file.is_open())
            {
                string line;
                while (getline(file, line))
                {
                    istringstream iss(line);
                    string subCommand;
                    while (iss >> subCommand)
                    {
                        auto [subCmd, subMult] = parseCommand(subCommand);
                        if (subCmd != "invalid")
                        {
                            for (int i = 0; i < subMult; ++i)
                            {
                                newGame->executeCommand(subCmd, 1);
                            }
                        }
                    }
                }
                file.close();
            }
            else
            {
                cerr << "Error: Could not open file " << filename << endl;
            }
            continue;
        }
        else if (command == "norandom")
        {
            string filename;
            cin >> filename;
            newGame->executeCommand("norandom", 1);
            continue;
        }
        else if (command == "random" || command == "restart")
        {
            newGame->executeCommand(command, 1);
            continue;
        }
        cout << "made it this far its you not me" << endl;
        newGame->executeCommand(command, multiplier);
    }
    cout << "made it this far its you not me 2 point 0 " << endl;

    delete newGame;
    return 0;
}
