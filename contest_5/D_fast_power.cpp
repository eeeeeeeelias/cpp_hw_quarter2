#include <cstdint>
#include <iostream>
#include <vector>

const uint64_t MODULO = 1000000000 + 7;

uint64_t FastPower(uint64_t base, uint64_t exponent) {
    if (exponent == 0) {
        return 1;
    }
    uint64_t answer = 1;
    while (exponent) {
        if (exponent & 1) {
            answer = (answer * base) % MODULO;
        }
        base = (base * base) % MODULO;
        exponent >>= 1;
    }
    return answer;
}

int main() {
    uint64_t base, exponent;
    std::cin >> base >> exponent;

    uint64_t power = FastPower(base, exponent);

    std::cout << power << '\n';
}

