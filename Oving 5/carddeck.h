//
// Created by Nicolai Stølen on 14/02/2018.
//

#include <vector>
#include "card.h"

#ifndef TDT4102_CARDDECK_H
#define TDT4102_CARDDECK_H

#endif //TDT4102_CARDDECK_H


class CardDeck {
    std::vector<Card> cards;
    int currentCardIndex;


public:
    CardDeck();
    void print();
    void printShort();
    void shuffle();
    Card drawCard();
    void swap(int c1, int c2);
};