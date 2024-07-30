#include "matrix.h"
#include <immintrin.h> // For SSE instructions

Matrix::Matrix(int rows, int cols) {
    rows_ = rows;
    cols_ = cols;
    data_ = new double[rows * cols];
}

Matrix::~Matrix() {
    delete[] data_;
}

Matrix Matrix::operator*(const Matrix& other) const {
    if (cols_ != other.rows()) {
        exit(1);
    }

    Matrix result(rows_, other.cols_);

    for (int i = 0; i < rows_; ++i) {
        for (int j = 0; j < other.cols_; ++j) {
            double sum = 0.0;
            for (int k = 0; k < cols_; ++k) {
                sum += (*this)(i, k) * other(k, j);
            }
            result(i, j) = sum;
        }
    }

    return result;
}


double Matrix::operator()(int i, int j) const {
    return data_[i * cols_ + j];
}
