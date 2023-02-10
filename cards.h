#ifndef CARDS_H
#define CARDS_H
#include <iostream>
#include<string>
#include <stdio.h>
#include <string.h>
#include<cstdlib>
using namespace std;

class Card
{
    private:
        int rank;
        int suit;
    
    public:
        void set_rank(int);
        int get_rank();
        void set_suit(int);
        int get_suit();
        string map_suit()const;
        string map_rank()const;
        void print_card();
        Card();
        Card (int rank,int suit);
};
#endif