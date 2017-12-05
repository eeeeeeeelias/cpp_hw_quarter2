#include <iostream>
#include <string>

int main() {
    std::string number1, number2;
    std::cin >> number1 >> number2;
    char comparison;
    if (number1 < number2) {
        comparison = '<';
    } else if (number1 > number2) {
        comparison = '>';
    } else {
        comparison = '=';
    }
    std::cout << comparison << '\n';
    return 0;
}
