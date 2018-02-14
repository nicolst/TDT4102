//
// Created by Nicolai Stølen on 14/02/2018.
//

#include <iostream>
#include "blackjack.h"


bool Blackjack::isAce(Card *card) {
    return card->getRank() == Rank::ACE;
}

int Blackjack::getCardValue(Card *card) {
    Rank rank = card->getRank();
    if (rank == Rank::ACE) return -1;
    if (Rank::JACK < rank < Rank::KING) return 10;
    return rank;
}

int Blackjack::getPlayerCardValue(Card *card) {
    if (isAce(card)) {
        std::cout << "You got an ace! Do you want your ace value to be 1 or 11? ";

        int value;
        std::cin >> value;

        while (value != 1 && value != 11) {
            std::cout << "Invalid value." << std::endl;
            std::cout << "Do you want your ace value to be 1 or 11? ";
            std::cin >> value;
        }
        return value;
    }
    return getCardValue(card);
}

int Blackjack::getDealerCardValue(Card *card, int dealerHandValue) {
    if (isAce(card)) return (dealerHandValue + 11) > 21 ? 1 : 11;
    return getCardValue(card);
}

bool Blackjack::askPlayerDrawCard() {
    std::cout << "Do you want to draw another card (Y/N)? ";
    char c;
    std::cin >> c;
    c = (char) toupper(c);

    while (c != 'Y' && c != 'N') {
        std::cout << "Invalid choice." << std::endl;
        std::cout << "Do you want to draw another card (Y/N)? ";
        std::cin >> c;
    }

    return c == 'Y';
}

void Blackjack::drawInitialCards() {
    for (int i = 0; i < 2; i++) {
        Card playerCard = deck.drawCard();
        std::cout << playerCard.toString() << std::endl;
        Card dealerCard = deck.drawCard();
        playerCardsDrawn++;
        dealerCardsDrawn++;
        playerHand += getPlayerCardValue(&playerCard);
        dealerHand += getDealerCardValue(&dealerCard, dealerHand);
    }
}

void Blackjack::printScores(bool showDealerScore) {
    std::cout << "\tCards drawn\tCard value" << std::endl
              << "Dealer\t" << dealerCardsDrawn << "\t\t" << (showDealerScore ? std::to_string(dealerHand) : "xx") << std::endl
              << "You\t" << playerCardsDrawn << "\t\t" << playerHand << std::endl;
}

void Blackjack::playGame() {
    bool finished = false;
    deck = CardDeck();
    deck.printShort();
    deck.shuffle();
    std::cout << std::endl;
    deck.printShort();
    playerHand = 0;
    dealerHand = 0;
    playerCardsDrawn = 0;
    dealerCardsDrawn = 0;

    drawInitialCards();

    bool drawn = true;
    while(!finished && drawn) {
        printScores(false);
        drawn = false;
        if (askPlayerDrawCard()) {
            drawn++;
            playerCardsDrawn++;
            Card playerCard = deck.drawCard();
            playerHand += getPlayerCardValue(&playerCard);
            if (playerHand > 21) break;
        }
        if (dealerHand < 17) {
            drawn++;
            dealerCardsDrawn++;
            Card dealerCard = deck.drawCard();
            dealerHand += getDealerCardValue(&dealerCard, dealerHand);
            if (dealerHand > 21) break;
        }
    }

    if (playerHand > 21) {
        std::cout << "You lost!" << std::endl;
    } else if (dealerHand > 21) {
        std::cout << "You won!" << std::endl;
    } else if (playerHand > dealerHand) {
        std::cout << "You won!" << std::endl;
    } else if (playerHand < dealerHand) {
        std::cout << "You lost!" << std::endl;
    } else {
        if (playerHand == 21) {
            if(playerCardsDrawn == 2) {
                if (dealerCardsDrawn == 2) std::cout << "Tie! (Both of you have blackjack)" << std::endl;
                else std::cout << "You win! (Blackjack vs 21)" << std::endl;
            } else {
                if (dealerCardsDrawn == 2) std::cout << "You lose! (21 vs Blackjack)" << std::endl;
                else std::cout << "Tie!" << std::endl;
            }
        } else {
            std::cout << "Tie!" << std::endl;
        }
    }

    printScores(true);
}
























