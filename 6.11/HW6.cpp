#include <string>
#include <iostream>
#include <windows.h>
using namespace std;

class Animal {
    int health;

protected:

    string const name;
    string const breed;
    int age;


public:
    Animal(string Name, string Breed, int Age, int x): name{Name}, breed{Breed} {
        age = Age;
        health = x;
    };
    virtual void makeSound() = 0;

    void getInfo() {
        cout << age << breed << name << endl;
    }

    friend class Doctor;
};

class Cat : public Animal {
public:
    Cat(string Name, string Breed, int Age, int Health): Animal(Name, Breed, Age, Health) {
    };

    void makeSound() override {
        cout << "Мяу" << endl;
    }
};

class Dog : public Animal {
public:
    Dog(string Name, string Breed, int Age, int Health): Animal(Name, Breed, Age, Health) {
    };

    void makeSound() override {
        cout << "Гав" << endl;
    }
};


class Owner {
    struct FIO {
        string const name;
        string const surname;
        string const patronymic;
    };

    FIO fio;
    int age;

public:
    int count;
    Animal **pets;

    Owner(string Name, string Surname, string Patronymic, int Age, int Count): fio{Name, Surname, Patronymic} {
        age = Age;
        count = Count;
        pets = new Animal *[count];
    }

    friend class Doctor;
};

class Doctor {
public:
    void check(Animal &animal) {
        cout << "Здоровье "<< animal.name +": "<< animal.health << endl;
    }

    void heal(Animal &animal) {
        animal.health = 100;
    }

    void talk(Owner &owner, Animal &animal) {
        if (animal.health < 100) {
            cout << owner.fio.name + " " + owner.fio.patronymic + ", " << animal.name << " болен" << endl;
        } else {
            cout << owner.fio.name + " " + owner.fio.patronymic + ", " << animal.name << " здоров" << endl;
        };
    }
};


int main() {
    SetConsoleOutputCP(CP_UTF8);
    Owner Example("Иван", "Иванов", "Иванович", 30, 2);
    Example.pets[0] = new Dog("Собака", "Овчарка", 5, 70);
    Example.pets[1] = new Cat("Кошка", "Дворняга", 5, 50);
    Doctor doctor;
    doctor.check(*Example.pets[1]);
    doctor.talk(Example, *Example.pets[1]);
    doctor.heal(*Example.pets[1]);
    doctor.heal(*Example.pets[0]);
    doctor.check(*Example.pets[1]);
    doctor.check(*Example.pets[0]);
    Example.pets[1]->makeSound();

    delete &Example; // (без этой строчки CLion жалуется на утечку памяти, но как я понимаю, деструктор вызывается сам при завершении main.
    // Если эту строчку оставить, то утечка памяти "пропадает" (а может и нет, но жалобы на неё нет)
    return 0;
}
