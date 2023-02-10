#include <iostream>
#include<string>
#include <stdio.h>
#include <string.h>
#include<cstdlib>
#include "cards.h"
#include "deck.h"
#include "hand.h"
using namespace std;


Hand::Hand()
{
    this->n_cards=0;
	this->cards=NULL;
}
Hand::~Hand()
{
    if (this->cards != NULL)
	{
		delete [] this->cards;
		this->cards = NULL;
	}
}
Hand::Hand (const Hand & old_hand)
{
    this->n_cards= old_hand.n_cards;
    this->cards = new Card [this->n_cards];
	for (int i = 0; i < this->n_cards; i++)
			this->cards[i] = old_hand.cards[i];
}
Hand & Hand ::operator=(const Hand & old_Hand)
{
    if (this != &old_Hand)
    {
		this->n_cards = old_Hand.n_cards;

		if (this->cards != NULL)
			delete [] this->cards;

		this->cards = new Card [this->n_cards];
		for (int i = 0; i < this->n_cards; ++i)
			this->cards[i] = old_Hand.cards[i];	

	}
	return *this;
}
void Hand::add_to_hand(Card& a_card)
{
	
	if (this->cards == NULL)
	{
		this->cards = new Card[++this->n_cards];
    	this->cards[this->n_cards-1] = a_card; 
		return;
	}

	Card* temp = new Card[this->n_cards + 1];

	for (int i = 0; i < this->n_cards; ++i)
	{
		temp[i] = this->cards[i];
	}
	temp[this->n_cards] = a_card;

	delete [] this->cards;

	this->cards = temp;

	this->n_cards++;
}
Card* Hand::getCard()
{
	return this->cards;	
}
int Hand:: get_n_cards()
{
	return this->n_cards;
}
void Hand::remove_cards_hand(int rank)
{
    int count=0;
	int j=0;
	for(int i=0;i<this->n_cards;++i)
	{
		if(cards[i].get_rank()==rank)
		{
			count++;
		}
	}
	Card* temp = new Card[this->n_cards - count];
	for (int i = 0; i < this->n_cards; ++i)
	{
		if(this->cards[i].get_rank()!=rank)
		{
			temp[j] = this->cards[i];
			j++;
		}
		
	}
	delete [] this->cards;

	this->cards = temp;

	this->n_cards-=count;
}
void Hand::print_hand()
{
	for (int i = 0; i < this->n_cards; ++i)
	{
		this->cards[i].print_card();
	}
}
void Hand::remove_a_Book(int rank)
{
	Card* temp = new Card[this->n_cards - 4];
	int j =0;
	for(int i=0;i<this->n_cards;++i)
	{
		if(this->cards[i].get_rank()!=rank)
		{
			temp[j] = this->cards[i];
			j++;
		}
	}
	delete [] this->cards;
	this->cards = temp;
	this->n_cards-=4;
}
int Hand:: checkBook()
{
	int  cardCount;
	for(int i = 1;i<=13;++i)
	{
		cardCount=0;
		for(int j=0;j<this->n_cards;++j)
	    {
			if(this->cards[j].get_rank()==i)
			{
				cardCount++;
			}
	    }
		if(cardCount==4)
		{
			return i;
		}
	}
	return -1;
}

