#include <algorithm>
#include <iostream>
#include <vector>

class Minefield {
 public:
    Minefield(size_t height, size_t width) {
        Minefield::field.resize(height + 2);
        Minefield::height = height;
        Minefield::width = width;
        for (size_t row = 0; row < height + 2; ++row) {
            Minefield::field[row].resize(width + 2);
        }
    }

    void AddMine(size_t mineY, size_t mineX) {
        if (mineY > Minefield::height ||  mineX > Minefield::width) {
            std::cout << "Out of bounds while adding a mine!\n";
        } else if (Minefield::field[mineY][mineX] != 10) {
            Minefield::field[mineY][mineX] = 10;
            IncrementNeighbour(mineY, mineX);
        }
    }

    void Print(size_t yFrom, size_t xFrom, size_t yTo, size_t xTo) {
        if (yFrom > Minefield::height || xFrom > Minefield::width) {
            std::cout << "Out of bounds while printing the minefield!";
        } else if (yFrom > yTo || xFrom > xTo) {
            std::cout << "Incorrect parameters for printing the minefield!";
        } else {  // OK
            for (size_t row = 1; row <= Minefield::height; ++row) {
                for (size_t column = 1; column <= Minefield::width; ++column) {
                    if (Minefield::field[row][column] == 10) {  // a mine!
                        std::cout << "* ";
                    } else {
                        std::cout << Minefield::field[row][column] << ' ';
                    }
                }
                std::cout << '\n';
            }
        }
    }

 private:
    std::vector<std::vector<int>> field;
    size_t height, width;
    void IncrementNeighbour(size_t y, size_t x) {
        // 10 == 'cell has a mine, it doesn't give a damn if it has neighbourmines'
        Minefield::field[y - 1][x - 1] = std::min(10, Minefield::field[y - 1][x - 1] + 1);
        Minefield::field[y - 1][x] = std::min(10, Minefield::field[y - 1][x] + 1);
        Minefield::field[y - 1][x + 1] = std::min(10, Minefield::field[y - 1][x + 1] + 1);
        Minefield::field[y][x - 1] = std::min(10, Minefield::field[y][x - 1] + 1);
        Minefield::field[y][x + 1] = std::min(10, Minefield::field[y][x + 1] + 1);
        Minefield::field[y + 1][x - 1] = std::min(10, Minefield::field[y + 1][x - 1] + 1);
        Minefield::field[y + 1][x] = std::min(10, Minefield::field[y + 1][x] + 1);
        Minefield::field[y + 1][x + 1] = std::min(10, Minefield::field[y + 1][x + 1] + 1);
    }
};

template <typename T>
void ReadArguments(T& x, T& y, T& z) {
    std::cin >> x >> y >> z;
}

int main() {
    size_t fieldHeight, fieldWidth, numMines;
    ReadArguments(fieldHeight, fieldWidth, numMines);
    Minefield field(fieldHeight, fieldWidth);
    size_t mineY, mineX;
    for (size_t mine = 0; mine < numMines; ++mine) {
        std::cin >> mineY >> mineX;
        field.AddMine(mineY, mineX);
    }
    field.Print(1, 1, fieldHeight, fieldWidth);
    return 0;
}
