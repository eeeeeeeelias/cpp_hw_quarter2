#include <iostream>
#include <string>
#include <vector>

bool NextCombination(std::vector<int>& combination, int maxX) {
    for (int i = combination.size() - 1; i >= 0; --i) {
        if (combination[i] < maxX - (combination.size() - i)) {
            ++combination[i];
            for (int j = i + 1; j < combination.size(); ++j) {
                combination[j] = combination[j - 1] + 1;
            }
            return true;
        }
    }
    return false;
}

size_t NumOnes(size_t x) {
    size_t oneCount = 0;
    while (x > 0) {
        oneCount += x % 2;
        x >>= 1;
    }
    return oneCount;
}

template <typename T>
void PrintCombination(size_t id, const std::vector<T>& set) {
    bool hasPrintedFirst = false;
    for (size_t i = 0; i < set.size(); ++i) {
        if (id & 1) {
            if (hasPrintedFirst) {
                std::cout << ',' << set[set.size() - i - 1];
            } else {
                std::cout << set[set.size() - i - 1];
                hasPrintedFirst = true;
            }
        }
        id >>= 1;
    }
}

template <typename T>
void PrintSubsets(const std::vector<T>& set) {
    for (size_t i = 0; i < (1 << set.size()); ++i) {
        std::cout << '[';
        PrintCombination(i, set);
        std::cout << "]\n";
    }
}

void ReadVector(std::vector<std::string>& myVector) {
    size_t vectorSize;
    std::cin >> vectorSize;
    myVector.resize(vectorSize);
    for (size_t i = 0; i < vectorSize; ++i) {
        std::cin >> myVector[i];
    }
}

int main() {
    freopen("output.txt", "wt", stdout);
    std::vector<std::string> lines;
    ReadVector(lines);
    PrintSubsets(lines);
}

