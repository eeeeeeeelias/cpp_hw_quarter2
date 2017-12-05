#include <cstdint>
#include <iostream>
#include <unordered_set>

int main() {
    int64_t currentNumber;
    std::unordered_set<int64_t> allNumbers;
    while (std::cin >> currentNumber) {
        allNumbers.insert(currentNumber);
    }

    std::cout << allNumbers.size() << '\n';
}

