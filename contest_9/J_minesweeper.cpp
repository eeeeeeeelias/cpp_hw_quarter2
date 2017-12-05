#include <iostream>
#include <vector>

using std::vector;

class Minesweeper {
 private:
    size_t M, N;
    vector<vector<int>> Table;

 public:
    Minesweeper(size_t m, size_t n): M(m), N(n) {
        Table.resize(M);
        for (size_t i = 0; i != M; ++i) {
            Table[i].resize(N);
        }
    }

    size_t Rows() const {
        return M;
    }

    size_t Columns() const {
        return N;
    }

    void SetMine(size_t i, size_t j) {
        Table[i][j] = -1;
    }

    int operator () (size_t i, size_t j) const {
        return Table[i][j];
    }

    void CheckForMinesAround() {
        for (int i = 0; i != M; ++i) {
            for (int j = 0; j != N; ++j) {
                CheckForMinesAround(i, j);
            }
        }
    }

 private:
    void CheckForMinesAround(int i, int j) {
        if (Table[i][j] != -1) {
            int counter = 0;
            for (int dx = -1; dx <= 1; ++dx) {
                for (int dy = -1; dy <= 1; ++dy) {
                    if (0 <= (i + dx) && (i + dx) < M &&
                        0 <= (j + dy) && (j + dy) < N &&
                        Table[i + dx][j + dy] == -1 &&
                        !(dx == 0 && dy == 0)
                    ) {
                        ++counter;
                    }
                }
            }
            Table[i][j] = counter;
        }
    }
};

std::ostream& operator << (std::ostream& out, const Minesweeper& ms) {
    for (size_t i = 0; i != ms.Rows(); ++i) {
        for (size_t j = 0; j != ms.Columns(); ++j) {
            if (ms(i, j) == -1)
                out << '*';
            else
                out << ms(i, j);
        }
        out << "\n";
    }
    return out;
}

/*
int main() {
    freopen("input.txt", "rt", stdin);
    size_t m, n;
    std::cin >> m >> n;
    Minesweeper ms(m, n);

    size_t minesCount;
    std::cin >> minesCount;
    for (size_t i = 0; i < minesCount; ++i) {
        size_t x, y;
        std::cin >> x >> y;
        ms.SetMine(x, y);
    }

    ms.CheckForMinesAround();

    std::cout << ms;
}
*/
