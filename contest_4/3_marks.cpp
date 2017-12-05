#include <iostream>
#include <map>
#include <string>

struct Marks{
    int64_t numTests, sumOfMarks;
};

void ProcessOneTest(std::map<std::string, Marks>& persons) {
    size_t numTests;
    std::cin >> numTests;
    std::string name;
    int mark;
    Marks firstMark;
    for (size_t i = 0; i < numTests; ++i) {
        std::cin >> name >> mark;
        if (persons.find(name) == persons.end()) {
            firstMark.numTests = 1;
            firstMark.sumOfMarks = mark;
            persons[name] = firstMark;
        } else {
            ++persons[name].numTests;
            persons[name].sumOfMarks += mark;
        }
        std::cout << (persons[name].sumOfMarks / persons[name].numTests) << '\n';
    }
}

int main() {
    std::map<std::string, Marks> pupils;
    ProcessOneTest(pupils);
}

