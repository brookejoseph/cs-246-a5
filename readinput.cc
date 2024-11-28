#include <string>
#include <iostream>
#include <sstream>
#include <vector>
#include <fstream>
#include "../gameengine/gameengine.h"

using namespace std;

// List of valid commands
vector<string> validCommands = {
    "left", "right", "down", "drop", "clockwise", "counterclockwise",
    "levelup", "leveldown", "norandom", "random", "sequence", "restart",
    "zBlock", "tBlock", "jBlock", "iBlock", "sBlock", "oBlock", "lBlock"};

// Helper function to find the closest matching command
string findMatchingCommand(const string &input)
{
    string matchedCommand;
    for (const string &cmd : validCommands)
    {
        if (cmd.find(input) == 0) // Check if the command starts with the input
        {
            if (!matchedCommand.empty())
            {
                return "invalid"; // Ambiguous input (matches multiple commands)
            }
            matchedCommand = cmd;
        }
    }
    return matchedCommand.empty() ? "invalid" : matchedCommand; // Return match or invalid
}

// Helper function to parse command and multiplier
pair<string, int> parseCommand(const string &input)
{
    int multiplier = 1;
    size_t pos = 0;

    // Extract numeric prefix
    while (pos < input.size() && isdigit(input[pos]))
    {
        pos++;
    }
    if (pos > 0)
    {
        multiplier = stoi(input.substr(0, pos));
    }

    // Extract the command portion and match it
    string command = findMatchingCommand(input.substr(pos));
    return {command, multiplier};
}

int main()
{
    GameEngine *newGame = new GameEngine(20, 23);
    string currentVal;

    while (cin >> currentVal)
    {
        // Parse the command and multiplier
        auto [command, multiplier] = parseCommand(currentVal);

        // Handle invalid commands gracefully
        if (command == "invalid")
        {
            cerr << "Invalid command: " << currentVal << endl;
            continue;
        }

        // Special cases for restart, norandom, random, and sequence
        if (command == "sequence")
        {
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
            newGame->executeCommand("norandom", 1); // Additional logic handled in GameEngine
            continue;
        }
        else if (command == "random" || command == "restart")
        {
            newGame->executeCommand(command, 1);
            continue;
        }

        // Execute valid commands with multiplier
        for (int i = 0; i < multiplier; ++i)
        {
            newGame->executeCommand(command, 1);
        }
    }

    delete newGame;
    return 0;
}
