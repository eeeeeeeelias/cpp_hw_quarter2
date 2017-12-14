#include <algorithm>
#include <cstdint>
#include <functional>
#include <iostream>
#include <string>
#include <vector>

struct Flags{
    bool _blanks = false;
    bool _digital = false;
    bool _ignore = false;
    bool _reverse = false;
};

struct Line{
    std::string line = "";
    int64_t number = 0;
    bool hasGeneralNumber = false;
};

void LStrip(std::string& input) {
    size_t i = 0;
    for (; input[i] == ' ' && i != input.size(); ++i) {}
    if (i == input.size()) {
        input = "";
    } else {
        input = input.substr(i);
    }
}

void ToLowercase(std::string& input) {
    std::string output = "";
    for (size_t i = 0; i != input.size(); ++i) {
        output.push_back(std::tolower(input[i]));
    }
    input = output;
}

bool Comparator(const Line& line1, const Line& line2, const Flags& flags) {
    Line copy1 = line1;
    Line copy2 = line2;
    bool answer = true;
    if (flags._blanks) {
        LStrip(copy1.line);
        LStrip(copy2.line);
    }
    if (flags._ignore) {
        ToLowercase(copy1.line);
        ToLowercase(copy2.line);
    }
    if (flags._reverse) {
        std::swap(copy1, copy2);
    }
    if (flags._digital) {
        if (copy1.hasGeneralNumber && !copy2.hasGeneralNumber) {
            return false;
        } else if (!copy1.hasGeneralNumber && copy2.hasGeneralNumber) {
            return true;
        } else if (copy1.hasGeneralNumber && copy2.hasGeneralNumber) {
            if (copy1.number == copy2.number) {
                return copy1.line < copy2.line;
            }
            return copy1.number < copy2.number;
        } else {
            return copy1.line < copy2.line;
        }
    } else {
        return copy1.line < copy2.line;
    }
}

bool GeneralNumber(const std::string& line, int64_t& number) {
    bool isNegative = false;
    if (line == "") {
        return false;
    }
    size_t i = 0;
    for (; line[i] == ' ' && i != line.size(); ++i) {}
    if (i == line.size()) {
        return false;
    }
    if (line[i] != '-' && !std::isdigit(line[i])) {
        return false;
    }
    if (line[i] == '-') {
        if (i + 1 == line.size()) {
            return false;
        }
        if (!std::isdigit(line[i + 1])) {
            return false;
        }
        ++i;
        isNegative = true;
    }
    number = 0;
    while (std::isdigit(line[i])) {
        number = number * 10 + (line[i] - '0');
        ++i;
        if (i == line.size()) {
            break;
        }
    }
    if (isNegative) {
        number *= -1;
    }
    return true;
}

std::vector<Line> ReadFile() {
    std::vector<Line> lines;
    Line currentLine;
    std::string rawLine;
    int64_t generalNumber;
    while (std::getline(std::cin, currentLine.line)) {
        currentLine.hasGeneralNumber = GeneralNumber(currentLine.line, currentLine.number);
        lines.push_back(currentLine);
    }
    return lines;
}

Flags ReadFlags() {
    Flags flags;
    std::string flagLine;
    std::getline(std::cin, flagLine);
    while (flagLine.find('-') != std::string::npos) {
        size_t pos = flagLine.find('-') + 1;
        char flag = flagLine[pos];
        if (flag == 'b') {
            flags._blanks = true;
        } else if (flag == 'f') {
            flags._ignore = true;
        } else if (flag == 'g') {
            flags._digital = true;
        } else if (flag == 'r') {
            flags._reverse = true;
        }
        flagLine = flagLine.substr(pos);
    }
    return flags;
}

template <typename TFile>
void PrintFile(TFile& lines) {
    for (size_t i = 0; i != lines.size(); ++i) {
        std::cout << lines[i].line << '\n';
    }
}

int main() {
    freopen("input.txt", "rt", stdin);
    Flags flags = ReadFlags();
    auto lines = ReadFile();
    std::sort(
            lines.begin(),
            lines.end(),
            std::bind(Comparator, std::placeholders::_1, std::placeholders::_2, flags));
    PrintFile(lines);
}

