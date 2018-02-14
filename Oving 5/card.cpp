//
// Created by Nicolai Stølen on 14/02/2018.
//

#include "card.h"



Card::Card() {
    valid = false;
}

Card::Card(Suit suit, Rank rank){
    initialize(suit, rank);
};

void Card::initialize(Suit suit, Rank rank) {
    this->suit = suit;
    this->rank = rank;
    this->valid = true;
}

Suit Card::getSuit() {
    return suit;
}

Rank Card::getRank() {
    return rank;
}

std::string Card::toString() {
    return rankToString(rank) + " of " + suitToString(suit);
}

std::string Card::toStringShort() {
    return suitToString(suit).substr(0, 1) + std::to_string(rank);
}

std::string suitToString(Suit suit) {
    switch (suit) {
        case Suit::CLUBS:
            return "Clubs";
        case Suit::DIAMONDS:
            return "Diamonds";
        case Suit::HEARTS:
            return "Hearts";
        case Suit::SPADES:
            return "Spades";
    }
}

std::string rankToString(Rank rank) {
    switch (rank) {
        case Rank::TWO:
            return "Two";
        case Rank::THREE:
            return "Three";
        case Rank::FOUR:
            return "Four";
        case Rank::FIVE:
            return "Five";
        case Rank::SIX:
            return "Six";
        case Rank::SEVEN:
            return "Seven";
        case Rank::EIGHT:
            return "Eight";
        case Rank::NINE:
            return "Nine";
        case Rank::TEN:
            return "Ten";
        case Rank::JACK:
            return "Jack";
        case Rank::QUEEN:
            return "Queen";
        case Rank::KING:
            return "King";
        case Rank::ACE:
            return "Ace";
    }
}

std::string toString(CardStruct card) {
    return rankToString(card.r) + " of " + suitToString(card.s);
}

std::string toStringShort(CardStruct card) {
    return suitToString(card.s).substr(0, 1) + std::to_string(card.r);
}














