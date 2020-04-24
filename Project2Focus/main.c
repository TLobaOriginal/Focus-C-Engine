#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>
#include "Initialiser.h"
#include "Turn.h"
/*CODE NAME: FOCUS
 * By: Joseph Ogunbiyi - 22/04/20
 * This is a code based off the game called Focus. All the rules are explained at the start of the game*/

int main() {
    Intro();
    player players[PLAYERS_NUM];           //This will hold the players
    square board[BOARD_SIZE][BOARD_SIZE];  //This will hold squares on the board
    initialize_players(players);           //This function will initialise the players
    initialize_board(board);               //This function will initialise the board
    print_board_update(board);             //Prints out board
    srand(time(NULL));
    unsigned int coin = CoinToss();        //Will get the coin to be randomised
    color turn;                            //turn will hold to colour of the current player's turn
    if(coin == 1)       //If 1 RED
        turn = RED;
    else if(coin == 2)  //If 2 GREEN
        turn = GREEN;


    switch(turn)
    {
        case(RED):
            printf("It's %s's turn\nBEGIN!!!!\n", players[0].name);
            break;
        case(GREEN):
            printf("It's %s's turn\nBEGIN!!!!\n", players[1].name);
            break;
        default:
            puts("ERROR");
            exit(0);
    }

    while(WinChecker(board, players[0]) == false && WinChecker(board, players[1]) == false) //This loop will only end the moment a winner has been found
    {
        ThisTurn(players, board, turn);
        if(turn == RED)
            turn = GREEN; //Turn switch
        else
            turn = RED;
    }

    /*When the loop ends this happens
     * We check to see if the current player can move or not and if it returns true then the other player has one*/
    if(WinChecker(board, players[0]) == true)
        Winner(players[1]); //Green wins if Red can't move
    else if(WinChecker(board, players[1]) == true)
        Winner(players[0]); //Red wins if Green can't move

    return 0;
}
