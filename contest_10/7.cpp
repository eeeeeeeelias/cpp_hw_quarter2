#include "c.h"

int main() {
    C object1;
    D object3(object1, object1, &object1);
    D object4 = std::move(object3);
}
