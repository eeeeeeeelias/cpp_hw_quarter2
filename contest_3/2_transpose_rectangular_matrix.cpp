#include <iostream>
#include <utility>
#include <vector>

std::vector<std::vector<int>> transpose(const std::vector<std::vector<int>>& matrix) {
    size_t height = matrix.size(), width = matrix[0].size();
    std::vector<std::vector<int>> matrix2(width, std::vector<int>(height, 0));
    for (size_t row = 0; row < height; ++row) {
        for (size_t column = 0; column < width; ++column) {
            matrix2[column][row] = matrix[row][column];
        }
    }
    return matrix2;
}

