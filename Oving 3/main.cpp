//
// Created by Nicolai Stølen on 16/01/2018.
//

#include "cannonball.h"
#include "utilities.h"
#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    srand(time(nullptr));

    cout << "Avvik for funksjoner vs forventet verdi: " << endl;
    double times[3] = {0.0, 2.5, 5.0};

    double initVelX = 50.0, initVelY = 25.0;

    double initPosX = 0.0, initPosY = 0.0;

    double avvikAcclX[3] = {0.0, 0.0, 0.0};
    double avvikAcclY[3] = {-9.81, -9.81, -9.81};

    double avvikVelX[3] = {50.0, 50.0, 50.0};
    double avvikVelY[3] = {25.0, 0.475, -24.05};

    double avvikPosX[3] = {0.0, 125.0, 250.0};
    double avvikPosY[3] = {0, 31.84, 2.375};

    for (int i = 0; i < 3; i++) {
        avvikAcclX[i] = avvikAcclX[i] - 0.0;
        avvikAcclY[i] = avvikAcclY[i] - acclY();

        avvikVelX[i] = avvikVelX[i] - initVelX;
        avvikVelY[i] = avvikVelY[i] - velY(initVelY, times[i]);

        avvikPosX[i] = avvikPosX[i] - posX(initPosX, initVelX, times[i]);
        avvikPosY[i] = avvikPosY[i] - posY(initPosY, initVelY, times[i]);
    }
    cout << fixed << setprecision(4);
    cout << "\t\tT=0.0\t\tT=2.5\t\tT=5.0" << endl;
    cout << "acclX\t" << avvikAcclX[0] << "\t\t" << avvikAcclX[1] << "\t\t\t" << avvikAcclX[2] << endl;
    cout << "acclY\t" << avvikAcclY[0] << "\t\t" << avvikAcclY[1] << "\t\t\t" << avvikAcclY[2] << endl;

    cout << "velX\t" << avvikVelX[0] << "\t\t" << avvikVelX[1] << "\t\t\t" << avvikVelX[2] << endl;
    cout << "velY\t" << avvikVelY[0] << "\t\t" << avvikVelY[1] << "\t\t\t" << avvikVelY[2] << endl;

    cout << "posX\t" << avvikPosX[0] << "\t\t" << avvikPosX[1] << "\t\t\t" << avvikPosX[2] << endl;
    cout << "posY\t" << avvikPosY[0] << "\t\t" << avvikPosY[1] << "\t\t\t" << avvikPosY[2] << endl;


    cout << endl << "Tester printTime:" << endl;
    cout << "3601.0s: ";
    printTime(3601.0);
    cout << "4324.0s: ";
    printTime(4324.0);
    cout << "68.34s: ";
    printTime(68.34);

    cout << endl << "Tester randomWithLimits:" << endl;
    for (int i = 0; i < 5; i++)
        cout << randomWithLimits(100, 199) << endl;

    cout << "Tester getUserInput, (getVelocityX, getVelocityY) (getVelocityVector), flightTime og targetPractice (100m):" << endl;
    double theta, vel;
    getUserInput(&theta, &vel);
    double velX, velY;
    getVelocityVector(theta, vel, &velX, &velY);
    cout << "theta: " << theta << " | velocity: " << vel << endl;
    cout << "velX: " << velX << " | velY: " << velY << endl;
    double ft = flightTime(velY);
    cout << "flightTime: " << ft << endl;
    cout << "targetPractice: " << targetPractice(100.0, velX, velY)<< endl;

    cout << "Tester så playTargetPractice: " << endl;
    playTargetPractice();


    return 0;
}