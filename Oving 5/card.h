//
// Created by Nicolai Stølen on 14/02/2018.
//

#ifndef TDT4102_CARD_H
#define TDT4102_CARD_H

#endif //TDT4102_CARD_H

#include <string>

enum Suit {CLUBS, DIAMONDS, HEARTS, SPADES};

enum Rank {TWO=2, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN , JACK, QUEEN, KING, ACE};

struct CardStruct {
    Suit s;
    Rank r;
};

class Card {
    Suit suit;
    Rank rank;
    bool valid;

public:
    void initialize(Suit suit, Rank rank);
    Suit getSuit();
    Rank getRank();
    std::string toString();
    std::string toStringShort();
    Card();
    Card(Suit suit, Rank rank);
};

std::string suitToString(Suit suit);

std::string rankToString(Rank rank);

std::string toString(CardStruct card);

std::string toStringShort(CardStruct card);

