#include <iostream>
#include <vector>

class Time;
int TimeToMinutes(const Time& t);
int TimeToMinutes(int dd, int hh, int mm);
Time MinutesToTime(int minutes);

class Time{
 public:
    Time(int days, int hours, int minutes) {
        Time::dd = days;
        Time::hh = hours;
        Time::mm = minutes;
    }

    Time() {
        Time::dd = 1;
        Time::hh = 0;
        Time::mm = 0;
    }

    void Read() {
        std::cin >> Time::dd >> Time::hh >> Time::mm;
    }

    void Print() const {
        std::cout << Time::dd << ' ' << Time::hh << ' ' << Time::mm << '\n';
    }

    void SetTime(int days, int hours, int minutes) {
        Time::dd = days;
        Time::hh = hours;
        Time::mm = minutes;
    }

    void SetTime(const Time& time) {
        Time::dd = time.dd;
        Time::hh = time.hh;
        Time::mm = time.mm;
    }

    void AddTime(int days, int hours, int minutes) {
        int date = TimeToMinutes(Time::dd, Time::hh, Time::mm);
        int term = TimeToMinutes(days, hours, minutes);
        Time::SetTime(MinutesToTime(date + term));
    }

    void AdjustZero(const Time& currentTime) {
        if (Time::dd == 0) {
            if ((Time::hh < currentTime.hh) ||
                    (Time::hh == currentTime.hh && Time::mm < currentTime.mm)) {
                Time::dd = currentTime.dd + 1;
            } else {
                Time::dd = currentTime.dd;
            }
        }
    }

    void AdjustTime() {
        if (Time::dd > 7) {
            Time::dd -= 7;
        }
    }

    friend int operator- (const Time& t1, const Time& t2) {
        Time _t1 = t1;
        if ((t1.dd < t2.dd) ||
                (t1.dd == t2.dd && t1.hh < t2.hh) ||
                (t1.dd == t2.dd && t1.hh == t2.hh && t1.mm < t2.mm)
        ) {
            _t1.AddTime(7, 0, 0);
        }
        return TimeToMinutes(_t1) - TimeToMinutes(t2);
    }

    void getDHM(int& d, int& h, int& m) const {
        d = Time::dd;
        h = Time::hh;
        m = Time::mm;
    }

 private:
    int dd, hh, mm;
};


int TimeToMinutes(int d, int h, int m) {
    return d * 24 * 60 + h * 60 + m;
}

int TimeToMinutes(const Time& t) {
    int d, h, m;
    t.getDHM(d, h, m);
    return d * 24 * 60 + h * 60 + m;
}

Time MinutesToTime(int minutes) {
    int mm = minutes % 60;
    minutes /= 60;
    int hh = minutes % 24;
    minutes /= 24;
    int dd = minutes;
    if (dd == 0) {
        dd = 7;
    }
    Time time(dd, hh, mm);
    return time;
}

void ReadAlarmClocks(std::vector<Time>& times) {
    size_t numAlarmClocks;
    std::cin >> numAlarmClocks;
    times.resize(numAlarmClocks);
    for (size_t i = 0; i < numAlarmClocks; ++i) {
        times[i].Read();
    }
}

void AdjustDailyAlarmClocks(std::vector<Time>& times, const Time& currentTime) {
    for (size_t i = 0; i < times.size(); ++i) {
        times[i].AdjustZero(currentTime);
    }
}

Time GetFirstAlarmTime(const std::vector<Time>& candidates, const Time& currentTime) {
    int minTimeGap = candidates[0] - currentTime;
    Time firstAlarmTime = candidates[0];
    for (size_t i = 1; i < candidates.size(); ++i) {
        if (candidates[i] - currentTime < minTimeGap) {
            minTimeGap = candidates[i] - currentTime;
            firstAlarmTime = candidates[i];
        }
    }
    return firstAlarmTime;
}

int main() {
    Time currentTime;
    currentTime.Read();
    std::vector<Time> alarmClocks;
    ReadAlarmClocks(alarmClocks);
    AdjustDailyAlarmClocks(alarmClocks, currentTime);
    Time firstAlarm = GetFirstAlarmTime(alarmClocks, currentTime);
    firstAlarm.AdjustTime();
    firstAlarm.Print();
    return 0;
}
