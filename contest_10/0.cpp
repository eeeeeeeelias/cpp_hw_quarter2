#include "c.h"

int main() {
    C *object1 = new C;
    delete object1;
    C *object2 = new C;
    delete object2;
}

