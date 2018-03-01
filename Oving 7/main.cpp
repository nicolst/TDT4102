//
// Created by Nicolai Stølen on 01/03/2018.
//

#include <iostream>
#include "fibonacci.h"
#include "matrix.h"
#include "dummy.h"


int main() {
    dummyTest();

    createFibonacci();

    Matrix m1 = Matrix();
    Matrix m2(5, 6);
    Matrix m3(3);

    std::cout << "M1, valid? " << m1.isValid() << std::endl;

    std::cout << "M2, valid? " << m2.isValid()
              << ", (1,3) = " << m2.get(0, 0)
              << ", height = " << m2.getHeight()
              << "m width = " << m2.getWidth() << std::endl;

    std::cout << "M2, valid? " << m3.isValid()
              << ", (2,2) = " << m3.get(2, 2)
              << ", height = " << m3.getHeight()
              << "m width = " << m3.getWidth() << std::endl;

    std::cout << &m2 << std::endl;
    std::cout << &m3;

}
