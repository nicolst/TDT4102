//
// Created by Nicolai Stølen on 16/01/2018.
//

#include "cannonball.h"
#include <iostream>

using namespace std;

int main() {
    double result = posX(0.0, 50.0, 5.0);
    double expected = 250.0;
    cout << result << " " << expected << endl;

    return 0;
}