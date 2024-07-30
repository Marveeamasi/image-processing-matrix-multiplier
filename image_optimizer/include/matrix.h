#ifndef MATRIX_H
#define MATRIX_H

#include <cstdint>

class Matrix {
public:
    Matrix(int rows, int cols);
    ~Matrix();

    double* data() const { return data_; }
    int rows() const { return rows_; }
    int cols() const { return cols_; }

private:
    double* data_;
    int rows_, cols_;
};

#endif
