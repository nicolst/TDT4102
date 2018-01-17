//
// Created by Nicolai Stølen on 16/01/2018.
//

#ifndef TDT4102_CANNONBALL_H
#define TDT4102_CANNONBALL_H

double acclY();

double velY(double initVelocityY, double time);

double posX(double initPosition, double initVelocity, double time);
double posY(double initPosition, double initVelocity, double time);

void printTime(double time);

double flightTime(double initVelocityY);

void printHumanReadableTime(double time);

void getUserInput(double *theta, double *absVelocity);

double degToRad(double deg);

double getVelocityX(double theta, double absVelocity);
double getVelocityY(double theta, double absVelocity);

void getVelocityVector(double theta, double absVelocity, double *velocityX, double *velocityY);

double getDistanceTraveled(double velocityX, double velocityY);

double targetPractice(double distanceToTarget, double velocityX, double velocityY);


#endif //TDT4102_CANNONBALL_H
