//
// Created by Nicolai Stølen on 22/01/2018.
//

// Oppgave 1a) 5, verdien endres ikke

#include <iostream>
#include <ctime>
#include "tests.h"
#include "mastermind.h"

using namespace std;

int main() {
    srand(time(nullptr));

    while (true) {
        int choice;
        cout << "1) testCallByValue() \n"
             << "2) testCallByPointer()\n"
             << "3) testSwapNumbers()\n"
             << "4) testTablesSorting()\n"
             << "5) testCStrings(randomize=true)\n"
             << "6) testCStrings(randomize=false)\n"
             << "7) playMasterMind\n"
             << "0) Exit\n";
        cin >> choice;
        switch (choice) {
            case 0:
                return 0;
            case 1:
                testCallByValue();
                break;
            case 2:
                testCallByPointer();
                break;
            case 3:
                testSwapNumbers();
                break;
            case 4:
                testTablesSorting();
                break;
            case 5:
                testCStrings(true);
                break;
            case 6:
                testCStrings(false);
                break;
            case 7:
                playMastermind();
                break;
            default:
                cout << "Ugyldig valg\n";
                break;
        }
    }
}