#include <iostream>
#include <string>

int main() {
    freopen("input.txt", "rt", stdin);
    std::string flag, key, currentLine;
    std::cin >> flag >> key;
    std::getline(std::cin, currentLine);
    bool has = flag == "-f";
    while (std::getline(std::cin, currentLine)) {
        if (has && currentLine.find(key) != std::string::npos) {
            std::cout << currentLine << '\n';
        }
        if (!has && currentLine.find(key) == std::string::npos) {
            std::cout << currentLine << '\n';
        }
    }
}

