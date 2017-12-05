#include <cstdint>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>

void CreateSubjectIndex(std::map<std::string, std::set<int32_t>>& words) {
    size_t numOccurences;
    std::cin >> numOccurences;

    std::string word;
    int32_t page;
    for (size_t i = 0; i < numOccurences; ++i) {
        std::cin >> page >> word;
        if (words.find(word) != words.end()) {
            words[word].insert(page);
        } else {  // new word
            words[word] = {page};
        }
    }
}

void PrintSubjectIndex(const std::map<std::string, std::set<int32_t>>& words) {
    for (auto word : words) {
        std::cout << word.first;
        for (auto page : word.second) {
            std::cout << ' ' << page;
        }
        std::cout << '\n';
    }
}

int main() {
    std::map<std::string, std::set<int32_t>> words;
    CreateSubjectIndex(words);
    PrintSubjectIndex(words);
}

