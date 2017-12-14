#include "c.h"
#include <iostream>
#include <stack>
#include <vector>

int main() {
    size_t stackSize;
    std::cin >> stackSize;
    std::vector<C> myStack(stackSize);
    for (size_t i = 0; i != stackSize; ++i) {
        myStack.pop_back();
    }
}