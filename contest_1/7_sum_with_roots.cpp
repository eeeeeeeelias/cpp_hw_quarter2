#include <cmath>
#include <cstdint>
#include <iostream>

int main() {
    uint64_t n, a;
    std::cin >> n >> a;
    uint64_t addendum = n * a;
    double sumWithRoots = 0;
    for (size_t i = 0; i <= n; ++i) {
        sumWithRoots = addendum + std::sqrt(sumWithRoots);
        addendum -= a;
    }
    std::cout << sumWithRoots << "\n";
    return 0;
}

