//
// Created by Nicolai Stølen on 16/04/2018.
//

#ifndef TDT4102_PERSON_H
#define TDT4102_PERSON_H

#include <string>
#include <iostream>

using namespace std;

class Person {
    string firstName;
    string lastName;

public:
    Person(string fornavn, string etternavn);

    string getFirstName() const;
    string getLastName() const;
    string getFullName() const;

    friend ostream& operator<<(ostream& os, const Person& p);
    bool operator <(const Person& p) const;
};



#endif //TDT4102_PERSON_H
