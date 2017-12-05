#include <iostream>

int main() {
    for (size_t iColumn = 0; iColumn <= 9; ++iColumn) {
        std::cout << '\t' << iColumn;
    }
    for (char iColumn = 'A'; iColumn <= 'F'; ++iColumn) {
        std::cout << '\t' << iColumn;
    }
    std::cout << '\n';

    for (size_t iRow = 2; iRow <= 7; ++iRow) {
        std::cout << iRow;
        for (size_t iColumn = 0; iColumn < 16; ++iColumn) {
            std::cout << '\t' << static_cast<char> (iRow * 16 + iColumn);
        }
        std::cout << '\n';
    }
}

