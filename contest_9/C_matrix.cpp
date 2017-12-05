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
    explicit Matrix(const std::vector<std::vector<T>>& rawData):
        height_(rawData.size()) {
        if (height_ > 0) {
            width_ = rawData[0].size();
        }
        matrix_.resize(rawData.size());
        for (size_t y = 0; y < rawData.size(); ++y) {
            matrix_[y].resize(rawData[y].size());
            for (size_t x = 0; x < rawData[y].size(); ++x) {
                matrix_[y][x] = rawData[y][x];
            }
        }
    }

    T GetValue(size_t y, size_t x) const {
        return matrix_[y][x];
    }
    std::pair<size_t, size_t> size() const {
        return std::make_pair(height_, width_);
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

/*
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

int main() {
    freopen("matrix.in", "rt", stdin);
    freopen("matrix.out", "wt", stdout);
    std::vector<std::vector<std::string>> x;
    ReadVector(x);

    Matrix<std::string> m1(x);
    std::cout << m1.size().first << ", " << m1.size().second << '\n';
    std::cout << m1 << '\n';
}
*/

