#include "matrix.hpp"
#include <cassert>

using namespace std;


int main() {
    Matrix<int> mat(2, 2);
    mat(0, 0) = 1; mat(0, 1) = 2;
    mat(1, 0) = 3; mat(1, 1) = 4;
// Проверка определителя
    int det = mat.determinant();
    assert(det == (1 * 4 - 2 * 3));
    cout << "Test 2 passed!\n";
}