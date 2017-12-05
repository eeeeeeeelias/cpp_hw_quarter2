#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

const size_t MAX_NUM_LINES = 1000;

template <typename T>
void ReadVector(std::vector<T>& myVector) {
    myVector.reserve(MAX_NUM_LINES);
    T element;
    while (std::getline(std::cin, element)) {
        myVector.push_back(element);
    }
}

template <typename T>
void PrintVector(const std::vector<T>& myVector) {
    for (auto element : myVector) {
        std::cout << element << '\n';
    }
}

int main() {
    std::string sortingType;
    std::getline(std::cin, sortingType);

    std::vector<std::string> lines;
    ReadVector(lines);

    if (sortingType == "ASCENDING") {
        std::sort(lines.begin(), lines.end());
    } else {
        std::sort(lines.rbegin(), lines.rend());
    }

    PrintVector(lines);
}

