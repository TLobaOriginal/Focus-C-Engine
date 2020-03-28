#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>
#include "Initialiser.h"
//typedef enum coin{HEAD, TAIL}coin;
typedef enum turntatus{START, END}status;

int main() {

    player players[PLAYERS_NUM]; //This will hold the players
    square board[BOARD_SIZE][BOARD_SIZE]; //This will hold squares on the board
    initialize_players(players); //This function will initialise the players
    initialize_board(board); //This function will initialise the board
    print_board(board); //Prints out board
    srand(time(NULL));
    unsigned int coin = CoinToss();
    color turn;
    if(coin == 1)
        turn = RED;
    else if(coin == 2)
        turn = GREEN;

    switch(turn)
    {
        case(RED):
            puts("It is RED's turn");
            break;
        case(GREEN):
            puts("GREEN");
            break;
        default:
            puts("ERROR");
            break;
    }
    for(status myturn = START; players[0].win != true && players[1].win != true; myturn = START)
    {

    }

    return 0;
}
