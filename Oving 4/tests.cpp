//
// Created by Nicolai Stølen on 22/01/2018.
//

#include <iostream>
#include <iomanip>
#include "utilities.h"

using namespace std;

void testCallByValue() {
    int v0 = 5;
    cout << "initial v0: " << v0 << endl;
    int increment = 2;
    int iterations = 10;
    int result = incrementByValueNumTimes(v0, increment, iterations);
    cout << "v0: " << v0 << endl
              << " increment: " << increment << endl
              << " iterations: " << iterations << endl
              << " result: " << result << endl;
}

void testCallByPointer() {
    int v0 = 5;
    cout << "initial v0: " << v0 << endl;
    int increment = 2;
    int iterations = 10;
    incrementByValueNumTimes2(&v0, increment, iterations);
    cout << "v0: " << v0 << endl
              << " increment: " << increment << endl
              << " iterations: " << iterations << endl;
}

void testSwapNumbers() {
    cout << "num1: ";
    int num1;
    cin >> num1;
    cout << "num2: ";
    int num2;
    cin >> num2;
    swapNumbers(&num1, &num2);
    cout << "num1: " << num1 << " | num2: " << num2 << endl;
}

void testTablesSorting() {
    int percentages[20];
    randomizeArray(percentages, 20);
    cout << "Opprinnelig array:" << endl;
    printArray(percentages, 20);
    swapNumbers(&percentages[0], &percentages[1]);
    cout << "To første verdier byttet om:" << endl;
    printArray(percentages, 20);
    double median = medianOfArray(percentages, 20);
    cout << "Median før: " << median << endl;
    sortArray(percentages, 20);
    cout << "Sortert array:" << endl;
    printArray(percentages, 20);
    median = medianOfArray(percentages, 20);
    cout << "Median etter: " << median << endl;
}

void testCStrings(bool randomize) {
    char grades[41];
    grades[40] = '\0';
    if (randomize) {
        randomizeCString(grades, 40, 'A', 'F');
    } else {
        readInputToCString(grades, 40, 'A', 'F');
    }
    cout << grades << endl;

    int gradeCount[6];
    for (int i = 0; i < 6; i++) {
        gradeCount[i] = countOccurencesOfCharacters(grades, 6, (char) ('A' + i));
    }

    int totalCount = 0;
    int sum = 0;
    for (int i = 0; i < 6; i++) {
        totalCount += gradeCount[i];
        sum += gradeCount[i] * (i + 1);
    }
    double average = ((double) sum) / totalCount;
    cout << fixed << setprecision(1);
    cout << "Snittkarakter: " << average << endl;

}