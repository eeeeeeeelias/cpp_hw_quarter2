#include <iostream>
#include <vector>

template <typename InIter, typename OutIter, typename Predicate>
OutIter remove_copy_if(InIter first, InIter last, OutIter out, Predicate f) {
    for (auto it = first; it != last; ++it) {
        if (!f(*it)) {
            *out = *it;
            ++out;
        }
    }
    return out;
}

bool IsOdd(int x) {
    return x == 2;
}

int main() {
    std::vector<int> v1 = {1, 2, 3, 4, 5};
    std::vector<int> v2;
    auto last = remove_copy_if(v1.begin(), v1.end(), v2.begin(), IsOdd);
    std::cout << v2.size() << '\n';
    for (auto it = v2.begin(); it != last; ++it) {
        std::cout << *it << ' ';
    }
    std::cout << '\n';
}

