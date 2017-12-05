#include <algorithm>
#include <cstdint>
#include <iostream>
#include <vector>

template <typename T>
void ReadVector(T& v, size_t vSize) {
    v.resize(vSize);
    for (size_t i = 0; i < vSize; ++i) {
        std::cin >> v[i];
    }
}

int main() {
    std::vector<int32_t> haystack;
    size_t haystackSize, numNeedles;
    std::cin >> haystackSize >> numNeedles;
    ReadVector(haystack, haystackSize);

    int32_t currentNeedle;
    while (std::cin >> currentNeedle) {
        std::cout
            << (std::binary_search(haystack.begin(), haystack.end(), currentNeedle) ? "YES" : "NO")
            << '\n';
    }
}

