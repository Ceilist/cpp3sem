#include <array>
#include <tuple>
#include <iostream>

using namespace std;



// Выход из рекурсии
template<typename T, size_t N>
constexpr auto product(const array<T, N> &arr) {
    array<tuple<T>, N> result{};
    for (size_t i = 0; i < N; ++i) {
        result[i] = make_tuple(arr[i]);
    }
    return result;
}

// Рекурсивное перемножение
template<typename T, size_t N, typename... Tail>
constexpr auto product(const array<T, N> &arr, const Tail &... rest) {
    const auto rest_product = product(rest...);


    array<decltype(tuple_cat(make_tuple(arr[0]), rest_product[0])), N * tuple_size_v<decltype(rest_product)>>
            result; // Массив для ответа

    size_t idx = 0;
    for (const auto &elem: arr) {
        for (const auto &tuple: rest_product) {
            result[idx++] = tuple_cat(make_tuple(elem), tuple);
        }
    }

    return result;
};

// Вывод в os
template<typename... T>
void print(const tuple<T...> &t) {
    apply([](const auto &... args) {
        ((cout << args << ' '), ...);
        cout << '\n';
    }, t);
}

int main() {
    constexpr array<int, 2> arr1{{2, 4}};
    constexpr array<char, 3> arr2{{'a', 'b', 'c'}};
    constexpr array<double, 2> arr3{{1.1, 2.2}};

    auto result = product(arr1, arr2, arr3);

    for (const auto &tup: result) {
        print(tup);
    }
}
