#include <iostream>
#include <vector>

template <typename InIter1, typename InIter2, typename OutIter>
OutIter set_difference(
            InIter1 first1,
            InIter2 last1,
            InIter2 first2,
            InIter2 last2,
            OutIter out) {
    while (first1 != last1) {
        if (first2 == last2) {
            *out++ = *first1++;
        } else {
            if (*first1 < *first2) {
                *out++ = *first1++;
            } else if (*first1 == *first2) {
                ++first1;
                ++first2;
            } else {
                ++first2;
            }
        }
    }
    return out;
}

template <typename T>
void ReadVector(std::vector<T>& v) {
    size_t vSize;
    std::cin >> vSize;
    v.resize(vSize);
    for (size_t i = 0; i < vSize; ++i) {
        std::cin >> v[i];
    }
}

int main() {
    std::vector<int> v1, v2, v3;
    ReadVector(v1);
    ReadVector(v2);
    v3.resize(std::max(v1.size(), v2.size()));
    auto answerIt = set_difference(v1.begin(), v1.end(), v2.begin(), v2.end(), v3.begin());
    for (auto it = v3.begin(); it != answerIt; ++it) {
        std::cout << *it << ' ';
    }
    std::cout << '\n';
}
