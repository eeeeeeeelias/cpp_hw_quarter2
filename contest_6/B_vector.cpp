#include <algorithm>
#include <cstdint>
#include <iostream>
#include <vector>

template <typename TInt>
size_t CountOccurence(TInt key, const std::vector<TInt>& haystack) {
    return std::upper_bound(haystack.begin(), haystack.end(), key)
        - std::lower_bound(haystack.begin(), haystack.end(), key);
}

template <typename TInt>
void ReadVector(std::vector<TInt>& myVector) {
    size_t vectorSize;
    std::cin >> vectorSize;
    myVector.resize(vectorSize);
    for (size_t i = 0; i < vectorSize; ++i) {
        std::cin >> myVector[i];
    }
}

template <typename TInt>
void PrintVector(const std::vector<TInt>& myVector) {
    for (const auto& element : myVector) {
        std::cout << element << ' ';
    }
    std::cout << '\n';
}

int main() {
    std::vector<int32_t> haystack;
    ReadVector(haystack);
    std::sort(haystack.begin(), haystack.end());

    size_t numKeys;
    std::cin >> numKeys;

    int32_t key;
    for (size_t i = 0; i < numKeys; ++i) {
        std::cin >> key;
        std::cout << CountOccurence(key, haystack) << ' ';
    }
    std::cout << '\n';
}

