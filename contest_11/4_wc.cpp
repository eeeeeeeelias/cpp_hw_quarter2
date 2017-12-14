#include <algorithm>
#include <iostream>
#include <string>

struct Flags{
    bool _symbols = false;
    size_t symbols = 0;
    bool _lines = false;
    size_t lines = 0;
    bool _longest = false;
    size_t longest = 0;
    bool _words = false;
    size_t words = 0;
};

Flags ReadFlags() {
    Flags flags;
    std::string flagLine;
    std::getline(std::cin, flagLine);
    while (flagLine.find('-') != std::string::npos) {
        size_t pos = flagLine.find('-') + 1;
        char flag = flagLine[pos];
        if (flag == 'm') {
            flags._symbols = true;
        } else if (flag == 'l') {
            flags._lines = true;
        } else if (flag == 'L') {
            flags._longest = true;
        } else if (flag == 'w') {
            flags._words = true;
        }
        flagLine = flagLine.substr(++pos);
    }
    return flags;
}

void ReadFile(Flags& flags) {
    std::string currentLine;
    while (std::getline(std::cin, currentLine)) {
        flags.longest = std::max(flags.longest, currentLine.size());
        flags.symbols += currentLine.size();
        ++flags.lines;
        size_t i = 0;
        while (i != currentLine.size()) {
            for (; currentLine[i] == ' ' && i != currentLine.size(); ++i) {}
            for (; currentLine[i] != ' ' && i != currentLine.size(); ++i) {}
            if (i < currentLine.size() || currentLine[currentLine.size() - 1] != ' ') {
                ++flags.words;
            }
        }
    }
    flags.symbols += flags.lines;
}

void PrintResults(const Flags& flags) {
    if (flags._lines) {
        std::cout << flags.lines << ' ';
    }
    if (flags._words) {
        std::cout << flags.words << ' ';
    }
    if (flags._symbols) {
        std::cout << flags.symbols << ' ';
    }
    if (flags._longest) {
        std::cout << flags.longest << ' ';
    }
    std::cout << '\n';
}

int main() {
    freopen("input.txt", "rt", stdin);
    Flags flags = ReadFlags();
    ReadFile(flags);
    PrintResults(flags);
}
