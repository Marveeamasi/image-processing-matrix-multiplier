#include "matrix.h"
#include <immintrin.h> // For SSE instructions

void matrix_multiply_blocked(const double* A, const double* B, double* C, int M, int N, int K, int block_size) {
    for (int ii = 0; ii < M; ii += block_size) {
        for (int jj = 0; jj < N; jj += block_size) {
            for (int kk = 0; kk < K; kk += block_size) {
                for (int i = ii; i < std::min(ii + block_size, M); ++i) {
                    for (int j = jj; j < std::min(jj + block_size, N); ++j) {
                        double sum = 0.0;
                        for (int k = kk; k < std::min(kk + block_size, K); ++k) {
                            sum += A[i * K + k] * B[k * N + j];
                        }
                        C[i * N + j] += sum;
                    }
                }
            }
        }
    }
}

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

    int block_size = 64; 

    matrix_multiply_blocked(data_.data(), other.data_.data(), result.data_.data(),
                           rows_, other.cols_, cols_, block_size);

    return result;
}

double Matrix::operator()(int i, int j) const {
    return data_[i * cols_ + j];
}
