#include <cstdint>
#include <iostream>
#include <vector>

void PrintMatrix(const std::vector<std::vector<int>>& matrix, int width) {
    for (size_t row  = 0; row < matrix.size(); ++row) {
        for (size_t column = 0; column < matrix[row].size(); ++column) {
            std::cout.width(width);
            std::cout << std::right << matrix[row][column];
        }
        std::cout << '\n';
    }
}


std::vector<std::vector<int>> GenerateTriangle(int height) {
    std::vector< std::vector<int> > triangle(height);
    triangle[0].resize(1);
    triangle[0][0] = 1;
    for (size_t row = 1; row < height; ++row) {
        triangle[row].resize(row + 1);
        triangle[row][0] = 1;
        for (size_t column = 1; column < row; ++column) {
            triangle[row][column] = triangle[row - 1][column - 1] + triangle[row - 1][column];
        }
        triangle[row][row] = 1;
    }
    return triangle;
}


int main() {
    const int DIGIT_WIDTH = 6;
    int triangleHeight;
    std::cin >> triangleHeight;
    std::vector<std::vector<int>> triangle = GenerateTriangle(triangleHeight);
    PrintMatrix(triangle, DIGIT_WIDTH);
    return 0;
}

