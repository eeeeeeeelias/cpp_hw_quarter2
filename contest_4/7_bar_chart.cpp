#include <ctime>
#include <iostream>
#include <map>
#include <set>

void AddSymbol(char symbol,
        std::set<char>& allSymbols,
        std::map<char, int>& quantity,
        std::map<int, std::set<char>>& symbolsByQuantity) {
    ++quantity[symbol];
    symbolsByQuantity[quantity[symbol]].insert(symbol);
    allSymbols.insert(symbol);
}

void PrintBarChart(size_t maxQuantity,
        const std::set<char>& allSymbols,
        std::map<char, int>& quantity) {
    for (size_t i = maxQuantity; i > 0; --i) {
        for (auto symbol : allSymbols) {
            std::cout << ((quantity[symbol] >= i) ? '#' : ' ');
        }
        std::cout << '\n';
    }
    for (auto symbol : allSymbols) {
        std::cout << symbol;
    }
    std::cout << '\n';
}

int main() {
    clock_t firstTime = clock();
    freopen("input_bar_chart.txt", "rt", stdin);
    std::map<int, std::set<char>> symbolsByQuantity;
    std::set<char> allSymbols;
    std::map<char, int> quantity;
    char symbol;

    while (std::cin >> symbol) {
        AddSymbol(symbol, allSymbols, quantity, symbolsByQuantity);
    }

    size_t maxQuantity = symbolsByQuantity.end()->first;

    PrintBarChart(maxQuantity, allSymbols, quantity);
    clock_t lastTime = clock();
    std::cout << double(lastTime - firstTime) / CLOCKS_PER_SEC << '\n';
}

