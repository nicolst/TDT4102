//
// Created by Nicolai Stølen on 16/02/2018.
//

#ifndef TDT4102_CAR_H
#define TDT4102_CAR_H

#endif //TDT4102_CAR_H

class Car {
    int freeSeats;

public:
    Car(int freeSeats);
    bool hasFreeSeats() const;
    void reserveFreeSeat();
};