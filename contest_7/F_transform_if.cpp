#include <iostream>
#include <vector>

template <typename InIter, typename OutIter, typename Predicate, typename Action>
OutIter transform_if(
            InIter first,
            InIter last,
            OutIter out,
            Predicate condition,
            Action f) {
    while (first != last) {
        if (condition(*first)) {
            *out++ = f(*first);
        }
        ++first;
    }
    return out;
}

int Square(int x) {
    int answer = x * x;
    return answer;
}

bool IsOdd(int x) {
    return (x % 2) != 0;
}

int main() {
    std::vector<int> v = {1, 2, 2, 5, 9, -59, 5, 0};
    std::vector<int> w(10);
    auto answer = transform_if(v.begin(), v.end(), w.begin(), IsOdd, Square);
    for (auto it = w.begin(); it != answer; ++it) {
        std::cout << *it << ' ';
    }
    std::cout << '\n';
}
