#include <cstdint>
#include <iostream>
#include <queue>

int main() {
    std::queue<int64_t> myQueue;
    std::string command;
    int64_t newNumber;

    while (std::cin >> command) {
        if (command == "push") {
            std::cin >> newNumber;
            myQueue.push(newNumber);
            std::cout << "ok\n";
        } else if (command == "pop") {
            if (!myQueue.empty()) {
                std::cout << myQueue.front() << '                                                     \n';
                myQueue.pop();
            } else {
                std::cout << "error\n";
            }
        } else if (command == "front") {
            if (!myQueue.empty()) {
                std::cout << myQueue.front() << '\n';
            } else {
                std::cout << "error\n";
            }
        } else if (command == "size") {
            std::cout << myQueue.size() << '\n';
        } else if (command == "clear") {
            while (!myQueue.empty()) {
                myQueue.pop();
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

