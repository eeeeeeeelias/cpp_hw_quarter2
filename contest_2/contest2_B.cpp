#include <iostream>
#include <string>
#include <vector>


std::vector<std::vector<std::string>> ASCIITable() {
    std::vector<std::vector<std::string>> table(6, std::vector<std::string>(16));
    for (int i = 0; i != 6; ++i) {
        for (int j = 0; j != 16; ++j) {
            if ((i == 0) && (j == 0)) {
                table[i][j] = "";
            } else {
                table[i][j] = static_cast<char> (j + 16 * (i + 2));
            }
        }
    }
    return table;
}

void PrintTable(const std::vector<std::vector<std::string>> table) {
    for (int i = 0; i != 7; ++i) {
        for (int j = 0; j != 17; ++j) {
            if ((i == 0) && (j < 10)) {
                std::cout << "\t" << j;
            } else if (i == 0) {
                if (j < 16) {
                    std::cout << "\t" << static_cast<char> (j - 10 + static_cast<int> ('A'));
                }
            } else if (j == 0) {
                std::cout << i + 1;
            } else {
                std::cout << "\t" << table[i - 1][j - 1];
            }
        }
        std::cout << "\n";
    }
}

int main() {
    PrintTable(ASCIITable());
}
