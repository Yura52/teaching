#include <iostream>
#include <cstdint>

using i32 = int32_t;


class Matrix {
public:
    Matrix() {
        std::cout << "Matrix()\n";
    }

    ~Matrix() {
        std::cout << "~Matrix()\n";
    }

    Matrix(const Matrix& other) {
        std::cout << "Matrix(const Matrix&)\n";
    }

    Matrix(Matrix&& other) {
        std::cout << "Matrix(Matrix&&)\n";
    }

    Matrix& operator=(const Matrix& other) {
        std::cout << "Matrix& operator=(const Matrix&)\n";
        return *this;
    }

    // TRY TO COMMENT / UNCOMMENT this operator AND SEE WHAT CHANGES
    Matrix& operator=(Matrix&& other) {
        std::cout << "Matrix& operator=(Matrix&& other)\n";
        return *this;
    }
};

Matrix MakeMatrix() {
    return Matrix();
}

int main() {
    Matrix a;
    a = MakeMatrix();

    return 0;
}
