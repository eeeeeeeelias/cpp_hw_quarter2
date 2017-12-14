#include <iostream>
#include <vector>

void ReadLines(std::vector<std::string>& lines) {
    for (size_t i = 0; i != lines.size(); ++i) {
        std::getline(std::cin, lines[i]);
    }
}

int main() {
    size_t numLines;
    std::cin >> numLines;
    std::string lineToCompare;
    std::getline(std::cin, lineToCompare);
    std::vector<std::string> lines(numLines);
    ReadLines(lines);

    for (size_t i = 0; i != numLines; ++i) {
        std::getline(std::cin, lineToCompare);
        if (lineToCompare != lines[i]) {
            std::cout << i << '\n';
        }
    }
}
