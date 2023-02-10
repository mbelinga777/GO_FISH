
#ifndef PLAYER_H
#define PLAYER_H
#include <iostream>
#include<string>
#include <stdio.h>
#include <string.h>
#include<cstdlib>
#include "cards.h"
#include "deck.h"
#include "hand.h"
class Player {
 private:
    Hand hand;
    int* books; // Array with ranks for which the player has books.
    int n_books;
 public:
    ~Player();
    Player();
    Player (const Player &);
    Player& operator=(const Player &);
    void displayCards();
    void addCard(Card& );
    void removePlayerBooks();
    void removeCard(int rank);
    int checkBook();
    int get_n_books();
    int* getBook();
    Hand getHand();
    Card getCardFromHand(int i);
    int getRank(int i);
    int getHandSize();
    void addBook(int& rank);
    void displayBooks();
    bool isValidChoice( string& x);
    int getWantedCard(string& x);
    bool CardChecker(const int rank);
    int humanWantedCard();
    Card accessCard(int i);
    int AIwantedCard();

};

#endif