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
void PrintSubsets(const std::vector<T>& set) {
    for (size_t cardinality = 0; cardinality <= set.size(); ++cardinality) {
        std::vector<int> combination(cardinality);
        for (size_t i = 0; i < cardinality; ++i) {
            combination[i] = i;
        }

        do {
            std::cout << '[';
            if (combination.size() > 0) {
                std::cout << set[combination[0]];
            }
            for (size_t i = 1; i < combination.size(); ++i) {
                std::cout << ',' << set[combination[i]];
            }
            std::cout << "]\n";
        } while (NextCombination(combination, set.size()));
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

