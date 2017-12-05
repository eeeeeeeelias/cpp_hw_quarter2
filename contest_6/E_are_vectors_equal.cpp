#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

void ReadVector(std::vector<std::string>& myVector) {
    std::string temp;
    std::getline(std::cin, temp);
    for (size_t i = 0; i < myVector.size(); ++i) {
        std::getline(std::cin, myVector[i]);
    }
}

int main() {
    size_t vectorSize;
    std::cin >> vectorSize;
    std::vector<std::string> vector1(vectorSize), vector2(vectorSize);

    ReadVector(vector1);
    ReadVector(vector2);

    bool areEqual = std::equal(vector1.begin(), vector1.end(), vector2.begin());
    std::cout << (areEqual ? "EQUAL" : "NOT EQUAL") << '\n';
}

