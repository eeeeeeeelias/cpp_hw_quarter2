#include <iostream>
#include <vector>

std::vector<std::vector<int>> ScanHall() {
    size_t numRows, numColumns;
    std::cin >> numRows >> numColumns;
    std::vector<std::vector<int>> hall(numRows, std::vector<int>(numColumns));
    for (size_t row = 0; row < numRows; ++row) {
        for (size_t column = 0; column < numColumns; ++column) {
            std::cin >> hall[row][column];
        }
    }
    return hall;
}

size_t RequestTickets() {
    size_t numTickets;
    std::cin >> numTickets;
    return numTickets;
}

size_t FindSuitableRow(const std::vector<std::vector<int>>& matrix, int numNeededPlaces) {
    for (size_t row = 0; row < matrix.size(); ++row) {
        size_t maxEmptyInRow = 0, currentEmptyInRowCount = 0;
        for (size_t column = 0; column < matrix[row].size(); ++column) {
            if (matrix[row][column] == 0) {
                ++currentEmptyInRowCount;
            } else {
                maxEmptyInRow = std::max(maxEmptyInRow, currentEmptyInRowCount);
                currentEmptyInRowCount = 0;
            }
        }
        maxEmptyInRow = std::max(maxEmptyInRow, currentEmptyInRowCount);
        if (maxEmptyInRow >= numNeededPlaces) {
            return row + 1;
        }
    }
    return 0;
}

template<typename T>
void PrintAnswer(T answer) {
    std::cout << answer << '\n';
}

int main() {
    std::vector<std::vector<int>> hall = ScanHall();
    size_t numTickets = RequestTickets();
    size_t emptyEnoughRow = FindSuitableRow(hall, numTickets);
    PrintAnswer(emptyEnoughRow);
    return 0;
}

