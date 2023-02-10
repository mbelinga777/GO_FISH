#include <iostream>
#include<string>
#include <stdio.h>
#include <string.h>
#include<cstdlib>
#include "cards.h"
#include "deck.h"
#include "hand.h"
#include "player.h"

using namespace std;

Player::Player()
{
    this->n_books=0;
	this->books=NULL;
}
Player::~Player()
{
    if (this->books != NULL){
		delete [] this->books;
		this->books = NULL;
	}
}
 Player::Player (const Player & old_player)
{
    this->n_books=old_player.n_books;
    this->books = new int [this->n_books];

    for (int i = 0; i < this->n_books; i++)
    {
		this->books[i] = old_player.books[i];
    }
    this->hand=old_player.hand;

}
Player & Player:: operator=(const Player & old_player)
{
    if (this != &old_player)
    {
		this->n_books = old_player.n_books;

		if (this->books != NULL)
			delete [] this->books;

		this->books = new int [this->n_books];
		for (int i = 0; i < this->n_books; ++i)
			this->books[i] = old_player.books[i];	
      this->hand=old_player.hand;
	}
	return *this;
}
void Player:: displayCards()
{
	this->hand.print_hand();
}
Hand Player::getHand()
{
	return this-> hand;
}
int Player::getHandSize()
{
	return this->hand.get_n_cards();
}
Card Player::getCardFromHand(int i)
{
	return this->hand.getCard()[i];
}
int Player:: getRank(int i)
{
	return this->hand.getCard()[i].get_rank();
}
void Player::addCard(Card& c)
{
	this->hand.add_to_hand(c);
}
void Player::removeCard(int rank)
{
	this->hand.remove_cards_hand(rank);
}
void Player::removePlayerBooks()
{
	int r=this->hand.checkBook();
	while(r!=-1)
    {
		r=this->hand.checkBook();
		if(r!=-1)
		{
			addBook(r);
		    removeCard(r);
		}
		
   	}
}
int Player::checkBook()
{
	this->hand.checkBook();
}
int Player::get_n_books()
{
	return this->n_books;
}
int* Player::getBook()
{
	return this->books;
}
void Player::addBook(int& rank)
{
	if(this->books == NULL)
	{
		this->books = new int[++this->n_books];
    	this->books[this->n_books-1] = rank; 
		return;
	}
	int* tempBooks=new int[this->n_books+1];
	for(int i=0;i<n_books;++i)
	{
		tempBooks[i]=books[i];
	}
	tempBooks[n_books]=rank;
	delete[]this->books;
	this->books=tempBooks;
	this->n_books++;
}
void Player:: displayBooks()
{
	for(int i=0;i<this->n_books;++i)
	{
		if(this->books!=NULL)
			cout<<this->books[i]<<" ";
	}
	cout<<endl;
}
bool Player:: CardChecker(const int rank)
{
	int size= this->hand.get_n_cards();
	for(int i=0;i<size;++i)
	{
		if(this->hand.getCard()[i].get_rank()==rank)
		{
			return true;
		}
	}
	return false;
}
bool Player::isValidChoice( string& x)
{
    for(int i = 0;i<x.length();i++)
    {
      if(!isdigit(x.at(i)))
      {
        return false;
      }
    }
    if(stoi(x)<1 || stoi(x)>13)
    {
        return false;
    }
    else
    {
     return true;
    }
}
int Player::getWantedCard(string& x)
{
	cout<<"which rank would you like?\n";
	cin>>x;
	while(!isValidChoice(x))
	{
		cout<<"Bad input?\n";
	     cin>>x;
	}
	return stoi(x);
}
int Player::humanWantedCard()
{
	string want;
	int cardWanted=getWantedCard(want);
	
	while(!CardChecker(cardWanted))
	{
		cout<<"You do not have that rank, try again\n"<<endl;
		cardWanted=getWantedCard(want);
	}
	return cardWanted;
}

int Player:: AIwantedCard()
{
	int rankCounts[14]={0};
	int highest=this->hand.getCard()[0].get_rank();
//this loops through each ranks then looks for how many times that rank appears in the hand
	for(int i=1;i<=13;++i)
	{
		for(int j=0;j<this->hand.get_n_cards();++j)
		{
			if(this->hand.getCard()[j].get_rank()==i)
			{
				rankCounts[i]++;
			}
		}
		if(rankCounts[i]>highest)
		{
			highest=i;
		}
	}
	cout<<"computer wants a "<<highest<<endl;
	return highest;

}