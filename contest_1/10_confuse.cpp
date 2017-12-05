#include <cstdint>
#include <iostream>

int main() {
    const int64_t MAX_X = 2000000000;
    int vectorSize, nConfuses;
    std::cin >> vectorSize >> nConfuses;
    int64_t currentX, minX = MAX_X + 1, maxX = -(MAX_X + 1);
    for (size_t i = 0; i < vectorSize; ++i) {
        std::cin >> currentX;
        if (currentX > maxX) {
            maxX = currentX;
        }
        if (currentX < minX) {
            minX = currentX;
        }
    }
    uint64_t diameter = maxX - minX;
    std::cout << diameter << '\n';
    return 0;
}

