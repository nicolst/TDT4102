//
// Created by Nicolai Stølen on 17/01/2018.
//

#include <cstdlib>

using namespace std;

int randomWithLimits(int low, int high) {
    int max = high - low;
    int random = (rand() % max) + low;
    return random;
}