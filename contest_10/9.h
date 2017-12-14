#include <iostream>

class C {
private:
    static int counter;
    const int id;

public:
    C(): id(++counter) {
        if (id <= 3) {
            std::cout << "constructor C() " << id << "\n";
        }
    }

    C(const C& other): id(++counter) {
        std::cout << "constructor C(const C&) " << id << " " << other.id << "\n";
    }

    C(const C&& other): id(++counter) {
        std::cout << "constructor C(const C&&) " << id << " " << other.id << "\n";
    }

    C& operator = (const C& other) {
        std::cout << "operator = (const C&) " << id << " " << other.id << "\n";
        return *this;
    }

    C& operator = (const C&& other) {
        std::cout << "operator = (const C&&) " << id << " " << other.id << "\n";
        return *this;
    }

    ~C() {
        if (id <= 3) {
            std::cout << "destructor C() " << id << "\n";
        }
    }
};

int C::counter = 0;