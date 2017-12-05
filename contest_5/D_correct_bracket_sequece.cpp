#include <iostream>
#include <stack>

bool IsSequenceCorrect() {
    char currentBracket;
    std::stack<char> brackets;
    while (std::cin >> currentBracket) {
        if (currentBracket == ')') {
            if (brackets.empty()) {
                return false;
            } else if (brackets.top() != '(') {
                return false;
            } else {
                brackets.pop();
            }
        } else if (currentBracket == ']') {
            if (brackets.empty()) {
                return false;
            } else if (brackets.top() != '[') {
                return false;
            } else {
                brackets.pop();
            }
        } else if (currentBracket == '}') {
            if (brackets.empty()) {
                return false;
            } else if (brackets.top() != '{') {
                return false;
            } else {
                brackets.pop();
            }
        } else {
            brackets.push(currentBracket);
        }
    }
    return brackets.empty();
}

int main() {
    std::cout << (IsSequenceCorrect() ? "yes" : "no") << '\n';
}
