#include <chrono>
#include <string>
#include <stdexcept>
using namespace std;

class Time {
private:
    int hours;
    int minutes;
    int seconds;

    void normalize() {
        if (seconds >= 60) {
            minutes += seconds / 60;
            seconds = seconds % 60;
        } else if (seconds < 0) {
            int borrow = (abs(seconds) + 59) / 60;
            minutes -= borrow;
            seconds += borrow * 60;
        }
        if (minutes >= 60) {
            hours += minutes / 60;
            minutes = minutes % 60;
        } else if (minutes < 0) {
            int borrow = (abs(minutes) + 59) / 60;
            hours -= borrow;
            minutes += borrow * 60;
        }
    }

public:
    Time() {
        hours = minutes = seconds = 0;
    };

    Time(int h, int m, int s) {
        hours = h;
        minutes = m;
        seconds = s;
    };

    Time operator +=(Time t) {
        hours += t.hours;
        minutes += t.minutes;
        seconds += t.seconds;
        normalize();
    }

    Time operator +=(int a) {
        hours += a;
        normalize();
    }
    Time operator -=(int a) {
        hours -= a;
        normalize();
    }

    bool checkday() {
        normalize();
        if (hours >= 24) {
            hours-=24;
            return true;
        }
        return false;
    }
};

class Student {
private:
    const string name;
    const string surname;
    unsigned group;
    int xp;
    unsigned age = 19;
    int money;
    Time stud_time;
    Time time;

public:
    int grade;

    Student(string Name, string Surname, int Group, int XP, int Money, Time Stud_time) : name{Name}, surname{Surname} {
        group = Group;
        xp = XP;
        money = Money;
        stud_time = Stud_time;
        grade = 10;
    };

    Student(string Name, string Surname, int Group, int XP, int Money, Time Stud_time,
            int Grade): name{Name}, surname{Surname} {
        group = Group;
        xp = XP;
        money = Money;
        stud_time = Stud_time;
        grade = Grade;
    }

    void food(int XP, int Money, Time eat) {
        xp += 10 * XP;
        money -= Money;
        time += eat;
    }

    void study(int hours, int XP) {
        stud_time += hours;
        xp -= 30 * XP;
        time+=hours;
    }

    void sleep(int hours, int XP) {
        if (hours >= 6) {
            stud_time = {0, 0, 0};
        } else {
            stud_time -= hours/2;
        }
        time+=hours;
        time.checkday();
        xp += 100 * XP;
    }
    void work(int hours, int Money, int XP) {
        money+=Money;
        time+=hours;
        if (time.checkday()) {
            xp-=3*XP;

        } else {
            xp-=XP;
        }
    }
     void party(int hours, int XP, int Money) {
        if (money-Money<=0) {
            throw out_of_range("No money, go to work!");
        }
        money-=Money;
        time+=hours;
        if (time.checkday()) {
    }
};

int main() {
    Time time(25, 40, 10);
}
