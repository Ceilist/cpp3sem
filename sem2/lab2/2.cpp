#include <iostream>
#include <tuple>

using namespace std;


// Реализация получения хвоста
template<typename Tuple, size_t... index>
auto tail_impl(const Tuple &t, index_sequence<index...>) {
    return make_tuple(get<index + 1>(t)...);
}

// Шаблонный вызов
template<typename Head, typename... Tail>
auto tail(const tuple<Head, Tail...> &t) {
    return tail_impl(t, make_index_sequence<sizeof...(Tail)>());
}

// Выход из рекурсии
void print_tuple(const tuple<> &) {
}

// В рекурсии печатаем голову и вызываем функцию от хвоста
template<typename Head, typename... Tail>
void print_tuple(const tuple<Head, Tail...> &t) {
    cout << get<0>(t) << endl;
    print_tuple(tail(t));
}


// Использование
int main() {
    int b = 5;
    auto tup = make_tuple(52, 2.718, "tralalelo", &b, ref(b));
    print_tuple(tup);
}
