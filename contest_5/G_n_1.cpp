#include <cstdint>
#include <iostream>
#include <vector>

void PrintLine(std::vector<int> &v, int64_t length) {
    for (int i = 0; i < v[0]; ++i) {
        std::cout << 0;
    }
    for (int i = 0; i < v.size() - 1; ++i) {
        std::cout << 1;
        for (int j = v[i] + 1; j < v[i + 1]; ++j) {
            std::cout << 0;
        }
    }
    std::cout << 1;
    for (int i = v[v.size() - 1] + 1; i < length; ++i) {
        std::cout << 0;
    }
    std::cout << "\n";
}

bool HasNext(std::vector<int> &v, int64_t length) {
    int fromHere = 0;
    for (size_t i = v.size() - 1; i > 0; --i) {
        if (v[i] - v[i - 1] != 1) {
            fromHere = i;
            break;
        }
    }
    --v[fromHere];
    for (size_t i = fromHere + 1; i < v.size(); ++i) {
        v[i] = length - v.size() + i;
    }
    return v[v.size() - 1] != v.size() - 1;
}

int main() {
    int64_t length = 0, oneCount = 0;
    std::cin >> length >> oneCount;
    if (length == oneCount) {
        for (size_t i = 0; i < length; ++i) {
            std::cout << 1;
        }
        std::cout << "\n";
        return 0;
    } else if (oneCount == 0) {
        for (size_t i = 0; i < length; ++i) {
            std::cout << 0;
        }
        std::cout << "\n";
        return 0;
    }
    std::vector<int> combination(oneCount);
    for (int i = 0; i < oneCount; ++i) {
        combination[i] = length - oneCount + i;
    }
    PrintLine(combination, length);
    while (HasNext(combination, length)) {
        PrintLine(combination, length);
    }
    PrintLine(combination, length);
}

