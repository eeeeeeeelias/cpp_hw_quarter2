#include <iostream>
#include <string>
#include <vector>

struct Flags {
    bool
        dollar = false,
        lineNumbering = false,
        deleteEmptyLines = false,
        tabs = false;
};

void ReadFlags(Flags& flags) {
    std::string flagLine;
    std::getline(std::cin, flagLine);
    while (flagLine.find('-') != std::string::npos) {
        size_t pos = flagLine.find('-');
        char flag = flagLine[++pos];
        if (flag == 'E') {
            flags.dollar = true;
        } else if (flag == 'n') {
            flags.lineNumbering = true;
        } else if (flag == 's') {
            flags.deleteEmptyLines = true;
        } else if (flag == 'T') {
            flags.tabs = true;
        }
        flagLine = flagLine.substr(pos);
    }
}

void ReadFile(std::vector<std::string>& lines) {
    std::string line;
    while (std::getline(std::cin, line)) {
        lines.push_back(line);
    }
}

void PrintFile(const std::vector<std::string>& lines, const Flags& flags) {
    size_t currentLine = 0;
    for (size_t i = 0; i != lines.size(); ++i) {
        if (flags.deleteEmptyLines && lines[i] == "") {
            if (i != 0) {
                if (lines[i - 1] == "") {
                    continue;
                }
            }
        }
        ++currentLine;
        if (flags.lineNumbering) {
            if (currentLine < 10) {
                std::cout << "     " << currentLine << '\t';
            } else if (currentLine < 100) {
                std::cout << "    " << currentLine << '\t';
            } else {
                std::cout << "   " << currentLine << '\t';
            }
        }
        for (size_t j = 0; j != lines[i].size(); ++j) {
            if (flags.tabs && lines[i][j] == '\t') {
                std::cout << "^I";
            } else {
                std::cout << lines[i][j];
            }
        }
        if (flags.dollar) {
            std::cout << '$';
        }
        std::cout << '\n';
    }
}

int main() {
    freopen("input.txt", "rt", stdin);
    Flags flags;
    ReadFlags(flags);
    std::vector<std::string> lines;
    ReadFile(lines);
    PrintFile(lines, flags);
}

