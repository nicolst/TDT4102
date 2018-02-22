//
// Created by Nicolai Stølen on 16/02/2018.
//


#include "Person.h"
#include <iostream>

Person::Person(std::string name, std::string email, Car *car): name(name), email(email), car(car) {}

std::string Person::getName() const {
    return name;
}

std::string Person::getEmail() const {
    return email;
}

void Person::setEmail(std::string newEmail) {
    email = newEmail;
}

bool Person::hasAvailableSeats() const {
    if (car == nullptr) return false;
    return car->hasFreeSeats();
}

std::ostream& operator<<(std::ostream& os, const Person& p) {
    os << "Name: " << p.getName() << std::endl
       << "Email: " << p.getEmail() << std::endl     
       << "Has available seats? " << (p.hasAvailableSeats() ? "Yes" : "No") << std::endl;
    return os;
}

bool operator<(const Person& lhs, const Person& rhs) {
    return lhs.getName() < rhs.getName();
}

bool operator==(const Person& lhs, const Person& rhs) {
    return lhs.getName() == rhs.getName();
}
