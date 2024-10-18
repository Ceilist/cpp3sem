#include <iostream>
#include <ostream>
#include <string>
#include <windows.h>
using namespace std;

struct Author {
    string name;
    string surname;
};

struct Book {
    string name = "Неизвестно";
    Author author{"Неизвестно", "Неизвестно"};
    int year = 0;
    int size = 0;

    void displayBook() {
        cout << "Название: " << this->name << endl;
        cout << "Автор: " << this->author.name << " " << this->author.surname << endl;
        cout << "Год издания: " << this->year << endl;
        cout << "Количество страниц: " << this->size << endl;
    };
};

Book createBook() {
    Book book;
    cout << "Название книги"<<endl;
    cin >> book.name;
    cout << "Имя автора"<<endl;
    cin >> book.author.name;
    cout << "Фамилия автора"<<endl;
    cin >> book.author.surname;
    cout << "Год"<<endl;
    cin >> book.year;
    cout << "Число страниц"<<endl;
    cin >> book.size;

    return book;
};

int main() {

    SetConsoleOutputCP(CP_UTF8);
    Book Books[3]{Book() ,createBook(), createBook()};
    for(int i = 0; i < 3; i++) {
        Books[i].displayBook();
    };
};
