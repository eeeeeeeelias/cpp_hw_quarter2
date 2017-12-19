#include <algorithm>
#include <iostream>
#include <stdexcept>
#include <vector>

const float EPS = 0.000001;

template <typename T>
void PrintVector(const std::vector<T> v) {
    for (const auto x : v) {
        std::cout << x << ' ';
    }
    std::cout << '\n';
}

template <typename T>
class Polynomial{
 private:
    int degree_ = 0;
    std::vector<T> coeffs_;
 public:
    Polynomial(const Polynomial<T>& polynom)
          : degree_(polynom.degree_),
            coeffs_(polynom.coeffs_) { }
    Polynomial(const std::vector<T>& coeffInput)
          : degree_(coeffInput.size() - 1),
            coeffs_(coeffInput) {
        optimize();
    }
    Polynomial(const T& coeff = T())
          : degree_(0),
            coeffs_({coeff}) {
        optimize();
    }
    void optimize() {
        size_t i = coeffs_.size() - 1;
        while (abs(coeffs_[i]) < EPS) {
            coeffs_.pop_back();
            --i;
            --degree_;
        }
    }
    template <typename It>
    Polynomial(It first, It last)
          : degree_(-1) {
        for (auto it = first; it != last; ++it) {
            ++degree_;
            coeffs_.push_back(*it);
        }
        optimize();
    }
    Polynomial<T> operator+ () const {
        return Polynomial<T>(*this);
    }
    Polynomial<T> operator- () const {
        Polynomial lhsCopy = Polynomial(*this);
        for (size_t i = 0; i < lhsCopy.degree_; ++i) {
            coeffs_[i] *= -1;
        }
        return lhsCopy;
    }
    template <typename TPolynom>
    Polynomial<T>& operator+= (const TPolynom& rhs) {
        Polynomial rhsCopy = Polynomial<T>(rhs);
        if (degree_ < rhsCopy.degree_) {
            degree_ = rhsCopy.degree_;
            coeffs_.resize(rhsCopy.degree_ + 1);
            for (size_t i = 0; i <= degree_; ++i) {
                coeffs_[i] += rhsCopy.coeffs_[i];
            }
            for (size_t i = degree_ + 1; i <= rhsCopy.degree_; ++i) {
                coeffs_[i] = rhsCopy.coeffs_[i];
            }
        }
        else {
            for (size_t i = 0; i != rhsCopy.degree_ + 1; ++i) {
                coeffs_[i] += rhsCopy.coeffs_[i];
            }
        }
        optimize();
        return *this;
    }
    template <typename TPolynom>
    Polynomial<T>& operator-= (const TPolynom& rhs) {
        *this += -Polynomial<T>(rhs);
        return *this;
    }
    template <typename TPolynom>
    Polynomial<T> operator- (const TPolynom& rhs) const {
        return Polynomial(*this) -= Polynomial(rhs);
    }
    int Degree() const {
        return degree_;
    }
    const T& operator[] (int degree) const {
        if (degree < 0) {
            throw std::invalid_argument("degree cannot be negative");
        }
        return (degree > degree_) ? 0 : coeffs_[degree];
    }
    T& operator[] (int degree) {
        return *this[degree];
    }
    /*
    const T& operator() (int degree) const {
        T answer = 0;
        return answer;
    }
    */
    T& operator() (int degree) {
    }
    typename std::vector<T>::const_iterator begin() const {
        return coeffs_.begin();
    }
    typename std::vector<T>::const_iterator end() const {
        return coeffs_.end();
    }
};


template <typename T, typename T1, typename T2>
Polynomial<T> operator+ (const T1& lhs, const T2& rhs);

template <typename T>
Polynomial<T> operator+ (const Polynomial<T>& lhs, const Polynomial<T>& rhs) {
    return Polynomial<T>(lhs) += rhs;
}

template <typename T, typename TScalar>
Polynomial<T> operator+ (const TScalar& lhs, const Polynomial<T>& rhs) {
    return Polynomial<T>(lhs) += rhs;
}

template <typename T, typename TScalar>
Polynomial<T> operator+ (const Polynomial<T>& lhs, const TScalar& rhs) {
    return Polynomial<T>(rhs) += lhs;
}

template <typename TPolynom, typename T>
Polynomial<T> operator- (const TPolynom& lhs, const Polynomial<T>& rhs) {
    return Polynomial<T>(lhs) -= rhs;
}

template <typename TPolynom, typename T>
bool operator== (const Polynomial<T>& lhs, const TPolynom& rhs) {
    return lhs.coeffs_ == Polynomial<T>(rhs).coeffs_;
}

template <typename TPolynom, typename T>
bool operator== (const TPolynom& lhs, const Polynomial<T>& rhs) {
    return rhs == lhs;
}

template <typename TPolynom, typename T>
bool operator!= (const Polynomial<T>& lhs, const TPolynom& rhs) {
    return !(lhs == Polynomial<T>(rhs));
}

template <typename TPolynom, typename T>
bool operator!= (const TPolynom& lhs, const Polynomial<T>& rhs) {
    return !(Polynomial<T>(lhs) == rhs);
}

/*
int main() {
    Polynomial<int> P({1, 2, 3, 0, 0, 0, 0});
    Polynomial<int> p1 = P + 1;
    Polynomial<int> p2 = 1 + P;
    Polynomial<int> p3 = p1 + p1;
    for (auto it = p3.begin(); it != p3.end(); ++it) {
        std::cout << *it << ' ';
    }
    std::cout << '\n';
}
*/
