#include <iostream>
#include <set>
#include <string>

template <typename T>
void PrintSet(const std::set<T>& mySet) {
    for (auto element : mySet) {
        std::cout << element;
    }
    std::cout << '\n';
}

void StringToSet(const std::string& myLine, std::set<char>& mySet) {
    for (auto letter : myLine) {
       mySet.insert(letter);
    }
}

std::set<char> SetIntersection(const std::set<char>& set1, const std::set<char>& set2) {
    std::set<char> answerSet;
    for (auto letter : set1) {
        if (set2.find(letter) != set2.end()) {
            answerSet.insert(letter);
        }
    }
    return answerSet;
}

int main() {
    std::set<char> commonLetters;
    std::string currentLine;

    if (std::getline(std::cin, currentLine)) {
        StringToSet(currentLine, commonLetters);
        std::set<char> currentLineSet;
        while (std::getline(std::cin, currentLine)) {
            currentLineSet.clear();
            StringToSet(currentLine, currentLineSet);
            commonLetters = SetIntersection(commonLetters, currentLineSet);
        }
    }

    PrintSet(commonLetters);
}

