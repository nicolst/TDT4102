//
// Created by Nicolai Stølen on 01/03/2018.
//

#include "fibonacci.h"
#include <iostream>

void fillInFibonacciNumbers(int result[], int length) {
    result[0] = 0;
    result[1] = 1;
     for (int i = 2; i < length; i++) {
        result[i] = result[i - 1] + result[i - 2];
    }
}

void printArray(int arr[], int length) {
    for (int i = 0; i < length; i++) std::cout << arr[i] << " ";
    std::cout << std::endl;
}

void createFibonacci() {
    std::cout << "Hvor mange tall skal genereres? ";
    int amount;
    std::cin >> amount;

    auto *fib = new int[amount];
    fillInFibonacciNumbers(fib, amount);

    printArray(fib, amount);

    delete fib;
}