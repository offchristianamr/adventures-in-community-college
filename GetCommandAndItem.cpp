#include <string>

using namespace std;

string GetUserCommand(string command) {
    string userCommand;
    if (command.find(" ") == string::npos) {
        userCommand = command;
    }
    else {
        userCommand = command.substr(0, command.find(" "));
    }

    return userCommand;
}

string GetUserItem(string command) {
    string userItem;
    userItem = command.substr(command.find(" ") + 1, (command.size() - (command.find(" ") + 1)));
    return userItem;
}
