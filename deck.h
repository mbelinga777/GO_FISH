#ifndef DECK_H
#define DECK_H
#include <iostream>
#include<string>
#include <stdio.h>
#include <string.h>
#include<cstdlib>
#include "cards.h"

class Deck
{
    private:
        Card cards[52]; 
        int n_cards;
    public:
        Deck();
        Card giveCard();
        void set_card(Card* card);
        void set_n_cards(int);
        Card get_cards();
        int  get_n_cards();
        void shuffleDeck();
        void printDeck();

};
#endif