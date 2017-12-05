#include <algorithm>
#include <cstdint>
#include <iostream>
#include <map>
#include <unordered_map>
#include <string>
#include <unordered_set>

void InputExam(std::unordered_map<std::string, int64_t>& examList) {
    int n = 0;
    std::cin >> n;
    std::string name;
    int64_t mark;
    for (int i = 0; i != n; ++i) {
        std::cin >> name >> mark;
        examList[name] = mark;
    }
}

void InputResults(std::unordered_map<std::string, int64_t>& examList,
                  std::map<std::string, std::unordered_set<std::string>>& resultsList) {
    std::string student, examName;
    int64_t mark, m;
    std::cin >> m;
    for (int64_t i = 0; i != m; ++i) {
        std::cin >> student >> examName >> mark;
        if (mark >= examList[examName]) {
            resultsList[student].insert(examName);
        }
    }
}

bool CompareStudents(std::pair<std::string, std::unordered_set<std::string>>& a,
                      std::pair<std::string, std::unordered_set<std::string>>& b) {
    if (a.second.size() == b.second.size()) {
        return a.first < b.first;
    } else {
        return a.second.size() > b.second.size();
    }
}

// void MapToVector(std::unordered_map a, std::vector<)

void OutputResults(const std::map<std::string, std::unordered_set<std::string>>& table) {
    for (auto item : table) {
        std::cout << item.first << ' ' << item.second.size() << '\n';
    }
}

int main() {
    /*std::unordered_map<std::string, int64_t> examMin;
    std::map<std::string, std::unordered_set<std::string>> results;
    InputExam(examMin);
    InputResults(examMin, results);
    std::sort(results.begin(), results.end(), CompareStudents);
    OutputResults(results);*/
    std::pair<std::string, std::unordered_set<std::string>> p1, p2;
    p1.first = "abc";
    p1.second.insert("5");
    p1.second.insert("10");
    p1.second.insert("sadfsffa");
    p2.first = "def";
    p2.second.insert("1");
    p2.second.insert("2");
    p2.second.insert("3");
    std::cout << (CompareStudents(p1, p2) ? "p1" : "p2") << '\n';
}
