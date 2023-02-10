#include <iostream>
#include <string>
#include <stdio.h>
#include <string.h>
#include <fstream>
#include <cstdlib>
#include "cards.h"
using namespace std;

/*******************************************************************
**  Description:function that returns the rank of a card
**  
**  
*******************************************************************/
int Card:: get_rank()
{
    return this-> rank;
}
/*******************************************************************
**  Description:function that returns the suit of a card
**  
**  
*******************************************************************/
int Card::get_suit()
{
    return this-> suit;
}
/*******************************************************************
**  Description:function that sets the value of a card's rank
**  
**  
*******************************************************************/
void Card::set_rank (int rank){
	this->rank = rank;
}
/*******************************************************************
**  Description:function that sets the value of a card's suit
**  
**  
*******************************************************************/
void Card::set_suit (int suit){
	this-> suit = suit;
}
/*******************************************************************
**  Description:function that sets the value of a card's rank
**  
**  
*******************************************************************/
Card:: Card(int rank,int suit)
{
    this->rank=rank;
    this->suit=suit;
}
/*******************************************************************
**  Description:default constructor for my card class, initializes
    each rank and suit of objects created
**  
**  
*******************************************************************/
Card:: Card()
{
    this->rank=0;
    this->suit=0;
}
/*******************************************************************
**  Description:this function maps the rank of each card by taking a
**  rank has an input and returning the corresponding card rank in a
**  string format
*******************************************************************/
string Card::map_rank()const
{
	if(rank >1 && rank<11)
    {
        string rankString= to_string(this->rank);
        return rankString;
    }
    else if(this->rank==1)
    {
        string ace="ace";
        return "ace";
    }
    else if(this->rank==11)
    {
        string jack="jack";
        return "jack";
    }
    else if(this->rank==12)
    {
        return "queen";
    }
    else if(this->rank==13)
    {
        return "king";
    }
}
/*******************************************************************
**  Description:this function maps the suit of each card by taking a
**  suit has an input and returning the corresponding card rank in a
**  string format
*******************************************************************/
string Card::map_suit() const
{

    if(this->suit==0)
    {
        return "heart";
    }
    else if(this->suit==1)
    {
      
        return "diamond";
    }
    else if(this->suit==2)
    {
      
        return "spade";
    }
    else if(this->suit==3)
    {

        return "clubs";
    }
}
/*******************************************************************
**  Description:prints out a card object on the screen
*******************************************************************/
void Card::print_card()
{
	cout<<map_rank()<<" "<<map_suit()<<endl;
}