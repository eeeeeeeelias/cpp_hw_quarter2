#include <vector>

bool is_symmetric(const std::vector<std::vector<int>>& matrix) {
    int matrixSize = matrix.size();
    for (int iRow = 0; iRow < matrixSize - 1; ++iRow) {
        for (int iColumn = iRow + 1; iColumn < matrixSize; ++iColumn) {
            if (matrix[iRow][iColumn] != matrix[iColumn][iRow]) {
                return false;
            }
        }
    }
    return true;
}

