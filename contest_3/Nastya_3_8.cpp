#include <iostream>
 
using namespace std;
 
struct Time {
    int day;
    int hour;
    int minutes;
};
 
int in_minutes(Time al) {
    return ((al.day - 1) * 24 * 60 + al.hour * 60 + al.minutes);
}
 
void every_day_alarm(Time cur, Time& al) {
    al.day = cur.day;
    if (in_minutes(cur) > in_minutes(al))
        al.day++;
    if (al.day > 7)
        al.day = 1;
}
 
int difference(int time1, int time2) {
    if (time1 <= time2) {
        return (time2 - time1);
    } else {
        return (7 * 24 * 60 - time1 + time2);
    }
}
 
int main() {
    Time cur;
    cin >> cur.day >> cur.hour >> cur.minutes;
    int n;
    cin >> n;
    int mindif = 7 * 24 * 60 + 1;
    Time minalarm, alarm;
    for (int i = 0; i < n; ++i) {
        cin >> alarm.day >> alarm.hour >> alarm.minutes;
        if (alarm.day == 0)
            every_day_alarm(cur, alarm);
        if (mindif > difference(in_minutes(cur), in_minutes(alarm))) {
            mindif = difference(in_minutes(cur), in_minutes(alarm));
            minalarm.day = alarm.day;
            minalarm.hour = alarm.hour;
            minalarm.minutes = alarm.minutes;
        }
    }
    cout << minalarm.day << " " << minalarm.hour << " " << minalarm.minutes << endl;
}
