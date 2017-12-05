#include <algorithm>
#include <iostream>
#include <stack>
#include <unordered_set>
#include <unordered_map>
#include <string>

bool IsSequenceTrue(std::string& line) {
    std::stack<char> sequence;
    std::unordered_set<char> openSymbols{'{', '(', '['};
    std::unordered_map<char, char> openClose {
        {'{', '}'},
        {'(', ')'},
        {'[', ']'}
    };
    for (auto elem : line) {
        std::cout << "current element is " << elem << '\n';
        if (openSymbols.find(elem) == openSymbols.end()) {
            std::cout << "pushing\n";
            sequence.push(elem);
            std::cout << "pushed\n";
        } else {
            std::cout << "sequence.size() is " << sequence.size() << "\n";
            std::cout << "sequence.top() is " << sequence.top() << "\n";
            if (elem != openClose[sequence.top()]) {
                std::cout << "returning false...\n";
                return false;
            } else {
                std::cout << "popping\n";
                sequence.pop();
                std::cout << "popped\n";
            }
        }
        std::cout << "stack size is " << sequence.size() << '\n';
    }
    return true;
}


int main() {
    std::string sequence;
    std::cin >> sequence;
    std::cout << (IsSequenceTrue(sequence) ? "yes" : "no") << '\n';
}
