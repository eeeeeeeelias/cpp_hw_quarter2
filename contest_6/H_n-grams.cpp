#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
#include <utility>
#include <vector>

class NGram {
 public:
    NGram() {
        line = "";
    }

    void Add(std::string token) {
        line += token + ' ';
    }

    void Print() const {
        std::cout << line;
    }

    void Push(std::string token) {
        line += token + ' ';
        int spacePos = line.find(' ');
        line = line.substr(spacePos + 1);
    }

    std::string GetLine() const {
        return line;
    }

 protected:
    std::string line = "";
};

bool CompareNGrams(
        const std::pair<std::string, size_t>& nGram1,
        const std::pair<std::string, size_t>& nGram2) {
    if (nGram1.second == nGram2.second) {
        return nGram1.first < nGram2.first;  // compare lines
    } else {
        return nGram1.second > nGram2.second;  // compare frequencies
    }
}

template <typename TMap, typename TVector>
void MapToVector(const TMap& myMap, TVector& myVector) {
    for (const auto& element : myMap) {
        myVector.push_back(std::make_pair(element.first, element.second));
    }
}

template <typename TVector>
void PrintVector(const TVector& v) {
    for (const auto& element : v) {
        std::cout << element.first << "- " << element.second << '\n';
    }
}

template <typename TMap>
void ReadNGrams(
        size_t numWords,
        size_t nGramSize,
        TMap& frequency) {
    NGram currentNGram;
    std::string token;
    for (size_t i = 0; i < nGramSize; ++i) {
        std::cin >> token;
        currentNGram.Add(token);
    }
    ++frequency[currentNGram.GetLine()];
    for (size_t i = nGramSize; i < numWords; ++i) {
        std::cin >> token;
        currentNGram.Push(token);
        ++frequency[currentNGram.GetLine()];
    }
}

int main() {
    size_t numWords, nGramSize;
    std::cin >> numWords >> nGramSize;
    if (numWords >= nGramSize) {
        std::unordered_map<std::string, size_t> frequency;
        ReadNGrams(numWords, nGramSize, frequency);

        std::vector<std::pair<std::string, size_t>> allNGrams;
        MapToVector(frequency, allNGrams);

        std::sort(allNGrams.begin(), allNGrams.end(), CompareNGrams);

        PrintVector(allNGrams);
    }
}

