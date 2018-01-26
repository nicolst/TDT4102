//
// Created by Nicolai Stølen on 22/01/2018.
//

#ifndef TDT4102_UTILITIES_H
#define TDT4102_UTILITIES_H

#endif //TDT4102_UTILITIES_H

int incrementByValueNumTimes(int startValue, int increment, int numTimes);
void incrementByValueNumTimes2(int *startValue, int increment, int numTimes);

void swapNumbers(int *num1, int *num2);

void printArray(int *arr, int length);

void randomizeArray(int *arr, int length);

int randomWithLimits(int low, int high);

void sortArray(int* arr, int length);

double medianOfArray(int *arr, int length);

void randomizeCString(char *arr, int length, char lower, char upper);

void readInputToCString(char *arr, int length, char lower, char upper);

int countOccurencesOfCharacters(char *arr, int length, char c);
