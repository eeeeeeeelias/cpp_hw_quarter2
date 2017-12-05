#include <algorithm>
#include <cstdint>
#include <ctime>
#include <iostream>
#include <map>
#include <unordered_map>
#include <string>


void PentagonText(std::map<char, int64_t>& table, int64_t& maxSize) {
    std::string line;
    while (std::cin >> line) {
        for (auto elem : line) {
            ++table[elem];
            if (maxSize < table[elem]) {
                maxSize = table[elem];
            }
        }
    }
}

void OutputHistogram(const std::map<char, int64_t>& table, int64_t maxSize) {
    std::string outputString = "";
    for (int64_t i = maxSize; i != 0; --i) {
        for (auto item : table) {
            if (i == maxSize) {
                outputString += item.first;
            }
            if (item.second >= i) {
                std::cout << '#';
            } else {
                std::cout << ' ';
            }
        }
        std::cout << '\n';
    }
    std::cout << outputString;
}

int main() {
    clock_t firstTime = clock();
    freopen("input_bar_chart.txt", "rt", stdin);
    std::map<char, int64_t> information;
    int64_t maxSize = 0;
    PentagonText(information, maxSize);
    OutputHistogram(information, maxSize);
    clock_t lastTime = clock();
    std::cout << '\n' << (double(lastTime - firstTime) / CLOCKS_PER_SEC) << '\n';
}
