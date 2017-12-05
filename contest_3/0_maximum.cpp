#include <iostream>
#include <vector>

std::pair<size_t, size_t> max_element(const std::vector<std::vector<int>>& matrix) {
    int maxElement = matrix[0][0], maxRow = 0, maxColumn = 0;
    for (size_t row = 0; row < matrix.size(); ++row) {
        for (size_t column = 0; column < matrix[row].size(); ++column) {
            if (matrix[row][column] > maxElement) {
                maxElement = matrix[row][column];
                maxRow = row;
                maxColumn = column;
            }
        }
    }
    return std::make_pair(maxRow, maxColumn);
}

