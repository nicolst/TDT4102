//
// Created by Nicolai Stølen on 16/02/2018.
//

#ifndef TDT4102_PERSON_H
#define TDT4102_PERSON_H

#endif //TDT4102_PERSON_H

#include <string>
#include "Car.h"

class Person {
    std::string name, email;
    Car *car;

public:
    Person(std::string name, std::string email, Car *car = nullptr);
    std::string getName() const;
    std::string getEmail() const;
    void setEmail(std::string newEmail);
    bool hasAvailableSeats() const;
    friend std::ostream& operator<<(std::ostream& os, const Person& p);
    friend bool operator<(const Person& lhs, const Person& rhs);
    friend bool operator==(const Person& lhs, const Person& rhs);
};