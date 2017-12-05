#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>

void transpose(std::vector<std::vector<int>>& matrix) {
    for (size_t row = 0; row < matrix.size() - 1; ++row) {
        for (size_t column = row + 1; column < matrix.size(); ++column) {
            std::swap(matrix[row][column], matrix[column][row]);
        }
    }
}

