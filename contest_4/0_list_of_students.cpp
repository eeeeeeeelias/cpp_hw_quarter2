#include <iostream>
#include <vector>

struct Student{
    std::string name, surname;
    int year, month, day;
};

void ReadStudent(Student& student) {
    std::cin >> student.name >> student.surname >> student.day >> student.month >> student.year;
}

void ProcessQuery(const std::vector<Student>& students) {
    int studentNumber;
    std::string query;
    std::cin >> query >> studentNumber;
    --studentNumber;
    if (0 <= studentNumber && studentNumber < students.size()) {
        if (query == "name") {
            std::cout << students[studentNumber].name << ' '
                << students[studentNumber].surname << '\n';
        } else if (query == "date") {
            std::cout << students[studentNumber].day << '.' << students[studentNumber].month
                << '.' << students[studentNumber].year << '\n';
        } else {
            std::cout << "bad request\n";
        }
    } else {
        std::cout << "bad request\n";
    }
}

int main() {
    size_t numStudents, numQueries;
    std::cin >> numStudents;
    std::vector<Student> students(numStudents);
    for (size_t student = 0; student < numStudents; ++student) {
        ReadStudent(students[student]);
    }
    std::cin >> numQueries;
    for (size_t query = 0; query < numQueries; ++query) {
        ProcessQuery(students);
    }
}
