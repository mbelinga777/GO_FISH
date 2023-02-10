
#ifndef game_H
#define game_H
#include <iostream>
#include<string>
#include <stdio.h>
#include <string.h>
#include<cstdlib>
#include "cards.h"
#include "deck.h"
#include "hand.h"
#include "player.h"

class Game
 {
 private:
    Deck cards;
    Player players[2];
 public:
        Game();
        bool gameOver();
        void distributeCards();
        void newGame(char * m);
        int playerGoFish(char*m);
        void PlayerTurn(char*m);
        void compTurn();
        int compGoFish();
        void displayGame(char* gm);
        void displayBooks(int x);
};
#endif