#include <algorithm>
#include <iostream>
#include <string>
#include <utility>
#include <vector>

template <typename T>
class Matrix{
 private:
    size_t height_, width_;
    std::vector<std::vector<T>> matrix_;

 public:
    Matrix(const Matrix<T>& src):
        height_(src.height_), width_(src.width_) {
        matrix_.resize(src.height_);
        for (size_t y = 0; y < src.height_; ++y) {
            matrix_[y].resize(src.width_);
            for (size_t x = 0; x < src.width_; ++x) {
                matrix_[y][x] = src.matrix_[y][x];
            }
        }
    }
    explicit Matrix(const std::vector<std::vector<T>>& rawData):
        height_(rawData.size()), width_(rawData[0].size()) {
        matrix_.resize(rawData.size());
        for (size_t y = 0; y < rawData.size(); ++y) {
            matrix_[y].resize(rawData[y].size());
            for (size_t x = 0; x < rawData[y].size(); ++x) {
                matrix_[y][x] = rawData[y][x];
            }
        }
    }
    ~Matrix() {}

    T GetValue(size_t y, size_t x) const {
        return matrix_[y][x];
    }
    std::pair<size_t, size_t> size() const {
        return std::make_pair(height_, width_);
    }

    Matrix<T>& operator+=(const Matrix<T>& rhs) {
        for (size_t y = 0; y < height_; ++y) {
            for (size_t x = 0; x < width_; ++x) {
                matrix_[y][x] += rhs.matrix_[y][x];
            }
        }
        return *this;
    }

    Matrix<T> operator+(const Matrix<T>& rhs) const {
        return Matrix(*this) += rhs;
    }

    template <typename Number>
    Matrix<T>& operator*=(const Number& scalar) {
        for (size_t y = 0; y < height_; ++y) {
            for (size_t x = 0; x < width_; ++x) {
                matrix_[y][x] *= scalar;
            }
        }
        return *this;
    }

    template <typename Number>
    Matrix<T> operator*(const Number& scalar) const {
        return Matrix(*this) *= scalar;
    }

    Matrix<T>& operator*=(const Matrix<T>& rhs) {
    }

    Matrix<T> operator*(const Matrix<T>& rhs) const {
        return Matrix<T>(*this) *= rhs;
    }

    Matrix<T>& transpose() {
        if (height_ >= width_) {
            for (size_t y = 0; y < width_; ++y) {
                matrix_[y].resize(height_);
                for (size_t x = y + 1; x < height_; ++x) {
                    std::swap(matrix_[y][x], matrix_[x][y]);
                }
            }
            matrix_.resize(width_);
        } else {
            matrix_.resize(width_);
            for (size_t y = 0; y < height_; ++y) {
                for (size_t x = 0; x < y; ++x) {
                    std::swap(matrix_[y][x], matrix_[x][y]);
                }
            }
            for (size_t y = height_; y < width_; ++y) {
                matrix_[y].resize(height_);
                for (size_t x = 0; x < height_; ++x) {
                    matrix_[y][x] = matrix_[x][y];
                }
            }
            for (size_t y = 0; y < height_; ++y) {
                matrix_[y].resize(height_);
            }
        }
        std::swap(height_, width_);
        return *this;
    }

    Matrix<T> transposed() const {
        return Matrix(*this).transpose();
    }
};

template <typename T>
std::ostream& operator<<(std::ostream& out, const Matrix<T>& m) {
    std::pair<size_t, size_t> mSize = m.size();
    for (size_t y = 0; y < mSize.first - 1; ++y) {
        if (mSize.second != 0) {  // not Ax0 matrix
            out << m.GetValue(y, 0);
            for (size_t x = 1; x < mSize.second; ++x) {
                out << '\t' << m.GetValue(y, x);
            }
        }
        out << '\n';
    }
    if (mSize.first != 0) {  // last line
        if (mSize.second != 0) {
            out << m.GetValue(mSize.first - 1, 0);
        }
        for (size_t x = 1; x < mSize.second; ++x) {
            out << '\t' << m.GetValue(mSize.first - 1, x);
        }
    }
    return out;
}

template <typename T>
void ReadVector(std::vector<std::vector<T>>& v) {
    size_t height, width;
    std::cin >> height >> width;
    v.resize(height);
    for (size_t row = 0; row < height; ++row) {
        v[row].resize(width);
        for (size_t column = 0; column < width; ++column) {
            std::cin >> v[row][column];
        }
    }
}

/*
int main() {
    freopen("matrix.in", "rt", stdin);
    freopen("matrix.out", "wt", stdout);
    std::vector<std::vector<int>> x;
    ReadVector(x);
    Matrix<int> m1(x);
    std::cout << m1 << '\n' << '\n';
    m1.transpose();
    std::cout << m1 << "\n\n";
    m1.transpose();
    std::cout << m1 << "\n\n";
    std::cout << m1.transposed() << '\n' << '\n';
    std::cout << m1 << '\n' << '\n';
    m1.transpose();
    std::cout << m1 << '\n';
}
*/
