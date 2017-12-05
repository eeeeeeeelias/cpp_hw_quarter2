#include <iostream>

size_t BitLength(int x) {
    size_t length = 0;
    if (x != 0) {
        while (x >= (1 << length)) {
            ++length;
        }
        return length;
    } else {
        return 1;
    }
}

void Shift(int xLength, int& x) {
    int leftBit = x / (1 << (xLength - 1));
    x <<= 1;
    x += leftBit;
    x &= (1 << xLength) - 1;
}

int main() {
    int number;
    std::cin >> number;

    int modified = number, maxModified = number;
    size_t xLength = BitLength(number);
    do {
        Shift(xLength, modified);
        maxModified = std::max(maxModified, modified);
    } while (modified != number);

    std::cout << maxModified << '\n';
}
