#include <cmath>
#include <iostream>
#include <stdexcept>

class Rational;

std::ostream& operator<<(std::ostream& out, const Rational& x);

template <typename T>
T gcd(T a, T b) {
    a = std::abs(a);
    b = std::abs(b);
    while (b != 0) {
        auto tmp = a % b;
        a = b;
        b = tmp;
    }
    return a;
}

template <typename T>
T lcm(T a, T b) {
    return a * b / gcd(a, b);
}

class Rational {
 private:
    int nmrtr_, dnmntr_;

 public:
    explicit Rational(int n = 0):
        nmrtr_(n), dnmntr_(1) {}
    Rational(int nmrtr, int dnmntr):
        nmrtr_(nmrtr), dnmntr_(std::abs(dnmntr)) {
        if (dnmntr < 0) {
            nmrtr_ *= -1;
        } else if (dnmntr == 0) {
            throw std::invalid_argument("denominator cannot be zero!");
        }
        reduce();
    }
    ~Rational() {}

    void reduce() {
        auto fractionGCD = gcd(nmrtr_, dnmntr_);
        nmrtr_ /= fractionGCD;
        dnmntr_ /= fractionGCD;
        if (dnmntr_ < 0) {
            nmrtr_ *= -1;
            dnmntr_ *= -1;
        }
    }

    int numerator() const {
        return nmrtr_;
    }

    int denominator() const {
        return dnmntr_;
    }

    Rational reciprocal() const {
        if (nmrtr_ == 0) {
            throw std::invalid_argument("reciprocal of 0 is undefined");
        } else {
            return Rational(dnmntr_, nmrtr_);
        }
    }

    template <typename T2>
    Rational& operator+= (const T2& rhs) {
        auto rhsCopy = Rational(rhs);
        auto commonDnmntr = lcm(dnmntr_, rhsCopy.dnmntr_);
        nmrtr_ =
            commonDnmntr / dnmntr_ * nmrtr_
            + commonDnmntr / rhsCopy.dnmntr_ * rhsCopy.nmrtr_;
        dnmntr_ = commonDnmntr;
        reduce();
        return *this;
    }

    template <typename T2>
    Rational& operator-= (const T2& rhs) {
        auto rhsNegativeCopy = Rational(rhs);
        rhsNegativeCopy.nmrtr_ *= -1;
        *this += rhsNegativeCopy;
        reduce();
        return *this;
    }

    template <typename T2>
    Rational& operator*= (const T2& rhs) {
        auto rhsCopy = Rational(rhs);
        nmrtr_ *= rhsCopy.nmrtr_;
        dnmntr_ *= rhsCopy.dnmntr_;
        reduce();
        return *this;
    }

    template <typename T2>
    Rational& operator/= (const T2& rhs) {
        if (rhs == 0) {
            throw std::invalid_argument("division by zero");
        }
        auto rhsCopy = Rational(rhs);
        nmrtr_ *= rhsCopy.dnmntr_;
        dnmntr_ *= rhsCopy.nmrtr_;
        reduce();
        return *this;
    }

    template <typename T2>
    Rational operator+ (const T2& rhs) const {
        return Rational(*this) += Rational(rhs);
    }

    Rational operator+ () const {
        return Rational(*this);
    }

    Rational& operator++ () {
        *this += 1;
        return *this;
    }

    Rational operator++ (int) {
        Rational tmp(*this);
        ++*this;
        return tmp;
    }

    template <typename T2>
    Rational operator- (const T2& rhs) const {
        return Rational(*this) -= Rational(rhs);
    }

    Rational operator- () const {
        return Rational(*this) *= -1;
    }

/*
    Rational operator- () {
        auto tmp = *this;
        tmp *= -1;
        return tmp;
    }
*/

    Rational& operator-- () {
        *this -= 1;
        return *this;
    }

    Rational operator-- (int) {
        Rational tmp(*this);
        --*this;
        return tmp;
    }

    template <typename T2>
    Rational operator* (const T2& rhs) const {
        return Rational(*this) *= Rational(rhs);
    }

    template <typename T2>
    Rational operator/ (const T2& rhs) const {
        return Rational(*this) /= Rational(rhs);
    }

    template <typename T2>
    bool operator== (const T2& rhs) const {
        Rational rhsCopy(rhs);
        return nmrtr_ == rhsCopy.nmrtr_ && dnmntr_ == rhsCopy.dnmntr_;
    }

    template <typename T2>
    bool operator!= (const T2& rhs) const {
        return !(*this == rhs);
    }
};


Rational operator+ (const int& lhs, const Rational& rhs) {
    return +rhs + lhs;
}

Rational operator- (const int& lhs, const Rational& rhs) {
    return -rhs + lhs;
}

Rational operator* (const int& lhs, const Rational& rhs) {
    return rhs * lhs;
}

Rational operator/ (const int& lhs, const Rational& rhs) {
    if (rhs == 0) {
        throw std::invalid_argument("division by zero");
    }
    return rhs.reciprocal() * lhs;
}


std::ostream& operator<<(std::ostream& out, const Rational& x) {
    if (x.denominator() == 1) {
        out << x.numerator();
    } else {
        out << x.numerator() << '/' << x.denominator();
    }
    return out;
}


int main() {
    Rational x(51, -16);
    Rational y(-28, 34);
    Rational z(-34, 14);
    Rational a(30, 15);
    Rational b(2);
    std::cout << "x / 0 = " << 0 / x << '\n';
    std::cout << "2 + x = " << 2 + x << '\n';
    std::cout << "2 - x = " << 2 - x << '\n';
    std::cout << "2 * x = " << 2 * x << '\n';
    std::cout << "2 / x = " << 2 / x << '\n';
/*
    std::cout << "is a == 2? " << (a == 2) << '\n';
    std::cout << "is a != 2? " << (a != 2) << '\n';
    std::cout << "is a == b? " << (a == b) << '\n';
    std::cout << "x = " << x << ", y = " << y << ", z = " << z << '\n';
    std::cout << "x + y = " << x + y << '\n';
    std::cout << "x - y = " << x - y << '\n';
    std::cout << "x * y = " << x * y << '\n';
    std::cout << "x / y = " << x / y << '\n';
    std::cout << "x + 2 = " << x + 2 << '\n';
    std::cout << "x - 2 = " << x - 2 << '\n';
    std::cout << "x * 2 = " << x * 2 << '\n';
    std::cout << "x / 2 = " << x / 2 << '\n';
    std::cout << "+x = " << +x << '\n';
    std::cout << "-x = " << -x << '\n';
    Rational c(5), d;
    std::cout << "c = " << c << ", d = " << d << '\n';
    std::cout << "x = " << x << '\n';
    std::cout << "x++ : " << x++ << '\n';
    std::cout << "x = " << x << '\n';
    std::cout << "++x : " << ++x << '\n';
    std::cout << "x = " << x << '\n';
    std::cout << "--x : " << --x << '\n';
    std::cout << "x = " << x << '\n';
    std::cout << "x-- : " << x-- << '\n';
    std::cout << "x = " << x << '\n';
*/
}

