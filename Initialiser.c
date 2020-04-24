//
// Created by Joseph Tobi Ogunbiyi on 27/03/2020.
//

#include "Initialiser.h"
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

/* FUnction to print the board:
 * Invalid Squares are printed as | - |
 * Valid empty squares are printed as |   |
 * Valid squares with a GREEN piece are printed as | G |
 * Valid squares with a RED piece are printed as | R | */

void initialize_players(player players[PLAYERS_NUM]){
    //Players have been initialised
    players[0].player_color = RED;
    players[1].player_color = GREEN;
    for(int i = 0; i < 2; i++)
    {
        players[i].captured = 0; //Nobody has a piece captured
        players[i].total_pieces = 18; //Everyone starts off with 18 pieces
        players[i].reserved = 0;
        players[i].win = false; //Win will start on false
        printf("Player %d, enter your name(MAX 20 CHARACTERS): ",i+1);
        fgets(players[i].name, 20, stdin); //We can initialise the player name
        printf("%s has %d pieces left, %d adversary pieces captured and %d pieces reserved\n", players[i].name, players[i].total_pieces, players[i].captured, players[i].reserved);
        puts("");
        for(int j = 0; players[i].name[j] != '\0'; j++)
            if(players[i].name[j] == '\n')
                players[i].name[j] = '\0';
    }
    printf("%s is RED\n%s is GREEN\n\n", players[0].name, players[1].name);
}

unsigned int CoinToss()
{
    return 1 + rand() % 2; //Coin toss
}

