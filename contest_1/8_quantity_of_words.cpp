#include <cstdint>
#include <iostream>
#include <string>

int main() {
    std::string newWord;
    size_t wordCount = 0;
    while (std::cin >> newWord) {
        ++wordCount;
    }
    std::cout << wordCount << "\n";
    return 0;
}

