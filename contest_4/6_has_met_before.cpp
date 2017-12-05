#include <cstdint>
#include <iostream>
#include <unordered_set>

int main() {
    int64_t currentNumber;
    std::unordered_set<int64_t> all;
    while (std::cin >> currentNumber) {
        if (all.find(currentNumber) != all.end()) {
            std::cout << "YES\n";
        } else {
            std::cout << "NO\n";
            all.insert(currentNumber);
        }
    }
}

