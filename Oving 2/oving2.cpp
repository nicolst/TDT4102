//
// Created by Nicolai Stølen on 15/01/2018.
//
#include <iostream>

using namespace std;

// Funkjsoner IO, oppgave a
void inputAndPrintInteger() {
    int nummer;
    cin >> nummer;
    cout << nummer << endl;
}

// Funksjoner IO, oppgave b
int inputInteger() {
    int nummer;
    cin >> nummer;
    return nummer;
}

// Funksjoner IO, oppgave c,d
// Bruker inputInteger, fordi vi vil bare printe summen, trenger verdien som blir skrevet inn...
void inputIntegersAndPrintSum() {
    cout << "Skriv inn et tall: ";
    int n1 = inputInteger();
    cout << "Skriv inn et tall: ";
    int n2 = inputInteger();
    cout << "Summen av tallene: "  << n1 + n2 << endl;
}

// Funksjoner IO, oppgave e
bool isOdd(int nummer) {
    return (nummer % 2) == 1;
}

// Funksjoner IO, oppgave f
void printHumanReadableTime(int seconds) {
    int hours = seconds / 3600;
    int minutes = (seconds % 3600) / 60;
    int sec = seconds % 60;
    if (hours != 0) cout << hours << " time" << ((hours == 1) ? ", " : "r, ");
    if (minutes != 0) cout << minutes << " minutt" << ((minutes == 1) ? ", " : "er, ");
    cout << sec << " sekund" << ((sec == 1) ? "." : "er.") << endl;
}

// Løkker, oppgave a
// Løkker, oppgave b: while når man angir antall tall, slipper å lage "hjelpevariablen" i
void inputIntegersUsngLoopAndPrintSum() {
    int m;
    cin >> m;
    int sum = 0;
    while (m--) {
        int n;
        cin >> n;
        sum += n;
    }
    cout << sum;
}

// Løkker, oppgave c
double inputDouble() {
    double i;
    cin >> i;
    return i;
}

// skriv om med setprecison,fixed
double nokToEur(double nok) {
    return nok*9.64;
}


int main() {
    setlocale(LC_ALL, "Norwegian");

    inputAndPrintInteger();

    int nummer = inputInteger();
    cout << "Du skrev: " << nummer << endl;

    inputIntegersAndPrintSum();

    for (int i = 10; i < 15; i++) {
        cout << i << " er et " << (isOdd(i) ? "oddetall." : "partall.") << endl;
    }

    printHumanReadableTime(3601);
    printHumanReadableTime(67);
    printHumanReadableTime(3599);

    inputIntegersUsngLoopAndPrintSum();

    int nok;
    while (true) {
        int temp;
        cout << "Antall NOK: ";
        cin >> temp;
        if (temp > 0) {
            nok = temp;
            break;
        }
    }
    cout << nokToEur(nok);





}