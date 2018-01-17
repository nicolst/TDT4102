//
// Created by Nicolai Stølen on 16/01/2018.
//

#include <cmath>
#include <iostream>
#include "cannonball.h"
#include <math.h>

using namespace std;

const double G_ACC = -9.81;

double acclY() {
    return G_ACC;
}

double velY(double initVelocityY, double time) {
    return initVelocityY + acclY() * time;
}

double posX(double initPosition, double initVelocity, double time) {
    return initPosition + initVelocity * time;
}
double posY(double initPosition, double initVelocity, double time) {
    return initPosition + initVelocity * time + 0.5 * acclY() * pow(time, 2);
}

void printTime(double time) {
    printHumanReadableTime(time);
}

double flightTime(double initVelocityY) {
    return -2 * initVelocityY / acclY();
}

void getUserInput(double *theta, double *absVelocity) {
    cout << "Vinkel i grader: ";
    cin >> *theta;

    cout << "Fart: ";
    cin >> *absVelocity;
}

double degToRad(double deg) {
    return deg * M_PI / 180;
}

double getVelocityX(double theta, double absVelocity) {
    return absVelocity * cos(degToRad(theta));
}


double getVelocityY(double theta, double absVelocity) {
    return absVelocity * sin(degToRad(theta));
}

void getVelocityVector(double theta, double absVelocity, double *velocityX, double *velocityY) {
    *velocityX = getVelocityX(theta, absVelocity);
    *velocityY = getVelocityY(theta, absVelocity);
}

double getDistanceTraveled(double velocityX, double velocityY) {
    double time = flightTime(velocityY);
    return velocityX * time;
}

double targetPractice(double distanceToTarget, double velocityX, double velocityY) {
    double distanceTraveled = getDistanceTraveled(velocityX, velocityY);
    return distanceToTarget - distanceTraveled;
}

void printHumanReadableTime(double seconds) {
    int secondsi = static_cast<int>(floor(seconds));
    int hours = secondsi / 3600;
    int minutes = (secondsi % 3600) / 60;
    double sec = secondsi % 60 + (seconds - secondsi);
    if (hours != 0) cout << hours << " time" << ((hours == 1) ? ", " : "r, ");
    if (minutes != 0) cout << minutes << " minutt" << ((minutes == 1) ? ", " : "er, ");
    cout << sec << " sekund." << endl;
}