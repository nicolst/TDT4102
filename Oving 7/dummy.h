//
// Created by Nicolai Stølen on 01/03/2018.
//

#ifndef TDT4102_DUMMY_H
#define TDT4102_DUMMY_H

#endif //TDT4102_DUMMY_H

void dummyTest();

class Dummy {
public:
    int *num;
    Dummy();
    Dummy(const Dummy &d);

    ~Dummy();

    Dummy& operator=(Dummy rhs);

};