#include <iostream>
#include <vector>

void PrintPermutation(const std::vector<int>& permutation) {
    for (auto x : permutation) {
        std::cout << x;
    }
    std::cout << '\n';
}

bool MakeNextPermutation(std::vector<int>& permutation) {
    int pivot = permutation.size() - 1;
    for (; permutation[pivot - 1] >= permutation[pivot] && pivot >= 1; --pivot) {}
    if (pivot == 0) {
        return false;
    } else {
        int pivotChanger = permutation.size() - 1;
        for (; permutation[pivot - 1] >= permutation[pivotChanger]; --pivotChanger) {}
        std::swap(permutation[pivot - 1], permutation[pivotChanger]);
        for (size_t i = pivot; i <= pivot - 1 + (permutation.size() - pivot) / 2; ++i) {
            std::swap(permutation[i], permutation[permutation.size() + pivot - i - 1]);
        }
        return true;
    }
}

int main() {
    int length;
    std::cin >> length;
    std::vector<int> myPermutation(length);
    for (size_t i = 0; i < length; ++i) {
        myPermutation[i] = i + 1;
    }
    PrintPermutation(myPermutation);
    while (MakeNextPermutation(myPermutation)) {
        PrintPermutation(myPermutation);
    }
}

