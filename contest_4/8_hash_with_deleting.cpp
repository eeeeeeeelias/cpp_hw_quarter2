#include <iostream>
#include <unordered_set>

void DoCommand(char command, std::unordered_set<std::string>& mySet) {
    std::string currentLine;
    if (command != '#') {
        std::getline(std::cin, currentLine);
        currentLine = currentLine.substr(1);
        if (command == '+') {
            mySet.insert(currentLine);
        } else if (command == '-') {
            mySet.erase(currentLine);
        } else if (command == '?') {
            std::cout << (mySet.find(currentLine) != mySet.end() ? "YES" : "NO") << '\n';
        }
    }
}

int main() {
    freopen("input.txt", "rt", stdin);
    char command;
    std::unordered_set<std::string> lines;
    while (std::cin >> command) {
        DoCommand(command, lines);
    }
    return 0;
}

