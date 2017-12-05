#include <iostream>
#include <vector>

struct Date{
    int day, month, year;
};

void ReadDate(Date& date) {
    std::cin >> date.day >> date.month >> date.year;
}

bool IsYearLeap(int y) {
    if (y % 400 == 0) {
        return true;
    } else if (y % 100 == 0) {
        return false;
    } else if (y % 4 == 0) {
        return true;
    } else {
        return false;
    }
}

const std::vector<int> MONTH_ENDS = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

void GetTomorrow(Date& date) {
    // normal day, like 05.05.1955
    // end of februar
    // end of december
    // end of normal month
    if (date.day < MONTH_ENDS[date.month]) {  // normal day
        ++date.day;
    } else if (date.month == 2) {
        if (date.day == 29) {  // 29.2 -> 1.3
            date.day = 1;
            date.month = 3;
        } else {  // 28.2
            if (IsYearLeap(date.year)) {
                ++date.day;
            } else {
                date.day = 1;
                date.month = 3;
            }
        }
    } else if (date.month == 12) {
        date.day = 1;
        date.month = 1;
        ++date.year;
    } else {  // end of 1/3..11 month
        date.day = 1;
        ++date.month;
    }
}

void PrintDate(Date& date) {
    std::cout << date.day << ' ' << date.month << ' ' << date.year << '\n';
}

int main() {
    Date currentDate;
    ReadDate(currentDate);
    GetTomorrow(currentDate);
    GetTomorrow(currentDate);
    PrintDate(currentDate);
}
