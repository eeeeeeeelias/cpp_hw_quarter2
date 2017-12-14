#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

struct Flags{
    bool rev = false, tac = false;
};

Flags ReadFlags() {
    Flags flags;
    std::string flagLine;
    std::getline(std::cin, flagLine);
    if (flagLine.find("rev") != std::string::npos) {
        flags.rev = true;
    }
    if (flagLine.find("tac") != std::string::npos) {
        flags.tac = true;
    }
    return flags;
}

std::vector<std::string> ReadFile() {
    std::vector<std::string> lines;
    std::string currentLine;
    while (std::getline(std::cin, currentLine)) {
        lines.push_back(currentLine);
    }
    return lines;
}

template <typename TFile>
void PrintFile(const TFile& lines) {
    for (auto line : lines) {
        std::cout << line << '\n';
    }
}

int main() {
    freopen("input.txt", "rt", stdin);
    Flags flags = ReadFlags();
    auto lines = ReadFile();
    if (flags.tac) {
        std::reverse(lines.begin(), lines.end());
    }
    if (flags.rev) {
        for (size_t i = 0; i != lines.size(); ++i) {
            std::reverse(lines[i].begin(), lines[i].end());
        }
    }
    PrintFile(lines);
}

