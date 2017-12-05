#include <vector>

void reverse(std::vector<int>& numbers) {
    int size = numbers.size();
    for (int i = 0; i < size / 2; ++i) {
        numbers[i] = numbers[i] ^ numbers[numbers.size() - i - 1];
        numbers[size - i - 1] = numbers[i] ^ numbers[size - i - 1];
        numbers[i] = numbers[i] ^ numbers[size - i - 1];
    }
}
