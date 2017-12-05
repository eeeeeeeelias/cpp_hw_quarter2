#include <iostream>

int main() {
    int64_t x;
    size_t bitPosition;
    std::cin >> x >> bitPosition;
    std::cout << (x & (1 << bitPosition) - 1) << '\n';
}

