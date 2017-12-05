#include <algorithm>
#include <iostream>
#include <stack>
#include <unordered_set>
#include <unordered_map>
#include <string>

bool IsSequenceTrue() {
    char elem;
    std::stack<char> sequence;
    std::unordered_set<char> open {'{', '(', '['};
    std::unordered_map<char, char> openClose {
            {'{', '}'},
            {'(', ')'},
            {'[', ']'}
    };
    while (std::cin >> elem) {
        std::cout << "current element is " << elem << '\n';
        if (open.find(elem) != open.end()) {
            std::cout << "pushing\n";
            sequence.push(elem);
        } else {  // closing bracket
            std::cout << "closing bracket\n";
            if (sequence.empty()) {
                return false;
            } else if (elem != openClose[sequence.top()]) {
                return false;
            } else {
                sequence.pop();
            }
        }
        std::cout << "now stack size is " << sequence.size() << '\n';
    }
    std::cout << "gonna return\n";
    return sequence.empty();
}


int main() {
    std::cout << (IsSequenceTrue() ? "yes" : "no") << '\n';
}
