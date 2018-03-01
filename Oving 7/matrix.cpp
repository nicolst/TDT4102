//
// Created by Nicolai Stølen on 01/03/2018.
//

#include <iostream>
#include "matrix.h"

Matrix::Matrix() {
    matrix = nullptr;
    rows = 0;
    cols = 0;
}

Matrix::Matrix(int nRows, int nColumns): rows(nRows), cols(nColumns) {
    matrix = new double*[nRows];
    for (int i = 0; i < nColumns; i++) {
        matrix[i] = new double[nColumns]();
    }
}

Matrix::Matrix(int nRows): Matrix(nRows, nRows) {
    for (int i = 0; i < nRows; i++) {
        matrix[i][i] = 1;
    }
}

Matrix::~Matrix() {
    for (int i = 0; i < rows; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;
}

double Matrix::get(int row, int col) const {
    return matrix[row][col];
}

void Matrix::set(int row, int col, double value) {
    matrix[row][col] = value;
}

int Matrix::getHeight() const {
    return rows;
}

int Matrix::getWidth() const {
    return cols;
}

bool Matrix::isValid() {
    return matrix != nullptr;
}

std::ostream& operator<<(std::ostream &os, Matrix* m) {
    for (int i = 0; i < m->getHeight(); i++) {
        for (int j = 0; j < m->getWidth(); j++) {
            std::cout << m->get(i, j) << "\t";
        }
        std::cout << std::endl;
    }
    return os;
}
