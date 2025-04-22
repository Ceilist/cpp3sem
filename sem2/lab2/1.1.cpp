#include <vector>
#include <deque>
#include <list>
#include <array>
#include <iostream>
#include <algorithm>
#include <chrono>

using namespace std;

// Сортировка вставками
// Работает с итераторами с доступом по индексу
template <typename random_access_iterator, typename Compare>
void itersort(random_access_iterator first, random_access_iterator last, Compare comp) {
    if (first == last) return;

    for (auto i = first + 1; i != last; ++i) {
        auto key = *i;
        auto j = i;

        while (j != first && comp(key, *(j - 1))) {
            iter_swap(j, j - 1);
            --j;
        }
    }
}
// Функция сравнивания
bool CompFunc(int a, int b) {
    return a < b;
}


int main() {
    vector<int> iter1 = {3, 5, 2, 1, 8, 4, 6};
    deque<int> iter2 = {8, 3, 6, 5, 1, 4, 2};
    array<int,7> iter3 = {6, 5, 3, 8, 1, 2, 4};
    list<int> iter4 = {5, 1, 2, 3, 8, 6, 4};

    // Работа с функтором и вектором
    itersort(iter1.begin(), iter1.end(), greater<int>());

    // Работа с лямбда-ф и декой
    itersort(iter2.begin(), iter2.end(), [](int a, int b) { return a < b; });

    // Работа с функцией и array
    itersort(iter3.begin(), iter3.end(), CompFunc);

    // С функтором и списком не работает, т.к. не подходит тип итератора
    // itersort(iter4.begin(), iter4.end(), [](int a, int b) { return a < b; });

    // Засекание времени
    auto timer = [](auto& container, const string& name) {
        auto start = chrono::high_resolution_clock::now();
        itersort(container.begin(), container.end(), greater<int>());
        auto end = chrono::high_resolution_clock::now();
        auto duration = chrono::duration_cast<chrono::microseconds>(end - start);
        cout << name << " sorted in: " << duration.count() << " microseconds "<< endl;
    };

    // Заполним дек и вектор случайными элементами
    vector<int> vec(10000);
    deque<int> deq(10000);
    generate(vec.begin(), vec.end(), []() { return rand(); });
    generate(deq.begin(), deq.end(), []() { return rand(); });

    timer(vec, "vector");
    timer(deq, "deque");
    // Вектор сортируется быстрее т.к. непрерывно хранит данные, а у деки элементы могут быть разбросаны в памяти

}
