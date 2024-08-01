#include <chrono>
#include "matrix_operations.h"

void benchmark(int size) {
    Matrix A(size, size), B(size, size), C(size, size);

    auto start = std::chrono::high_resolution_clock::now();
    C = A * B;
    auto end = std::chrono::high_resolution_clock::now();
}

