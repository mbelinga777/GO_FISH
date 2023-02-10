#include <iostream>
#include<string>
#include <stdio.h>
#include <string.h>
#include<cstdlib>
#include "cards.h"
#include "deck.h"
#include "hand.h"
#include "player.h"
#include "game.h"

using namespace std;

Game::Game()
{
    this->cards.shuffleDeck();
}
void Game:: distributeCards()
{
	Card c,c2;
	for(int i=0;i<7;++i)
	{
        c= cards.get_cards();
		c2= cards.get_cards();
		this->players[0].addCard(c);
		this->players[1].addCard(c2);
		
	}
}
bool Game::gameOver()
{
    if(this->players[0].get_n_books()+this->players[1].get_n_books()==13)
    {
        return true;
    }
    return false;
}
int Game::playerGoFish(char*m)
{
	cout<<"Go fish!\n";
    int r;
	Card c=cards.get_cards();
	players[0].addCard(c);
	cout<<"You drew a ";
	c.print_card();
	int IsBook=players[0].checkBook();
	if(IsBook!=1)
	{
		players[0].removePlayerBooks();
	}
	displayGame(m);
}
int Game::compGoFish()
{
	cout<<"Go fish!\n";
	Card c=cards.get_cards();
	players[1].addCard(c);
	int IsBook=players[1].checkBook();
	if(IsBook!=1)
	{
		players[1].removePlayerBooks();
	}
}
void Game::PlayerTurn(char*m)
{
	Card c;
	displayGame(m);
	int cardAsked=players[0].humanWantedCard();
    int cardReceived;
	if(!players[1].CardChecker(cardAsked))
	{
		cardReceived=playerGoFish(m);
		if(cardAsked!=cardReceived)
	    {
			return;
	    }
	}
	while(cardReceived==cardAsked ||players[1].CardChecker(cardAsked))
	{
		if(!players[1].CardChecker(cardAsked))
		{
			cardReceived=playerGoFish(m);
		}
		else
		{
			for(int i=0;i<players[1].getHandSize();++i)
			{
				if(players[1].getRank(i)==cardAsked)
				{
					c=players[1].getCardFromHand(i);
					players[0].addCard(c);
				}
			}
			players[1].removeCard(cardAsked);
		}
		players[0].removePlayerBooks();
		displayGame(m);
		if(players[0].getHandSize()>0)
			cardAsked=players[0].humanWantedCard();
	}
}
void Game::compTurn()
{
	Card c;
	
	int cardAsked=players[1].AIwantedCard();
    int cardReceived;
	if(!players[0].CardChecker(cardAsked))
	{
		cardReceived=compGoFish();
		if(cardAsked!=cardReceived)
	    {
			players[1].removePlayerBooks();
			return;
	    }

	}
	while(cardReceived==cardAsked ||players[0].CardChecker(cardAsked))
	{

		if(!players[0].CardChecker(cardAsked))
		{
			cardReceived=compGoFish();
		}
		else
		{
			for(int i=0;i<players[0].getHandSize();++i)
			{
				if(players[0].getRank(i)==cardAsked)
				{
					c=players[0].getCardFromHand(i);
					players[1].addCard(c);
				}
			}
			players[0].removeCard(cardAsked);
		}
		players[1].removePlayerBooks();
		if(players[1].getHandSize()>0)
			cardAsked=players[1].AIwantedCard();
	}
}
void Game::displayBooks(int x)
{
	for(int i=0;i<players[x].get_n_books();++i)
	{
		cout<<players[x].getBook()[i]<<" ";
	}
}
void Game::displayGame(char* gm)
{
	if(strcmp(gm,"true")==0)
	{
		cout<<"\n==================================";
		cout<<"\nCOMPUTER'S HAND\n\n";
		players[1].displayCards();
		cout<<"\nCOMPUTER'S BOOKS: ";
		displayBooks(1);
		cout<<"\n===================================\n";
		cout<<"YOUR HAND\n\n";
	    players[0].displayCards();
		cout<<"\nYOUR BOOKS: ";
		displayBooks(0);
		cout<<endl;
	}
	else
	{
		cout<<"\n====================================\n";
		cout<<"\nYOUR HAND\n\n";
		players[0].displayCards();
		cout<<"\nYOUR BOOKS: ";
		displayBooks(0);
		cout<<"\n====================================\n";
		cout<<"\nCOMPUTER'S BOOKS: ";
		displayBooks(1);
		cout<<endl;
	}
}

void Game::newGame(char* gm)
{

	distributeCards();
	while(!gameOver())
	{
		PlayerTurn(gm);
		compTurn();
	}
	if(players[0].get_n_books()>players[1].get_n_books())
	{
		cout<<"congratulations human you have won";
	}
	else
	{
		cout<<"i guess doing the extra credit was worth it, i beat you";
	}

}