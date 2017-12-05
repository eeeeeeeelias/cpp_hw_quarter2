#include <algorithm>
#include <iostream>
#include <map>
#include <set>

void AddSymbol(char symbol,
        std::set<char>& allSymbols,
        std::map<char, size_t>& quantity) {
    ++quantity[symbol];
    allSymbols.insert(symbol);
}

size_t GetMaxQuantity(const std::map<char, size_t>& quantity) {
    size_t maxQuantity = 0;
    for (auto element : quantity) {
        maxQuantity = std::max(maxQuantity, element.second);
    }
    return maxQuantity;
}

void PrintBarChart(size_t maxQuantity,
        const std::set<char>& allSymbols,
        std::map<char, size_t>& quantity) {
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
    std::set<char> allSymbols;
    std::map<char, size_t> quantity;
    char symbol;

    while (std::cin >> symbol) {
        AddSymbol(symbol, allSymbols, quantity);
    }

    size_t maxQuantity = GetMaxQuantity(quantity);

    PrintBarChart(maxQuantity, allSymbols, quantity);
}

