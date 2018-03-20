//
// Created by Nicolai Stølen on 20/03/2018.
//

#include "Matrix.h"

#ifndef TDT4102_VECTOR_H
#define TDT4102_VECTOR_H

#endif //TDT4102_VECTOR_H


class Vector: public Matrix {

public:
    Vector();
    explicit Vector(int nRows);
    Vector(const Matrix &other);

    void set(int row, double value);
    double get(int row) const;

    double dot(const Vector &rhs) const;

    double lengthSquared() const;
    double length() const;

};