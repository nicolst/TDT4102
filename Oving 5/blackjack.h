//
// Created by Nicolai Stølen on 14/02/2018.
//

#include "carddeck.h"

#ifndef TDT4102_BLACKJACK_H
#define TDT4102_BLACKJACK_H

#endif //TDT4102_BLACKJACK_H


class Blackjack {
    CardDeck deck;
    int playerHand;
    int dealerHand;
    int playerCardsDrawn;
    int dealerCardsDrawn;
    bool isAce(Card *card);
    int getCardValue(Card *card);
    int getPlayerCardValue(Card *card);
    int getDealerCardValue(Card *card, int dealerHandValue);
    bool askPlayerDrawCard();
    void drawInitialCards();
    void printScores(bool showDealerScore);

public:
    void playGame();
};