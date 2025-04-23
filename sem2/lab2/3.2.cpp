#include <array>
#include <cassert>

using namespace std;


template<size_t N, typename T>
constexpr T solution(size_t k, const array<T, N> &coef, const array<T, N> &first) {
    // Ответ из начальных данных
    if (k < N) {
        return first[k];
    }
    // Рекуррентно вычисляем k-тый
    T result = 0;
    for (size_t i = 0; i < N; ++i) {
        result += coef[i] * solution<N, T>(k - N + i, coef, first);
    }
    return result;
}

int main() {
    // Фибо
    constexpr array<int, 2> fib1 = {1, 1};
    constexpr array<int, 2> fib2 = {0, 1}; // Считаем, что первое число 0

    static_assert(solution<2, int>(19, fib1, fib2) == 4181); // static assert тоже проверяет на этапе компиляции

    // Рандомный рекуррент
    constexpr array<int, 3> rand1 = {3, 2, 5};
    constexpr array<int, 3> rand2 = {8, 15, 17};
    static_assert(solution<3, int>(8, rand1, rand2) == 686117);
    // Если попробовать взять 19 элемент в этом рекурренте, то будет ошибка "overflow in constant expression"
}
