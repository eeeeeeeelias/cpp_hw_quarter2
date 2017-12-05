#include <cstdint>
#include <iostream>
#include <vector>

template <typename TInt>
void FindAll(TInt key, std::vector<size_t>& positions) {
    size_t index = 0;
    TInt element;
    while (std::cin >> element) {
        if (element == key) {
            positions.push_back(index);
        }
        ++index;
    }
}

template <typename TInt>
int32_t FindOne(TInt key, const std::string& command) {
    int32_t index = 0, position = -1;
    TInt element;
    if (command == "first") {
        while (std::cin >> element) {
            if (element == key) {
                return index;
            }
            ++index;
        }
    } else if (command == "last") {
        while (std::cin >> element) {
            if (element == key) {
                position = index;
            }
            ++index;
        }
    }
    return position;
}

template <typename T>
void PrintVector(const std::vector<T>& v) {
    for (auto element : v) {
        std::cout << element << ' ';
    }
    std::cout << '\n';
}

int main() {
    size_t sequenceLength;
    std::cin >> sequenceLength;
    std::string command;
    std::cin >> command;
    int32_t key;
    std::cin >> key;

    if (command == "all") {
        std::vector<size_t> occurences;
        FindAll(key, occurences);
        PrintVector(occurences);
    } else {
        int32_t index;
        index = FindOne(key, command);
        std::cout << index << '\n';
    }
}

