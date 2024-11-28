#include <string>
#include "../gameengine/gameengine.h"
#include <string>
#include <iostream>
#include <sstream>
#include <fstream>
#include <functional>

using namespace std;

int main()
{
    GameEngine *newGame = new GameEngine(20, 23);
    string currentVal;

    while (cin >> currentVal)
    {
        int multiplier = 1;
        string command;

        size_t pos = 0;
        while (pos < currentVal.size() && isdigit(currentVal[pos]))
        {
            pos++;
        }
        if (pos > 0)
        {
            multiplier = stoi(currentVal.substr(0, pos));
        }
        command = currentVal.substr(pos);

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
                        newGame->executeCommand(subCommand, 1);
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
        else if (command == "random")
        {
            newGame->executeCommand("random", 1);
            continue;
        }
        else if (command == "norandom")
        {
            string filename;
            cin >> filename;
            newGame->executeCommand("norandom", 1);
            continue;
        }
        else if (command == "restart")
        {
            newGame->executeCommand("restart", 1);
            continue;
        }

        for (int i = 0; i < multiplier; ++i)
        {
            newGame->executeCommand(command, 1);
        }
    }

    delete newGame;
    return 0;
}
