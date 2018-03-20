//
// Created by Nicolai Stølen on 20/03/2018.
//

#include <cmath>
#include <iostream>
#import "Vector.h"

Vector::Vector(): Matrix() {}

Vector::Vector(int nRows): Matrix(nRows, 1) {}

Vector::Vector(const Matrix &other): Matrix(other) {
    if (this->getColumns() != 1) this->invalidate();
}

double Vector::get(int row) const {
    return Matrix::get(row, 0);
}

void Vector::set(int row, double value) {
    return Matrix::set(row, 0, value);
}

double Vector::dot(const Vector &rhs) const {
    if (!this->isValid() || !rhs.isValid() || this->getRows() != rhs.getRows()) return nan("");
    double dot = 0.0;
    for (int i = 0; i < this->getRows(); i++) {
        dot += this->get(i) * rhs.get(i);
    }
    return dot;
}

double Vector::lengthSquared() const {
    return dot(*this);
}

double Vector::length() const {
    return sqrt(lengthSquared());
}
