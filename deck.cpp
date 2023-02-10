#include <iostream>
#include <string>
#include <stdio.h>
#include <string.h>
#include <fstream>
#include <cstdlib>
#include "deck.h"
#include <ctime> 
#include <cstdlib>
using namespace std;
/*******************************************************************
**  Description: constructor, creates a deck of 52 cards everytime
    a deck object is created 
**  
**  
*******************************************************************/
Deck::Deck()
{
    this->n_cards=52;
    for (int i=0;i<52;i++)
    {
        this->cards[i]=Card((i%13)+1,(i/13));
    }
}

 Card Deck:: giveCard()
 {
     
     return cards[n_cards];
 }
 void Deck::set_n_cards(int numCards)
 {
     this->n_cards=numCards;
 }
 int Deck::get_n_cards()
 {
     return this->n_cards;
 }
 void Deck::set_card(Card* cards)
 {
     this->cards;
 }
 Card Deck::get_cards()
 {
         this->n_cards--;
         return this->cards[n_cards];
 }
 void Deck::shuffleDeck()
 {
     int index;
    srand(time(NULL));
    Card temp,temp2;
        for(int i=0;i<52;i++)
        {
             temp=cards[i];
             index=rand()%52;
             temp2=cards[index];
             cards[i]=temp2;
             cards[index]=temp;
        }
}
void Deck::printDeck()
{
    for(int i=0;i<52;i++)
    {
       this-> cards[i].print_card();
    }
}