#include <iostream>
#include <unordered_map>

void makeChangeMap(
        std::unordered_map<char, char>& changeMap,
        const std::string& toChange,
        const std::string& changers) {
    for (size_t i = 0; i != toChange.size(); ++i) {
        changeMap[toChange[i]] = changers[i];
    }
}

void Change(std::unordered_map<char, char>& changeMap, std::string& inputString) {
    for (size_t i = 0; i != inputString.size(); ++i) {
        if (changeMap.find(inputString[i]) != changeMap.end()) {
            inputString[i] = changeMap[inputString[i]];
        }
    }
}

int main() {
    freopen("input.txt", "rt", stdin);
    std::string toChange, changers;
    std::getline(std::cin, toChange);
    std::getline(std::cin, changers);
    std::unordered_map<char, char> changeMap;
    makeChangeMap(changeMap, toChange, changers);
    std::string inputStream;
    while (std::getline(std::cin, inputStream)) {
        Change(changeMap, inputStream);
        std::cout << inputStream << '\n';
    }
}
