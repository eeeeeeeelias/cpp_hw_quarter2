#include <iostream>
#include <string>

std::string IgnoreSpacesInput() {
    std::string s = "";
    char c;
    while (std::cin >> c) {
        if (c != ' ') {
            s += c;
        }
    }
    return s;
}

bool IsPalindrome(const std::string& s) {
    for (size_t i = 0; i < s.size() / 2; ++i) {
        if (s[i] != s[s.size() - i - 1]) {
            return false;
        }
    }
    return true;
}

int main() {
    std::string candidate = IgnoreSpacesInput();
    std::cout << (IsPalindrome(candidate) ? "yes" : "no") << '\n';
    return 0;
}

