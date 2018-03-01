//
// Created by Nicolai Stølen on 01/03/2018.
//

#include <ostream>

#ifndef TDT4102_MATRIX_H
#define TDT4102_MATRIX_H

#endif //TDT4102_MATRIX_H

class Matrix {
    double **matrix;
    int rows;
    int cols;

public:
    Matrix();
    Matrix(int nRows, int nColumns);
    Matrix(const Matrix& rhs);
    explicit Matrix(int nRows);
    ~Matrix();

    Matrix& operator=(const Matrix& rhs);
    Matrix& operator+=(const Matrix& rhs);
    Matrix& operator+(const Matrix& rhs);

    double get(int row, int col) const;
    void set(int row, int col, double value);
    int getHeight() const;
    int getWidth() const;

    bool isValid();

    friend std::ostream& operator<<(std::ostream& os, Matrix* m);

};