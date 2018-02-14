//
// Created by Nicolai Stølen on 14/02/2018.
//
#include <iostream>
#include <ctime>
#include "blackjack.h"


int main() {
    std::srand(time(nullptr));

    CardStruct card1{Suit::HEARTS, Rank::ACE};
    CardStruct card2{Suit::SPADES, Rank::FIVE};

    std::cout << "Rank::SIX: " << rankToString(Rank::SIX) << std::endl;
    std::cout << "Suit::CLUBS: " << suitToString(Suit::CLUBS) << std::endl << std::endl;

    std::cout << "Card 1" << std::endl
              << "toString:\t" << toString(card1) << std::endl
              << "toStringShort:\t" << toStringShort(card1) << std::endl << std::endl;

    std::cout << "Card 2" << std::endl
              << "toString:\t" << toString(card2) << std::endl
              << "toStringShort:\t" << toStringShort(card2) << std::endl << std::endl;

    Blackjack bj = Blackjack();

    while (true) {
        bj.playGame();
        std::cout << "Do you want to play again? (Y/N)";
        char c;
        std::cin >> c;
        c = (char) toupper(c);

        while (c != 'Y' && c != 'N') {
            std::cout << "Invalid choice." << std::endl;
            std::cout << "Do you want to draw another card (Y/N)? ";
            std::cin >> c;
        }
        if (c == 'N') break;
    }



    return 0;
}