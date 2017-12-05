#include <algorithm>
#include <cstdint>
#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

bool CompareStudents(const std::pair<std::string, size_t>& student1,
        const std::pair<std::string, size_t>& student2) {
    if (student1.second == student2.second) {
        return student1.first < student2.first;
    } else {
        return student1.second > student2.second;
    }
}

template <typename TMap, typename TList>
void GetStudentsList(const TMap& students, TList& studentsList) {
    studentsList.reserve(students.size());
    for (auto student : students) {
        studentsList.push_back(make_pair(student.first, student.second.size()));
    }
}

template <typename TVector>
void PrintVector(const TVector& v) {
    for (auto element : v) {
        std::cout << element.first << ' ' << element.second << '\n';
    }
}

template <typename TStudents, typename TSubjects>
void ReadAttempts(TStudents& students, TSubjects& subjects) {
    size_t numAttempts;
    std::cin >> numAttempts;

    std::string student, subject;
    int32_t mark;
    for (size_t i = 0; i < numAttempts; ++i) {
        std::cin >> student >> subject >> mark;
        if (subjects.find(subject) != subjects.end()) {
            if (mark >= subjects[subject]) {
                students[student].insert(subject);
            }
        }
        if (students.find(student) == students.end()) {
            students[student] = {};
        }
    }
}

template <typename TSubjects>
void ReadSubjects(TSubjects& subjects) {
    size_t numSubjects;
    std::cin >> numSubjects;

    std::string subject;
    int32_t mark;
    for (size_t i = 0; i < numSubjects; ++i) {
        std::cin >> subject >> mark;
        subjects[subject] = mark;
    }
}

int main() {
    std::unordered_map<std::string, size_t> minMarks;
    ReadSubjects(minMarks);

    std::unordered_map<std::string, std::unordered_set<std::string>> students;
    ReadAttempts(students, minMarks);

    std::vector<std::pair<std::string, size_t>> studentsList;
    GetStudentsList(students, studentsList);
    std::sort(studentsList.begin(), studentsList.end(), CompareStudents);

    PrintVector(studentsList);
}

