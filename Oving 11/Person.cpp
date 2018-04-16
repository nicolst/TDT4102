//
// Created by Nicolai Stølen on 16/04/2018.
//

#include "Person.h"

Person::Person(string firstName, string lastName): firstName(firstName), lastName(lastName) {}

string Person::getFirstName() const { return firstName; }
string Person::getLastName() const { return lastName; }
string Person::getFullName() const { return firstName + " " + lastName; }

ostream& operator<<(ostream& os, const Person& p) {
    cout << p.getFullName() << endl;
}

bool Person::operator<(const Person &p) const {
    return (getFullName() < p.getFullName());
}
