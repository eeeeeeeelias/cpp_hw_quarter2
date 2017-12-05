#include <cstdint>
#include <iostream>
#include <vector>

void PrintTribonacci(size_t numNumbers) {
    if (numNumbers == 0) {
    } else if (numNumbers < 4) {
        for (size_t i = 0; i != numNumbers - 1; ++i) {
            std::cout << 1 << ' ';
        }
        std::cout << 1;
    } else {
        std::vector<uint64_t> lastNumbers = {1, 1, 1};
        uint64_t tmp;
        for (size_t i = 0; i < numNumbers - 1; ++i) {
            std::cout << lastNumbers[0] << ' ';
            tmp = lastNumbers[0] + lastNumbers[1] + lastNumbers[2];
            lastNumbers[0] = lastNumbers[1];
            lastNumbers[1] = lastNumbers[2];
            lastNumbers[2] = tmp;
        }
        std::cout << lastNumbers[0];
    }
    std::cout << '\n';
}

int main() {
    size_t numNumbers;
    std::cin >> numNumbers;

    PrintTribonacci(numNumbers);
}

