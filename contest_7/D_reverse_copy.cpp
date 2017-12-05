#include <iostream>
#include <vector>

template <typename InIter, typename OutIter>
OutIter reverse_copy(InIter first, InIter last, OutIter out) {
    if (first != last) {
        for (auto it = std::prev(last); it != first; it = std::prev(it)) {
            *out = *it;
            ++out;
        }
        *out++ = *first;
    }
    return out;
}

template <typename T>
void ReadVector(T& v) {
    size_t vSize;
    std::cin >> vSize;
    v.resize(vSize);
    for (size_t i = 0; i < vSize; ++i) {
        std::cin >> v[i];
    }
}

int main() {
    std::vector<int> v;
    ReadVector(v);
    std::vector<int> w(v.size());
    auto wEnd = reverse_copy(v.begin(), v.end(), w.begin());
    for (auto it = w.begin(); it != wEnd; ++it) {
        std::cout << *it << ' ';
    }
    std::cout << '\n';
}

