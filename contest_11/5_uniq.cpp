#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

struct Flags{
    bool _count = false;
    bool _ignore = false;
    bool _repeated = false;
    bool _unique = false;
};

std::string ToLowercase(const std::string& input, bool toChange) {
    if (toChange) {
        std::string output;
        for (size_t i = 0; i != input.size(); ++i) {
            output.push_back(std::tolower(input[i]));
        }
        return output;
    } else {
        return input;
    }
}

Flags ReadFlags() {
    Flags flags;
    std::string flagLine;
    std::getline(std::cin, flagLine);
    while (flagLine.find('-') != std::string::npos) {
        size_t pos = flagLine.find('-') + 1;
        char flag = flagLine[pos];
        if (flag == 'c') {
            flags._count = true;
        } else if (flag == 'd') {
            flags._repeated = true;
        } else if (flag == 'i') {
            flags._ignore = true;
        } else if (flag == 'u') {
            flags._unique = true;
        }
        flagLine = flagLine.substr(++pos);
    }
    return flags;
}

std::vector<std::string> ReadFile(Flags& flags) {
    std::vector<std::string> lines;
    std::string currentLine;
    while (std::getline(std::cin, currentLine)) {
        lines.push_back(currentLine);
    }
    lines.push_back("#45");
    return lines;
}

template <typename TFile>
void PrintResults(const TFile& lines, const Flags& flags) {
    size_t countRepeats = 1;
    for (size_t iLine = 0; iLine != lines.size() - 1; ++iLine) {
        if (ToLowercase(lines[iLine], flags._ignore)
                != ToLowercase(lines[iLine + 1], flags._ignore)) {
            if (!(countRepeats > 1 && flags._unique)
                    && !(countRepeats == 1 && flags._repeated)) {
                if (flags._count) {
                    if (countRepeats < 10) {
                        std::cout << "      ";
                    } else if (countRepeats < 100) {
                        std::cout << "     ";
                    } else {
                        std::cout << "    ";
                    }
                    std::cout << countRepeats << " ";
                }
                std::cout << lines[iLine - countRepeats + 1] << '\n';
            }
            countRepeats = 1;
        } else {
            ++countRepeats;
        }
    }
}

int main() {
    freopen("input.txt", "rt", stdin);
    Flags flags = ReadFlags();
    if (!(flags._repeated && flags._unique)) {
        auto lines = ReadFile(flags);
        PrintResults(lines, flags);
    }
}

