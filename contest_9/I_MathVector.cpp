#include <iostream>
#include <vector>

template <typename T>
class MathVector {
 private:
    std::vector<T> data;

 public:
    // Zero vector of size n
    explicit MathVector(size_t n) {
        data.resize(n);
    }

    template <typename Iter>
    MathVector(Iter first, Iter last) {
        while (first != last) {
            data.push_back(*first);
            ++first;
        }
    }

    size_t Dimension() const {
         return data.size();
    }

    T& operator[] (size_t i) {
        return data[i];
    }

    const T& operator[] (size_t i) const {
        return data[i];
    }
};


// Output format: (1, 2, 3, 4, 5)
template <typename T>
std::ostream& operator<< (std::ostream& out, const MathVector<T>& v) {
    out << '(';
    for (size_t i = 0; i != v.Dimension(); ++i) {
        if (i > 0)
            out << ", ";
        out << v[i];
    }
    out << ')';
    return out;
}

template <typename T>
MathVector<T>& operator*= (MathVector<T>& lhs, const T& scalar) {
    for (size_t i = 0; i != lhs.Dimension(); ++i)
        lhs[i] *= scalar;
    return lhs;
}

template <typename T>
MathVector<T> operator* (const MathVector<T>& lhs, const T& scalar) {
    auto tmp(lhs);
    return tmp *= scalar;
}

template <typename T>
MathVector<T> operator* (const T& scalar, const MathVector<T>& rhs) {
    return rhs * scalar;
}

template <typename T>
MathVector<T>& operator+= (MathVector<T>& lhs, const MathVector<T>& rhs) {
    for (size_t i = 0; i != lhs.Dimension(); ++i) {
        lhs[i] += rhs[i];
    }
    return lhs;
}

template <typename T>
MathVector<T> operator+ (const MathVector<T>& lhs, const MathVector<T>& rhs) {
    auto tmp(lhs);
    return tmp += rhs;
}

/*
int main() {
    std::vector<int> v1 = {2, 3, 4, 5, 6};
    MathVector<int> x(v1.begin() + 2, v1.end());
    MathVector<int> y(v1.begin(), v1.begin() + 3);
    std::cout << x << '\n';
    std::cout << y << '\n';
    std::cout << "x + y = " << x + y << '\n';
    x += y;
    std::cout << "now x * 2 = " << x * 2 << '\n';
}
*/

