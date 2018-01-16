//
// Created by Nicolai Stølen on 15/01/2018.
//
#include <iostream>
#include <cmath>

using namespace std;

// Oppgave 1a
void inputAndPrintInteger() {
    int nummer;
    cin >> nummer;
    cout << nummer << endl;
}

// Oppgave 1b
int inputInteger() {
    int nummer;
    cin >> nummer;
    return nummer;
}

// Oppgave 1c,d
// Bruker inputInteger, fordi vi vil bare printe summen, trenger verdien som blir skrevet inn...
void inputIntegersAndPrintSum() {
    cout << "Skriv inn et tall: ";
    int n1 = inputInteger();
    cout << "Skriv inn et tall: ";
    int n2 = inputInteger();
    cout << "Summen av tallene: "  << n1 + n2 << endl;
}

// Oppgave 1e
bool isOdd(int nummer) {
    return (nummer % 2) == 1;
}

// Oppgave 1f
void printHumanReadableTime(int seconds) {
    int hours = seconds / 3600;
    int minutes = (seconds % 3600) / 60;
    int sec = seconds % 60;
    if (hours != 0) cout << hours << " time" << ((hours == 1) ? ", " : "r, ");
    if (minutes != 0) cout << minutes << " minutt" << ((minutes == 1) ? ", " : "er, ");
    cout << sec << " sekund" << ((sec == 1) ? "." : "er.") << endl;
}

// Oppgave 2a
// Oppgave 2b: while når man angir antall tall, slipper å lage "hjelpevariablen" i
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



// Oppgave 2c
double inputDouble() {
    double i;
    cin >> i;
    return i;
}

// skriv om med setprecison,fixed
double nokToEur() {
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
    return nok*9.64;
}

// Oppgave 3b
void printGangeTabell() {
    int hoyde, bredde;
    cout << "Angi høyde: ";
    cin >> hoyde;
    cout << "Angi bredde: ";
    cin >> bredde;

    for (int i = 1; i <= hoyde; i++) {
        for (int j = 1; j <= bredde; j++) {
            cout << j*i << "\t";
        }
        cout << endl;
    }

}

// Oppgave 4a
double discriminant(double a, double b, double c) {
    return pow(b, 2) - 4*a*c;
}

// Oppgave 4b
void printRealRoots(double a, double b, double c) {
    double disc = discriminant(a, b,c );
    int sqt = sqrt(disc);
    if (disc < 0) {
        cout << "Ingen løsninger." << endl;
    } else if (disc == 0) {
        cout << "Løsning: " << -b/(2*a) << endl;
    } else {
        cout << "Løsning 1: " << (-b+disc)/(2*a) << endl;
        cout << "Løsning 1: " << (-b-disc)/(2*a) << endl;
    }
}

// Oppgave 4c
void solveQuadraticEquation() {
    cout << "a: ";
    double a;
    cin >> a;

    cout << "b: ";
    double b;
    cin >> b;

    cout << "c: ";
    double c;
    cin >> c;

    printRealRoots(a, b, c);
}

// Oppgave 5a,b
void calculateLoanPayments() {
    double loan;
    cout << "Lånebeløp: ";
    cin >> loan;

    double rate;
    cout << "Rente: ";
    cin >> rate;

    double totalLoan = loan;
    double remainingLoan = loan;
    double avdrag = totalLoan / 10;
    rate = rate/100;

    cout << "År\t\tInnbetaling\t\tGjenstående lån" << endl;
    for (int i = 1; i < 11; i++) {
        double payment = avdrag + rate * remainingLoan;
        remainingLoan -= avdrag;
        cout << i << "\t\t" << payment << "\t\t\t" << remainingLoan << endl;
    }
}


int main() {
    setlocale(LC_ALL, "Norwegian");

//    inputAndPrintInteger();
//
//    int nummer = inputInteger();
//    cout << "Du skrev: " << nummer << endl;
//
//    inputIntegersAndPrintSum();
//
//    for (int i = 10; i < 15; i++) {
//        cout << i << " er et " << (isOdd(i) ? "oddetall." : "partall.") << endl;
//    }
//
//    printHumanReadableTime(3601);
//    printHumanReadableTime(67);
//    printHumanReadableTime(3599);
//
//    inputIntegersUsngLoopAndPrintSum();
//
//    int nok;
//    while (true) {
//        int temp;
//        cout << "Antall NOK: ";
//        cin >> temp;
//        if (temp > 0) {
//            nok = temp;
//            break;
//        }
//    }
//    cout << nokToEur(nok);

    // Oppgave 3a, 4d,e
    while (true) {
        cout << "Velg funksjon:" << endl;
        cout << "0) Avslutt" << endl;
        cout << "1) Summer to tall" << endl;
        cout << "2) Summer flere tall" << endl;
        cout << "3) Konverter NOK til EURO" << endl;
        cout << "4) Print gangetabell" << endl;
        cout << "5) Finn reelle røtter til et andregradsuttrykk" << endl;
        cout << "6) Kalkuler lån" << endl;
        cout << "Angi valg (0-6): ";
        int choice;
        cin >> choice;

        switch (choice) {
            case 0:
                return 0;
            case 1:
                inputIntegersAndPrintSum();
                break;
            case 2:
                inputIntegersUsngLoopAndPrintSum();
                break;
            case 3:
                nokToEur();
                break;
            case 4:
                printGangeTabell();
                break;
            case 5:
                solveQuadraticEquation();
                break;
            case 6:
                calculateLoanPayments();
                break;
            default:
                cout << "Ugyldig valg." << endl;

        }
    }






}