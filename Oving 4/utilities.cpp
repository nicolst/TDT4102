//
// Created by Nicolai Stølen on 22/01/2018.
//

#include <cstdlib>
#include <iostream>
#include "utilities.h"

using namespace std;

int incrementByValueNumTimes(int startValue, int increment, int numTimes) {
    for (int i = 0; i < numTimes; i++) {
        startValue += increment;
    }
    return startValue;
}

void incrementByValueNumTimes2(int *startValue, int increment, int numTimes) {
    for (int i = 0; i < numTimes; i++) {
        *startValue += increment;
    }
}

void swapNumbers(int *num1, int *num2) {
    int temp = *num1;
    *num1 = *num2;
    *num2 = temp;
}

void printArray(int *arr, int length) {
    for (int i = 0; i < length; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void randomizeArray(int *arr, int length) {
    for (int i = 0; i < length; i++) {
        arr[i] = randomWithLimits(0, 101);
    }
}

int randomWithLimits(int low, int high) {
    int max = high - low;
    int random = (rand() % max) + low;
    return random;
}

void sortArray(int *arr, int length) {
    bool sorted;
    do {
        sorted = true;
        for (int i = 0; i < length-1; i++) {
            if (arr[i] > arr[i+1]) {
                swapNumbers(&arr[i], &arr[i+1]);
                if (sorted) sorted = false;
            }
        }
    } while (!sorted);
}

double medianOfArray(int *arr, int length) {
    int first = (length / 2) - 1;
    int second = first + (length % 2 == 0 ? 1 : 0);
    return (arr[first] + arr[second]) / 2.0;
}

void randomizeCString(char *arr, int length, char lower, char upper) {
    for (int i = 0; i < length; i++) {
        arr[i] = (char) randomWithLimits(lower, upper);
    }
}

void readInputToCString(char *arr, int length, char lower, char upper) {
    lower = (char) toupper(lower);
    upper = (char) toupper(upper);
    int i = 0;
    while (i < length) {
        string s;
        cout << "Skriv bokstaver (" << lower << "-" << upper << ") (trenger " << (length - i) << " bokstaver til): ";
        cin >> s;
        for (char c : s) {
            c = (char) toupper(c);
            if ((c < lower) || (c > upper)) {
                cout << "Ugyldig bokstav." << endl;
                continue;
            }
            arr[i] = c;
            i++;
            if (i >= length) break;
        }
    }
}

int countOccurencesOfCharacters(char *arr, int length, char c) {
    int count = 0;
    c = (char) toupper(c);
    for (int i = 0; i < length; i++) {
        if ((char) toupper(arr[i]) == c) count++;
    }
    return count;
}