#include <iostream>

template <typename TInt>
size_t CountOnes(TInt x) {
    size_t answer = 0;
    while (x > 0) {
        answer += x % 2;
        x >>= 1;
    }
    return answer;
}

int main() {
    uint64_t x;
    std::cin >> x;
    std::cout << CountOnes(x) << '\n';
}

