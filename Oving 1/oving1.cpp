//
// Created by Nicolai Stølen on 08/01/2018.
//

#include <iostream>

// Oppgave a
int maks (int a, int b) {
    if (a > b) {
        std::cout << "A is greater than B." << std::endl;
        return a;
    } else {
        std::cout << "B is greater than or equal to A." << std::endl;
        return b;
    }
}

// Oppgave c
int fibonacci(int n) {
    int a = 0;
    int b = 1;
    std::cout << "Fibonacci numbers:" << std::endl;
    for (int i = 1; i <= n; i++) {
        std::cout << i << " " << b << std::endl;
        int temp = b;
        b += a;
        a = temp;
    }
    std::cout << "----" << std::endl;
    return b;
}

// Oppgave d
int squareNumberSum(int n) {
    int totalSum = 0;
    for (int i = 0; i < n; i++) {
        totalSum += i * i;
        std::cout << i * i << std::endl;
    }
    std::cout << totalSum << std::endl;
    return totalSum;
}

// Oppgave e
void triangleNumbersBelow(int n) {
    int acc = 1;
    int num = 2;
    std::cout << "Triangle numbers below " << n << ":" << std::endl;
    while (acc < n) {
        std::cout << acc << " ";
        acc += num;
        num++;
    }
    std::cout << std::endl;
}

bool isTriangleNumber(int number) {
    int acc = 1;
    while (number > 0) {
        number -= acc;
        acc++;
    }
    return number == 0;
}

// Oppgave f
bool isPrime(int n) {
    bool primeness = true;
    for (int j = 2; j < n; j++) {
        if ((n % j) == 0) {
            primeness = false;
            break;
        }
    }
    return primeness;
}

// Oppgave g
void naivePrimeNumberSearch(int n) {
    for (int i = 2; i < n; i++) {
        if (isPrime(i)) std::cout << i << " is a prime" << std::endl;
    }
}

// Oppgave h
int findGreatestDivisor(int n) {
    for (int i = n-1; i > 0; i--) {
        if (n % i == 0) return i;
    }
}

//Oppgave b, etc
int main() {
    setlocale(LC_ALL, "norwegian");

    std::cout << "Oppgave a)" << std::endl;
    std::cout << maks(5, 6) << std::endl;
    std::cout << std::endl;

    std::cout << "Oppgave c)" << std::endl;
    fibonacci(15);
    std::cout << std::endl;

    std::cout << "Oppgave d)" << std::endl;
    squareNumberSum(5);
    std::cout << std::endl;

    std::cout << "Oppgave e)" << std::endl;
    triangleNumbersBelow(20);
    std::cout << "15 is " << (isTriangleNumber(15) ? "" : "not ") << "a triangle number" << std::endl;
    std::cout << "17 is " << (isTriangleNumber(17) ? "" : "not ") << "a triangle number" << std::endl;
    std::cout << std::endl;

    std::cout << "Oppgave f)" << std::endl;
    std::cout << "7 is "  << (isPrime(7)  ? "prime" : "not prime") << std::endl;
    std::cout << "12 is " << (isPrime(12) ? "prime" : "not prime") << std::endl;
    std::cout << std::endl;

    std::cout << "Oppgave g)" << std::endl;
    naivePrimeNumberSearch(17);
    std::cout << std::endl;

    std::cout << "Oppgave h)" << std::endl;
    std::cout << "73 sin største divisor er " << findGreatestDivisor(73) << std::endl;
    std::cout << std::endl;

    return 0;
}