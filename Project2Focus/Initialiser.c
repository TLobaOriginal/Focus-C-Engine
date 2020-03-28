//
// Created by Joseph Tobi Ogunbiyi on 27/03/2020.
//

#include "Initialiser.h"
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
//
// Created by Lili on 26/03/2020.
//

//
// Created by Lili on 24/03/2020.
//
/* FUnction to print the board:
 * Invalid Squares are printed as | - |
 * Valid empty squares are printed as |   |
 * Valid squares with a GREEN piece are printed as | G |
 * Valid squares with a RED piece are printed as | R | */

void print_board(square board[BOARD_SIZE][BOARD_SIZE]){
    printf("****** The Board ******\n");
    for(int i = 0; i < BOARD_SIZE; i ++){
        for (int j = 0; j < BOARD_SIZE; j++){
            if(board[i][j].type == VALID) {
                if(board[i][j].stack == NULL)
                    printf("|   ");
                else{
                    if (board[i][j].stack->p_color == GREEN)
                        printf("| G ");
                    else printf("| R ");
                }
            }
            else
                printf("| - ");
        }
        printf("|\n");
    }
}
void initialize_players(player players[PLAYERS_NUM]){
    //Players have been initialised
    players[0].player_color = RED;
    players[1].player_color = GREEN;
    for(int i = 0; i < 2; i++)
    {
        players[i].captured = 0;
        players[i].total_pieces = 18;
        players[i].win = false;
        printf("Player %d, enter your name(MAX 14 CHARACTERS): ",i+1);
        fgets(players[i].name, 20, stdin);
        printf("%s has %d pieces left and %d adversary pieces captured\n", players[i].name, players[i].total_pieces, players[i].captured);
        puts("");
    }
}



unsigned int CoinToss()
{
    return 1 + rand() % 2;
}