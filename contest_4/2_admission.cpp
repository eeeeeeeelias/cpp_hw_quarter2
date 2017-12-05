#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <vector>

struct Date;
int IsEarlier(const Date& d1, const Date& d2);

class Enrollee;
class University;

using UniMap = std::map<std::string, University>;

void PrintStudentLists(UniMap& universitiesMap);
void ReadEnrollees(std::vector<Enrollee>& enrolleesList);
void ReadQuotas(UniMap& universitiesMap);
void RunAdmission(const std::vector<Enrollee>& enrolleesList, UniMap& universitiesMap);

struct Date{
    uint32_t day, month, year;
};

int IsEarlier(const Date& date1, const Date& date2) {  // 1 = "1st is older", -1 = "2nd is older"
    if (date1.year == date2.year) {
        if (date1.month == date2.month) {
            if (date1.day == date2.day) {
                return 0;
            } else {
                return (date1.day < date2.day) ? 1 : -1;
            }
        } else {
            return (date1.month < date2.month) ? 1 : -1;
        }
    } else {
        return (date1.year < date2.year) ? 1 : -1;
    }
}

class Enrollee {
 public:
     bool operator< (Enrollee &s2) {
         if (points == s2.points) {
             int8_t whoIsOlder = IsEarlier(dateOfBirth, s2.dateOfBirth);
             if (whoIsOlder == 1) {
                 return true;
             } else if (whoIsOlder == -1) {
                 return false;
             } else {  // same day of birth
                 if (surname == s2.surname) {
                     return name < s2.name;
                 } else {
                     return surname < s2.surname;
                 }
             }
         } else {
             return points > s2.points;
         }
     }


     bool ChooseUni(UniMap& universitiesMap, std::string& possibleUniName);

     void Read() {
         std::cin >> name >> surname;
         std::cin >> dateOfBirth.day >> dateOfBirth.month >> dateOfBirth.year;
         std::cin >> points >> numUnis;
         universities.resize(numUnis);
         for (size_t i = 0; i < numUnis; ++i) {
             std::cin >> universities[i];
         }
     }

     std::string GetFullName() const {
         return name + ' ' + surname;
     }

     std::string GetName() const {
         return name;
     }

     std::string GetSurname() const {
         return surname;
     }

     Date GetDate() const {
         return dateOfBirth;
     }

 private:
     std::string name, surname;
     Date dateOfBirth;
     size_t points, numUnis;

     std::vector<std::string> universities;
};

bool CompareForOutput(const Enrollee& e1, const Enrollee& e2) {
    if (e1.GetSurname() == e2.GetSurname()) {
        if (e1.GetName() == e2.GetName()) {
            return IsEarlier(e1.GetDate(), e2.GetDate());
        } else {
            return e1.GetName() < e2.GetName();
        }
    } else {
        return e1.GetSurname() < e2.GetSurname();
    }
}

class University {
 public:
    std::vector<Enrollee> studentList;

    University() {}
    University(std::string name, uint32_t places) {
        University::name = name;
        University::numPlaces = places;
    }

    bool IsAvailable() {
        return numPlaces > 0;
    }

    void AddStudent(const Enrollee& person) {
        studentList.push_back(person);
        --numPlaces;
    }

    void SortForOutput() {
        std::sort(studentList.begin(), studentList.end(), CompareForOutput);
    }

 private:
    std::string name;
    uint32_t numPlaces;
};


bool Enrollee::ChooseUni(UniMap& universitiesMap, std::string& possibleUniName) {
    for (auto uniName : universities) {
        if (universitiesMap[uniName].IsAvailable()) {
            possibleUniName = uniName;
            return true;
        }
    }
    return false;
}

void PrintStudentLists(UniMap& universitiesMap) {
    for (auto uni : universitiesMap) {
        std::cout << uni.first;
        uni.second.SortForOutput();
        for (auto student : uni.second.studentList) {
            std::cout << '\t' << student.GetFullName();
        }
        std::cout << '\n';
    }
}

void ReadEnrollees(std::vector<Enrollee>& enrolleesList) {
    size_t numEnrollees;
    std::cin >> numEnrollees;
    enrolleesList.resize(numEnrollees);
    for (size_t i = 0; i < numEnrollees; ++i) {
        enrolleesList[i].Read();
    }
}

void ReadQuotas(UniMap& universitiesMap) {
    size_t numUniversities;
    std::cin >> numUniversities;
    std::string uniName;
    uint32_t numFreePlaces;
    for (size_t i = 0; i < numUniversities; ++i) {
        std::cin >> uniName >> numFreePlaces;
        universitiesMap[uniName] = University(uniName, numFreePlaces);
    }
}

void RunAdmission(const std::vector<Enrollee>& enrolleesList, UniMap& universitiesMap) {
    std::string uniName;
    for (auto enrollee : enrolleesList) {
        bool canEnter = enrollee.ChooseUni(universitiesMap, uniName);
        if (canEnter) {
            universitiesMap[uniName].AddStudent(enrollee);
        }
    }
}

int main() {
    UniMap universities;
    ReadQuotas(universities);

    std::vector<Enrollee> enrollees;
    ReadEnrollees(enrollees);

    std::sort(enrollees.begin(), enrollees.end());
    RunAdmission(enrollees, universities);

    PrintStudentLists(universities);
}
