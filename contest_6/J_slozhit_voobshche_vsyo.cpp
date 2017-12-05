#include <algorithm>
#include <cstdint>
#include <iostream>
#include <vector>

template <typename T>
void ReadVector(std::vector<T>& v) {
    T element;
    while (std::cin >> element) {
        v.push_back(element);
    }
}

int main() {
    std::vector<double> numbers;
    ReadVector(numbers);
    double numbersSum = std::accumulate(numbers.begin(), numbers.end(), 0.0);
    std::cout << numbersSum << '\n';
}

