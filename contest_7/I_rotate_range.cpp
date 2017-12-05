#include <algorithm>
#include <iostream>

template <class It>
It rotate_range(It first, It new_first, It last) {
    if (first != last) {
        std::reverse(first, new_first);
        std::reverse(new_first, last);
        std::reverse(first, last);
    }
    return first + (last - new_first);
}

template <typename T>
void ReadVector(std::vector<T>& v) {
    size_t vSize;
    std::cin >> vSize;
    v.resize(vSize);
    for (size_t i = 0; i != vSize; ++i) {
        std::cin >> v[i];
    }
}

template <typename T>
void PrintVector(const std::vector<T>& v) {
    for (auto it = v.begin(); it != v.end(); ++it) {
        std::cout << *it << ' ';
    }
    std::cout << '\n';
}

int main() {
    std::vector<int> v;
    ReadVector(v);
    size_t shift;
    std::cin >> shift;
    auto new_begin = rotate_range(v.begin(), v.begin() + shift, v.end());
    PrintVector(v);
    std::cout << *v.end();
    std::cout << *new_begin;
}
