#ifndef HAND_H
#define HAND_H
#include <iostream>
#include<string>
#include <stdio.h>
#include <string.h>
#include<cstdlib>
#include "cards.h"
#include "deck.h"

using namespace std;
class Hand 
{
 private:
    Card* cards; // An array of cards in hand
    int n_cards; // Number of cards in the hand.
 public:
    ~Hand();
    Hand();
    Hand (const Hand &);
    Hand & operator=(const Hand &);
    void add_to_hand (Card& a_card);
    Card* getCard();
    int get_n_cards();
    void remove_cards_hand(int rank);
    void print_hand();
    int checkBook();
    void remove_a_Book(int rank);
};
#endif