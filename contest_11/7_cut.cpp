#include <iostream>
#include <string>
#include <vector>

std::string getRow(std::string& currentLine, int rowNumber) {
    if (rowNumber < 1) {
        return "";
    }
    for (int i = 1; i != rowNumber; ++i) {
        if (currentLine.find('\t') != std::string::npos) {
            currentLine = currentLine.substr(currentLine.find('\t') + 1);
        } else {
            return "";
        }
    }
    if (currentLine.find('\t') != std::string::npos) {
        return currentLine.substr(0, currentLine.find('\t'));
    }
    return currentLine;
}

int main() {
    std::string flagLine;
    std::getline(std::cin, flagLine);
    if (flagLine == "") {
        std::string currentLine;
        while (std::getline(std::cin, currentLine)) {
            std::cout << currentLine << '\n';
        }
    } else {
        flagLine = flagLine.substr(flagLine.find(' ') + 1);
        int rowNumber = stoi(flagLine);
        std::string currentLine;
        while (std::getline(std::cin, currentLine)) {
            std::cout << getRow(currentLine, rowNumber) << '\n';
        }
    }
}
