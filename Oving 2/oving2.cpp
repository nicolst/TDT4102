//
// Created by Nicolai Stølen on 15/01/2018.
//
#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

// Oppgave 1a
void inputAndPrintInteger() {
    cout << "Skriv inn et tall: ";
    int nummer;
    cin >> nummer;
    cout << "Du skrev: " << nummer << endl;
}

// Oppgave 1b
int inputInteger() {
    cout << "Skriv inn et tall: ";
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
    if (hours != 0) cout << hours << " time" << ((hours == 1) ? "" : "r") << ((minutes == 0 && sec == 0) ? "." : ", ");
    if (minutes != 0) cout << minutes << " minutt" << ((minutes == 1) ? "" : "er") << ((sec == 0) ? "." : ", ");
    if (sec != 0) cout << sec << " sekund.";
    cout << endl;
}

// Oppgave 2a
// Oppgave 2b: while når man angir antall tall, kortere syntaks, slipper å skrive inn condition
//           : kan bruke for også, men det blir bare lengre, foretrekker while
//           : for å vente på 0 ville jeg bare brukt en while(true)-loop med en if for break ved 0-input
void inputIntegersUsngLoopAndPrintSum() {
    int m;
    cin >> m;
    int sum = 0;
    while (m--) {
        cout << "Skriv inn et tall: ";
        int n;
        cin >> n;
        sum += n;
    }
    cout << "Sum: " << sum << endl;
}



// Oppgave 2c
double inputDouble() {
    cout << "Skriv inn et (desimal)tall: ";
    double i;
    cin >> i;
    return i;
}

// Oppgave 2d
// Bør bruke inputDouble for vi har lyst å kunne oppi f.eks. øre, pengesummer med desimaler
void nokToEur() {
    double nok;
    while (true) {
        double temp;
        cout << "Antall NOK: ";
        cin >> temp;
        if (temp > 0) {
            nok = temp;
            break;
        }
    }
    cout << fixed << setprecision(2) << nok*9.64 << endl;
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

void demonstrerOving() {
    cout << "Oppgave 1a" << endl;
    inputAndPrintInteger();

    cout << "Oppgave 1b" << endl;
    int nummer = inputInteger();
    cout << "Du skrev: " << nummer << endl;

    cout << "Oppgave 1e" << endl;
    for (int i = 10; i < 15; i++) {
        cout << i << " er et " << (isOdd(i) ? "oddetall." : "partall.") << endl;
    }

    cout << "Oppgave 1f" << endl;
    cout << "3601 sekund: ";
    printHumanReadableTime(3601);
    cout << "3660 sekund: ";
    printHumanReadableTime(3660);
    cout << "67 sekund: ";
    printHumanReadableTime(67);
    cout << "3599 sekund: ";
    printHumanReadableTime(3599);
}


int main() {
    setlocale(LC_ALL, "Norwegian");

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
        cout << "7) Demonstrer at resten av øvingen fungerer...";
        cout << "Angi valg (0-7): ";
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
            case 7:
                demonstrerOving();
                break;
            default:
                cout << "Ugyldig valg." << endl;

        }
    }






}