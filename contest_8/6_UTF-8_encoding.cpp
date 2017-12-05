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

size_t GetCode(const std::string& line, size_t charBegin, size_t charLength) {
    if (charLength > 1) {
        size_t answer = static_cast<size_t>(line[charBegin]);
        answer <<= charLength + 1;
        answer &= (1 << 8) - 1;
        answer >>= charLength + 1;
        for (size_t i = charBegin + 1; i < charBegin + charLength; ++i) {
            answer <<= 6;
            answer += static_cast<size_t>(line[i]) & ((1 << 6) - 1);
        }
        return answer;
    } else {
        return static_cast<size_t>(line[charBegin]);
    }
}

int main() {
    freopen("input.txt", "rt", stdin);
    std::string line;
    while (std::getline(std::cin, line)) {
        for (size_t i = 0; i < line.size();) {
            size_t charLength = CharacterLength(line[i]);
            std::cout << GetCode(line, i, charLength) << ' ';
            i += charLength;
        }
    }
}
