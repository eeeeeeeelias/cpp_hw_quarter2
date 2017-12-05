#include <algorithm>
#include <iostream>
#include <vector>

struct Student{
    std::string name, surname;
    int year, month, day;
};

bool CompareSurnames(Student& s1, Student& s2);
bool CompareDates(Student& s1, Student& s2);

bool CompareSurnames(Student& s1, Student& s2) {
    if (s1.surname == s2.surname) {
        if (s1.name == s2.name) {
            return CompareDates(s1, s2);
        } else {
            return s1.name < s2.name;
        }
    } else {
        return s1.surname < s2.surname;
    }
}

bool CompareDates(Student& s1, Student& s2) {
    if (s1.year == s2.year) {
        if (s1.month == s2.month) {
            if (s1.day == s2.day) {
                return CompareSurnames(s1, s2);
            } else {
                return s1.day < s2.day;
            }
        } else {
            return s1.month < s2.month;
        }
    } else {
        return s1.year < s2.year;
    }
}

void ReadStudent(Student& student) {
    std::cin >> student.name >> student.surname >> student.day >> student.month >> student.year;
}

void PrintStudent(Student& student) {
    std::cout << student.name << ' ' << student.surname << ' '
        << student.day << '.' << student.month << '.' << student.year << '\n';
}

int main() {
    size_t numStudents;
    std::cin >> numStudents;
    std::vector<Student> students(numStudents);
    for (size_t student = 0; student < numStudents; ++student) {
        ReadStudent(students[student]);
    }
    std::string sortingType;
    std::cin >> sortingType;
    if (sortingType == "date") {
        std::sort(students.begin(), students.end(), CompareDates);
    } else {
        std::sort(students.begin(), students.end(), CompareSurnames);
    }
    for (auto student : students) {
        PrintStudent(student);
    }
}

