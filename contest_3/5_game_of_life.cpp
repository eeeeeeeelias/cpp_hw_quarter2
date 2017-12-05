#include <algorithm>
#include <cstdint>
#include <iostream>
#include <utility>
#include <vector>

class Field {
 private:
    std::vector<std::vector<int>> field;
    size_t width, height;

 public:
    Field(size_t height, size_t width) {
        Field::width = width;
        Field::height = height;
        Field::field.resize(Field::height + 2);
        for (size_t row = 0; row < Field::height + 2; ++row) {
            Field::field[row].resize(Field::width + 2);
        }
    }

    size_t CountNeighbours(size_t y, size_t x) {
        return
                Field::field[y - 1][x - 1] % 8 + Field::field[y - 1][x] % 8 +
                Field::field[y - 1][x + 1] % 8 +
                Field::field[y][x - 1] % 8 + Field::field[y][x + 1] % 8 +
                Field::field[y + 1][x - 1] % 8 + Field::field[y + 1][x] % 8 +
                Field::field[y + 1][x + 1] % 8;
    }

    void MakeMove() {
        for (size_t row = 1; row <= Field::height; ++row) {
            for (size_t column = 1; column <= Field::width; ++column) {
                size_t numNeighbours = CountNeighbours(row, column);
                if (numNeighbours == 3) {
                    Field::field[row][column] += 8;  // there'll be a life!
                } else if (numNeighbours == 2 && Field::field[row][column] == 1) {
                    Field::field[row][column] += 8;  // there'll be a life!
                }
            }
        }
        for (size_t row = 1; row <= Field::height; ++row) {
            for (size_t column = 1; column <= Field::width; ++column) {
                field[row][column] /= 8;
            }
        }
    }

    void SpendTime(size_t time) {
        for (size_t i = 0; i < time; ++i) {
            Field::MakeMove();
        }
    }

    void Read(size_t yFrom, size_t xFrom, size_t yTo, size_t xTo) {
        if (yFrom < 1 || xFrom < 1 || yTo > Field::height || xTo > Field::width) {
            std::cout << "Out of bounds!\n";
        } else {
            for (size_t row = yFrom; row <= yTo; ++row) {
                for (size_t column = xFrom; column <= xTo; ++column) {
                    std::cin >> Field::field[row][column];
                }
            }
        }
    }

    void Print(size_t yFrom, size_t xFrom, size_t yTo, size_t xTo) {
        if (yFrom < 1 || xFrom < 1 || yTo > Field::height || xTo > Field::width) {
            std::cout << "Out of bounds\n";
        } else {
            for (size_t row = yFrom; row <= yTo; ++row) {
                for (size_t column = xFrom; column <= xTo; ++column) {
                    std::cout << Field::field[row][column] << ' ';
                }
                std::cout << '\n';
            }
        }
    }
};

template <typename T>
void ReadArguments(T& x, T&y) {
    std::cin >> x >> y;
}

int main() {
    size_t fieldSize, time;
    ReadArguments(fieldSize, time);
    Field field(fieldSize, fieldSize);
    field.Read(1, 1, fieldSize, fieldSize);
    field.SpendTime(time);
    field.Print(1, 1, fieldSize, fieldSize);
    return 0;
}

