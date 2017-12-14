#include <iostream>

class C {
private:
    static int counter;
    const int id;

public:
    C(): id(++counter) {
    }

    C(const C& other): id(++counter) {
        std::cout << "constructor C()" << "\n";
    }

    C(const C&& other): id(++counter) {
    }

    C& operator = (const C& other) {
        return *this;
    }

    C& operator = (const C&& other) {
        return *this;
    }

    ~C() {
        if (id == 2) {
            std::cout << "destructor C()" << "\n";
        }
    }
};

int C::counter = 0;