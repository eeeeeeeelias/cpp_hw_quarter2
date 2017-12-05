#include <iostream>
#include <string>

size_t NumBytes(uint32_t code) {
    code >>= 7;
    if (code == 0) {  // 0xxxxxxx
        return 1;
    } else {
        code >>= 4;
        if (code == 0) {  // 110xxxxx 10xxxxxx
            return 2;
        } else {
            code >>= 5;
            if (code == 0) {  // 1110xxxx 10xxxxxx 10xxxxxx
                return 3;
            } else {
                return 4;
            }
        }
    }
}

std::string CodeToSymbol(uint32_t code, size_t bytes) {
    if (bytes == 1) {
        return std::string(1, code);
    } else {
        std::string answerLine(bytes, 0);
        uint32_t answer = ((1 << 8) - 1) & ~((1 << (8 - bytes)) - 1);
        answer <<= 8 * (bytes - 1);
        for (size_t i = 1; i < bytes; ++i) {
            answer |= 1 << (8 * i - 1);
        }
        size_t currentBit = 0;
        while (code > 0) {
            if (currentBit % 8 == 6) {
                currentBit += 2;
            } else {
                answer |= (code & 1) << (currentBit);
                code >>= 1;
                ++currentBit;
            }
        }
        for (int i = bytes - 1; i >= 0; --i) {
            answerLine[i] = answer & ((1 << 8) - 1);
            answer >>= 8;
        }
        return answerLine;
    }
    return "";
}

int main() {
    freopen("input.txt", "rt", stdin);
    std::string outputLine = "";
/*    size_t bytes;
    uint32_t code;
    std::cin >> code >> bytes;
    std::cout << CodeToSymbol(code, bytes);*/
    uint32_t chCode;
    while (std::cin >> chCode) {
        size_t numBytes = NumBytes(chCode);
        outputLine += CodeToSymbol(chCode, numBytes);
    }
    std::cout << outputLine << '\n';
}

