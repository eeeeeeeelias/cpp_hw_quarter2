#include <cstdint>
#include <iostream>
#include <stack>

int main() {
    std::stack<int64_t> myStack;
    std::string command;
    int64_t newNumber;

    while (std::cin >> command) {
        if (command == "push") {
            std::cin >> newNumber;
            myStack.push(newNumber);
            std::cout << "ok\n";
        } else if (command == "pop") {
            if (!myStack.empty()) {
                std::cout << myStack.top() << '\n';
                myStack.pop();
            } else {
                std::cout << "error\n";
            }
        } else if (command == "back") {
            if (!myStack.empty()) {
                std::cout << myStack.top() << '\n';
            } else {
                std::cout << "error\n";
            }
        } else if (command == "size") {
            std::cout << myStack.size() << '\n';
        } else if (command == "clear") {
            while (!myStack.empty()) {
                myStack.pop();
            }
            std::cout << "ok\n";
        } else if (command == "exit") {
            std::cout << "bye\n";
            return 0;
        } else {
            std::cout << "error\n";
        }
    }
    return 0;
}

