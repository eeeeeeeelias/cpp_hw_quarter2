#include <cmath>
#include <iostream>

class Complex{
 public:
    explicit Complex(const double re) {
        re_ = re;
        im_ = 0;
    }
    Complex(const double re, const double im) {
        re_ = re;
        im_ = im;
    }

    Complex& operator+=(const Complex& rhs) {
        re_ += rhs.re_;
        im_ += rhs.im_;
        return *this;
    }
    Complex& operator-=(const Complex& rhs) {
        re_ -= rhs.re_;
        im_ -= rhs.im_;
        return *this;
    }
    Complex& operator*=(const Complex& rhs) {
        double re_tmp = re_ * rhs.re_ - im_ * rhs.im_;
        double im_tmp = re_ * rhs.im_ + im_ * rhs.re_;
        re_ = re_tmp;
        im_ = im_tmp;
        return *this;
    }
    Complex& operator/=(const Complex& rhs) {
        double re_tmp = (re_ * rhs.re_ + im_ * rhs.im_)
            / (rhs.re_ * rhs.re_ + rhs.im_ * rhs.im_);
        double im_tmp = (im_ * rhs.re_ - re_ * rhs.im_)
            / (rhs.re_ * rhs.re_ + rhs.im_ * rhs.im_);
        re_ = re_tmp;
        im_ = im_tmp;
        return *this;
    }
    bool operator== (const Complex& rhs) {
        return re_ == rhs.re_ && im_ == rhs.im_;
    }
    bool operator!= (const Complex& rhs) {
        return !(*this == rhs);
    }
    double Re() const {
        return re_;
    }
    double Im() const {
        return im_;
    }

 private:
    double re_, im_;
};

double abs(const Complex& z) {
    return sqrt(z.Re() * z.Re() + z.Im() * z.Im());
}

template <typename Number>
Complex operator+(const Complex& lhs, const Number& rhs) {
    return Complex(lhs) += Complex(rhs);
}
template <typename Number>
Complex operator-(const Complex& lhs, const Number& rhs) {
    return Complex(lhs) -= Complex(rhs);
}
template <typename Number>
Complex operator*(const Complex& lhs, const Number& rhs) {
    return Complex(lhs) *= Complex(rhs);
}
template <typename Number>
Complex operator/(const Complex& lhs, const Number& rhs) {
    return Complex(lhs) /= Complex(rhs);
}

Complex operator+(const double& lhs, const Complex& rhs) {
    return Complex(lhs) += Complex(rhs);
}
Complex operator-(const double& lhs, const Complex& rhs) {
    return Complex(lhs) -= Complex(rhs);
}
Complex operator*(const double& lhs, const Complex& rhs) {
    return Complex(lhs) *= Complex(rhs);
}
Complex operator/(const double& lhs, const Complex& rhs) {
    return Complex(lhs) /= Complex(rhs);
}
Complex operator+(const Complex& rhs) {
    return Complex(rhs);
}
Complex operator-(const Complex& rhs) {
    return Complex(rhs) * (-1);
}
std::ostream& operator<<(std::ostream& out, const Complex& rhs) {
    if (rhs.Re() != 0) {  // a +- ...
        out << rhs.Re();
    }
    if (rhs.Im() != 0) {  // a +- (b)i
        if (rhs.Im() > 0 && rhs.Re() != 0) {
            out << '+';
        } else {
            out << '-';
        }
        if (std::abs(rhs.Im()) != 1) {  // b != +- 1
            std::cout << std::abs(rhs.Im());
        }
        out << 'i';
    }
    return out;
}

/*
int main() {
    Complex a(2, 7), b(3, -5), c(2.0, 7.0);
    std::cout << a << " + " << b << " = " << a + b << '\n';
    std::cout << a << " * " << b << " = " << a * b << '\n';
    std::cout << a << " / " << b << " = " << a / b << '\n';
    std::cout << "|" << a << "| = " << abs(a);
}
*/

