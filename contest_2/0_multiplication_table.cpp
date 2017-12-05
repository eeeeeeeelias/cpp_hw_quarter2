#include <cstdint>
#include <iostream>

int main() {
    int64_t maxNumber, modulo;
    std::cin >> maxNumber >> modulo;

    for (size_t iColumn = 1; iColumn <= maxNumber; ++iColumn) {
        std::cout << "\t" << iColumn;
    }
    std::cout << "\n";

    for (size_t iRow = 1; iRow <= maxNumber; ++iRow) {
        std::cout << iRow;
        for (size_t iColumn = 1; iColumn <= maxNumber; ++iColumn) {
            std::cout << "\t" << (iRow * iColumn) % modulo;
        }
        std::cout << "\n";
    }

    return 0;
}

