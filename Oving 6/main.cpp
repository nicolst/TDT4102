//
// Created by Nicolai Stølen on 16/02/2018.
//


#include <SFML/graphics.hpp>
#include <iostream>
#include "Person.h"

using namespace std;

void partOne();

int mnain() {

    cout << "Del 1 eller 2? ";

    int choice;
    cin >> choice;

    switch(choice) {
        case 1:
            partOne();
            break;
        case 2:
            //gameMain();
            break;
    }

    return 0;
}

void partOne() {
    Person p1("P1", "p1@P1.com");

    Car c2(5);
    Person p2("P2", "p2@P2.com", &c2);

    Car c3(7);
    Person p3("P3", "p3@P3.com", &c3);

    Person p4("P4", "p4@P4.com");

    Car c5(2);
    Person p5("P5", "p5@P5.com", &c5);

    Car c6(4);
    Person p6("P3", "p6@P6.com", &c6);

    cout << "Er p1 og p3 samme person? " << (p1 == p3 ? "Ja" : "Nei") << endl;
    cout << "Er p3 og p6 samme person? " << (p3 == p6 ? "Ja" : "Nei") << endl;
    cout << "Har p1 ledige seter? " << (p1.hasAvailableSeats() ? "Ja" : "Nei") << endl;
    cout << "Har p5 ledige seter? " << (p5.hasAvailableSeats() ? "Ja" : "Nei") << endl;
    cout << endl;

    cout << "Tester print-funksjoner..." << endl;
    cout << p1;
    cout << p2;
    cout << p3;
    cout << p4;
    cout << p5;
    cout << p6;
}
