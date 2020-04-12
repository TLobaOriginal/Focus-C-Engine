#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>
#include "Initialiser.h"
#include "logic.h"
typedef enum turn_status{START, END}status;

int main() {
    puts("Welcome to Focus.");
    puts("There are two players. The rules have been displayed on the box of the game");
    puts("The way for you to pick a piece is by entering in the coordinates for example row: 2, column: 3 will be equivalent to (1,2)");
    puts("You'll be asked 'Row:' and you can enter 1 to access row 1 and the same goes for picking columns");
    printf("\tMOVEMENT\nW = Up\nA = Left\nD = Right\nS = Down\n\n\n");


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
            puts("It's is RED's turn\nBegin!!!");
            break;
        case(GREEN):
            puts("It's GREEN's turn\nBegin!!!");
            break;
        default:
            puts("ERROR");
            break;
    }
    player *playPtr;

    for(status myturn = START; players[0].win != true || players[1].win != true; myturn = START) //This loop will only end the moment a winner has been found
    {
        if(turn == RED)
        {
            playPtr = &players[0];
            Myturn(playPtr, board); // This function will be the turn system
            turn = GREEN;
            puts("----------------------\nIt's Green's turn\n----------------------");
        }
        else if(turn == GREEN)
        {
            playPtr = &players[1];
            Myturn(playPtr, board); // This function will be the turn system
            turn = RED;
            puts("----------------------\nIt's Red's turn\n----------------------");
        }

    }

    return 0;
}
