
#include "matrix.hpp"

// Явная специализация (чтобы разделить заголовочный и реализацию)
template<>
Matrix<int>::Matrix(unsigned rows, unsigned cols, int value)
    : data(rows * cols, value), rows_(rows), cols_(cols) {}