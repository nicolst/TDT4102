//
// Created by Nicolai Stølen on 01/03/2018.
//

/*
 * Forventer at dette skrives ut:
 *
 * 4
 * 4
 * 4
 *
 * 5
 * 5
 * 5
 *
 * Programmet krasjet ikke i slutten av dummyTest..
 *
 */





#include "dummy.h"
#include <iostream>
#include <algorithm>

using namespace std;

Dummy::Dummy() {
    num = new int(0);
}

Dummy::Dummy(const Dummy &d) {
    num = new int();
    *num = *d.num;
}

Dummy::~Dummy() {
    delete num;
}

Dummy& Dummy::operator=(Dummy rhs) {
    *num = *rhs.num;
    return *this;
}

void dummyTest() {
    Dummy a;
    *a.num = 4;
    Dummy b(a);
    Dummy c;
    c = a;
    cout << "a: " << *a.num << endl;
    cout << "b: " << *b.num << endl;
    cout << "c: " << *c.num << endl;

    *b.num = 3;
    *c.num = 5;

    cout << "a: " << *a.num << endl;
    cout << "b: " << *b.num << endl;
    cout << "c: " << *c.num << endl;

    cin.get();
}