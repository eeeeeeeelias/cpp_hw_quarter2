#include <iostream>
#include <string>

size_t CharacterLength(char character) {
    uint32_t ch = static_cast<uint32_t>(character);
    if (ch >> 7 == 0) {
        return 1;
    } else {
        ch = ~ch;
        size_t answer = 0;
        while (answer <= 6 && (ch >> (7 - answer)) == 0) {
            ++answer;
        }
        return answer;
    }
}

int main() {
    freopen("input.txt", "rt", stdin);
    std::string line;
    size_t lineCount = 0, characterCount = 0;
    while (std::getline(std::cin, line)) {
        ++lineCount;
        for (size_t i = 0; i < line.size();) {
           ++characterCount;
           i += CharacterLength(line[i]);
        }
    }
    std::cout << characterCount + lineCount - 1 << '\n';
}
