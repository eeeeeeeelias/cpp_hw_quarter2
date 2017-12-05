#include <iostream>

int main() {
    int64_t x;
    size_t bitNumber;
    std::cin >> x >> bitNumber;
    std::cout << (x ^ (1 << bitNumber)) << '\n';
}
