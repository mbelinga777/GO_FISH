/*******************************************************************
** Program: Gofish.cpp
** Author: marc belinga
** Date: 05/10/2022
** Description:program simulates a  game of gold fish between a user and the computer
** Input: playAgain ,card wanted
** Output:a game of go fish
*******************************************************************/
#include <iostream>
#include <string>
#include <stdio.h>
#include <string.h>
#include <cstdlib>
#include "cards.h"
#include "deck.h"
#include "hand.h"
#include "player.h"
#include "game.h"
using namespace std;

/*******************************************************************
**  Description: this function checks if an input is a number between
    0 and 1. it checks if each element is a digit then checks if the 
    the value of the limit is within limits
**  Input: a string
**  Output: return true if condition are met, false otherwise
*******************************************************************/
bool isValidPlayAgain( string x)
{
    for(int i = 0;i<x.length();i++)
    {
      if(!isdigit(x.at(i)))
      {
        return false;
      }
    }
    if(stoi(x)<0 || stoi(x)>1)
    {
        return false;
    }
    else return true;
}
/*******************************************************************
**  Description: this function checks if an input is a number between
    0 and 1. it checks if each element is a digit then checks if the 
    the value of the limit is within limits if it is, it will return 
    true if the user wants to play again ad false otherwise
**  Input: a string
**  Output: return true if user press 1, false otherwise
*******************************************************************/
bool playAgain(string& x)
{
    cout<<"would you like to play again? 1-yes 0-no ";
    cin>>x;
    while(!isValidPlayAgain(x))
    {
        cout<<"\nBad input, would you like to play again? 1-yes 0-no ";
        cin>>x;
    }
    if(stoi(x)==1)
    {
        return true;
    }
    if(stoi(x)==0)
    {
        return false;
    }
}
int main(int argc, char**argv)
{
    string Again;
    if(strcmp((argv[1]),"true")!=0 && strcmp((argv[1]),"false")!=0)
    {
        cout<<"bad command line argument program will shut down";
        return 0;
    }
    do
    {
        Game theGame;
        theGame.newGame(argv[1]);
    }
    while(playAgain(Again));
    

}