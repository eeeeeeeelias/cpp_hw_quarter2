#include <algorithm>
#include <iostream>
#include <iterator>
#include <stdexcept>
#include <string>
#include <utility>
#include <vector>


const std::string MATRICES_MULTIPLYING_ERROR =
    "The width of the 1st matrix must be equal to the height of the 2nd matrix!";

template <typename T>
class Matrix{
 private:
    size_t height_, width_;
    std::vector<T> matrix_;

 public:
    Matrix(const Matrix<T>& src):
        height_(src.height_), width_(src.width_) {
        matrix_.resize(src.height_ * src.width_);
        for (size_t i = 0; i < matrix_.size(); ++i) {
            matrix_[i] = src.matrix_[i];
        }
    }
    explicit Matrix(const std::vector<std::vector<T>>& rawData):
        height_(rawData.size()), width_(rawData[0].size()) {
        matrix_.resize(height_ * width_);
        for (size_t i = 0; i < matrix_.size(); ++i) {
            matrix_[i] = rawData[i / width_][i % width_];
        }
    }
    ~Matrix() {}

    T GetValue(size_t y, size_t x) const {
        return matrix_[y * width_ + x];
    }
    std::pair<size_t, size_t> size() const {
        return std::make_pair(height_, width_);
    }

    typename std::vector<T>::iterator begin() {
        return matrix_.begin();
    }

    typename std::vector<T>::const_iterator begin() const {
        auto tmp = matrix_.begin();
        return tmp;
    }

    typename std::vector<T>::iterator end() {
        return matrix_.end();
    }

    typename std::vector<T>::const_iterator end() const {
        auto tmp = matrix_.end();
        return tmp;
    }
/*
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
        if (width_ != rhs.height_) {
            throw std::invalid_argument(MATRICES_MULTIPLYING_ERROR);
        }
        std::vector<std::vector<T>> result(height_, std::vector<T>(rhs.width_, 0));
        auto rhsT = rhs.transposed();
        for (size_t y = 0; y < height_; ++y) {
            for (size_t x = 0; x < rhs.width_; ++x) {
                for (size_t i = 0; i < width_; ++i) {
                    result[y][x] += matrix_[y][i] * rhsT.matrix_[x][i];
                }
            }
        }
        *this = Matrix(result);
        return *this;
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
*/
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
    std::cout << m1 << '\n';
    for (auto it = m1.begin(); it != m1.end(); ++it) {
        std::cout << *it << '\n';
    }
    auto poi = m1.begin();
    *poi = 2;
    std::cout << m1 << '\n';
}
*/

