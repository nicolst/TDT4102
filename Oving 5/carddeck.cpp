//
// Created by Nicolai Stølen on 14/02/2018.
//

#include <iostream>
#include "carddeck.h"

CardDeck::CardDeck() {
    for (int s = 0; s < 4; s++) {
        for (int r = 2; r < 15; r++) {
            Suit suit = static_cast<Suit>(s);
            Rank rank = static_cast<Rank>(r);
            cards.push_back(Card(suit, rank));
        }
    }
    this->currentCardIndex = 0;
}

void CardDeck::swap(int c1, int c2) {
    Card temp = cards[c1];
    cards[c1] = cards[c2];
    cards[c2] = temp;
}

void CardDeck::print() {
    for (int i = 0; i < cards.size(); i++) {
        std::cout << cards[i].toString() << " ";
        if (i % 3 == 0 && i != 0) std::cout << std::endl;
    }
}

void CardDeck::printShort() {
    for (int i = 0; i < cards.size(); i++) {
        std::cout << cards[i].toStringShort() << " ";
        if (i % 3 == 0 && i != 0) std::cout << std::endl;
    }
}

void CardDeck::shuffle() {
    for (int i = 0; i < 52; i++) {
        int random1 = std::rand() % 52;
        int random2 = std::rand() % 52;
        swap(random1, random2);
    }
}

Card CardDeck::drawCard() {
    return cards[currentCardIndex++];
}