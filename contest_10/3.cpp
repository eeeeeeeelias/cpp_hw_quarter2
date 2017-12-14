#include "c.h"
#include <iostream>
#include <stack>
#include <vector>

int main() {
    C object1;
    C object2;
    object1 = object2;
    object1 = std::move(object2);
}