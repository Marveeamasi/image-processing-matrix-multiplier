#include <iostream>
#include "matrix_operations.h"

int main() {
    Matrix A(1024, 1024), B(1024, 1024), C(1024, 1024);
    // ... initialize matrices ...
    matrix_multiply(A, B, C);
    // ... print or use the result ...
    return 0;
}
