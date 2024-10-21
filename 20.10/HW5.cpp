#include <chrono>
#include <string>
#include <stdexcept>
#include <iostream>
#include <windows.h>
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

    Time& operator +=(Time t) {
        hours += t.hours;
        minutes += t.minutes;
        seconds += t.seconds;
        normalize();
    }

    Time& operator +=(int a) {
        hours += a;
        normalize();
    }

    Time& operator -=(int a) {
        hours -= a;
        normalize();
    }

    bool checkday() {
        normalize();
        if (hours >= 24) {
            hours -= 24;
            return true;
        }
        return false;
    }

    bool checkstudy() {
        if (hours >= 12) {
            return true;
        }
        return false;
    }

    int *output() {
        static int a[3]{hours, minutes, seconds};
        return a;
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

    Student(string Name, string Surname, unsigned Group, int XP, int Money, Time Stud_time)
        : name{Name}, surname{Surname} {
        group = Group;
        xp = XP;
        money = Money;
        stud_time = Stud_time;
        grade = 10;
    };

    Student(string Name, string Surname, int Group, int XP, int Money, Time Stud_time,
            int Grade)
        : name{Name}, surname{Surname} {
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
        time += hours;
        if (xp <= 0) {
            delete this;
        }
    }

    void sleep(int hours, int XP) {
        if (hours >= 6) {
            stud_time = {0, 0, 0};
        } else {
            stud_time -= hours / 2;
        }
        time += hours;
        time.checkday();
        xp += 100 * XP;
    }

    void work(int hours, int Money, int XP) {
        money += Money;
        time += hours;
        if (time.checkday()) {
            xp -= 3 * XP;
        } else {
            xp -= XP;
        }
        if (xp <= 0) {
            delete this;
        }
    }

    void party(int hours, int XP, int Money) {
        if (money <Money) {
            throw out_of_range("No money, go to work!");
        }
        money -= Money;
        time += hours;
        if (time.checkday() or stud_time.checkstudy()) {
            xp += XP / 3;
        } else {
            xp += XP;
        }
    }

    int getXP() {
        return xp;
    }

    int getMoney() {
        return money;
    }

    int getTime() {
        return *time.output();
    }

    ~Student() {
        cout << "Вы проиграли. Студент ушел в академ.";
    }

    void getInfo() {
        cout << "Имя: " << name << endl;
        cout << "Фамилия: " << surname << endl;
        cout << "Группа: " << group << endl;
        cout << "Опыт (XP): " << xp << endl;
        cout << "Количество денег: " << money << endl;
        cout << stud_time.output() << endl;
        cout << time.output() << endl;
    }
};

int main() {
    SetConsoleOutputCP(CP_UTF8);
    Student Mikhail("Mikhail", "Zotov", 301, 1000, 100000, Time());


    Mikhail.sleep(0, 200);
    cout<<Mikhail.getXP();

    exit(0);
}
