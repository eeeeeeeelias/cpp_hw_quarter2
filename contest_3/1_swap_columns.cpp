#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>

void swap_columns(std::vector<std::vector<int>>& matrix, size_t i, size_t j) {
    if (i != j) {
        for (size_t row = 0; row < matrix.size(); ++row) {
            std::swap(matrix[row][i], matrix[row][j]);
        }
    }
}

