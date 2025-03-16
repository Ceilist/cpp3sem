#include "matrix.hpp"
#include <cassert>

using namespace std;


int main() {
    // Создаем матрицу 2x2, заполненную единицами
    Matrix<int> mat(2, 2, 1);

    // Проверяем, что все элементы равны 1
    assert(mat(0, 0) == 1);
    assert(mat(0, 1) == 1);
    assert(mat(1, 0) == 1);
    assert(mat(1, 1) == 1);


    cout << "Test 1 passed.\n";
}