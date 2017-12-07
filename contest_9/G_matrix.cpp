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
        return matrix_.begin();
    }

    typename std::vector<T>::iterator end() {
        return matrix_.end();
    }

    typename std::vector<T>::const_iterator end() const {
        return matrix_.end();
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
    std::cout << m1 << '\n';
    for (auto it = m1.begin(); it != m1.end(); ++it) {
        std::cout << *it << '\n';
    }
    auto poi = m1.begin();
    *poi = 2;
    std::cout << m1 << '\n';
}
*/

