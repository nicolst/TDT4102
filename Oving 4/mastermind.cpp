//
// Created by Nicolai Stølen on 26/01/2018.
//

#include <cctype>
#include <iostream>
#include "utilities.h"
#include "mastermind.h"

using namespace std;

const int SIZE = 4;
const int LETTERS = 6;

void playMastermind(int maxGuesses) {
    char code[SIZE + 1];
    char guess[SIZE + 1];
    code[SIZE] = '\0';
    guess[SIZE] = '\0';
    randomizeCString(code, SIZE, 'A', 'A' + SIZE);
    int correct = 0;
    int guesses = 0;
    while ((correct < SIZE) && (guesses < maxGuesses)) {
        cout << "Gjett " << SIZE << " bokstaver mellom A og " << (char) ('A' + LETTERS - 1) << ":";
        readInputToCString(guess, SIZE, 'A', 'A' + SIZE - 1);
        correct = checkCharactersAndPosition(code, guess);
        int charCount = checkCharacters(code, guess);
        cout << "Riktig plasserte: " << correct << " | " << "Riktige bokstaver: " << charCount << endl;
        guesses++;
    }
    if (correct == 4)
        cout << "Du vant!" << endl;
    else cout << "Du tapte! Koden var " << code << "." << endl;

    while (true) {
        cout << "Vil du spille igjen? (Y/N) ";
        char c;
        cin >> c;
        c = (char) toupper(c);
        switch (c) {
            case 'N':
                return;
            case 'Y':
                playMastermind(maxGuesses);
                break;
            default:
                cout << "Ugyldig valg." << endl;
        }
    }

}

int checkCharactersAndPosition(char *code, char *guess) {
    int count = 0;
    for (int i = 0; i < SIZE; i++) {
        if (code[i] == guess[i]) count++;
    }
    return count;
}

int checkCharacters(char *code, char *guess) {
    int count = 0;
    for (int i = 0; i < LETTERS; i++) {
        int countCode = countOccurencesOfCharacters(code, SIZE, 'A'+i);
        int countGuess = countOccurencesOfCharacters(guess, SIZE, 'A'+i);
        if (countCode < countGuess) {
            count += countCode;
        } else {
            count += countGuess;
        }
    }
    return count;
}