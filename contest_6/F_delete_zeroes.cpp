#include <algorithm>
#include <iostream>
#include <vector>

void delete_zeroes(std::vector<int>& numbers) {
    numbers.erase(std::remove(numbers.begin(), numbers.end(), 0), numbers.end());
}

