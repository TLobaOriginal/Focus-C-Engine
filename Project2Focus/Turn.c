//
// Created by Joseph Tobi Ogunbiyi on 21/04/2020.
//

#include "Turn.h"
#include <stdio.h>
#include "Initialiser.h"
#include "logic.h"
#include <stdbool.h>

void ThisTurn(player players[PLAYERS_NUM], square board[BOARD_SIZE][BOARD_SIZE], color turn)
{
    if(turn == RED) //Should turn be RED then we deal with the 0th or first player
    {
        if(players[0].reserved > 0) //If it's a case that there is a reserved piece
        {
            printf("%s has %d reserved pieces\n", players[0].name, players[0].reserved);

            //IF NO PIECES ARE AVAILABLE ON THE BOARD WE WILL BE FORCED TO USE THE RESERVED OPTION AND THISTURN WILL END HERE
            if(Available(board, players[0]) == false)
            {
                puts("A piece from the reserves has to be placed as there is no piece available for you on the board.");
                reservation(&players[0], board);
                return; //End of function reached
            }
            puts("Do you want to place a reserved piece.\n(1 for yes to place a reserved piece\n0 for no to continue turn normally)");

            int choice;//We can choose whether we want to place a reserved piece or move a piece on the board
            scanf("%d", &choice);
            while(choice > 1 || choice < 0)
            {
                puts("Choose again number invalid"); //Should an invalid number be chosen
                scanf("%d", &choice);
            }
            if(choice == 1)
                reservation(&players[0], board);
            else
                Myturn(&players[0], board); // This function will be the turn system

        }
        else{
            //If no reserved pieces are there
            puts("There are no reserved pieces");
            Myturn(&players[0], board); // This function will be the turn system
        }
        turn = GREEN;
        printf("----------------------\nIt's %s's turn\n----------------------\n", players[1].name);
    }
    else if(turn == GREEN) //The same logic applies
    {

        if(players[1].reserved > 0)
        {
            printf("%s has %d reserved pieces\n", players[1].name, players[1].reserved);
            //IF NO PIECES ARE AVAILABLE ON THE BOARD WE WILL BE FORCED TO USE THE RESERVED OPTION AND THISTURN WILL END HERE
            if(Available(board, players[1]) == false)
            {
                reservation(&players[1], board);
                return;
            }
            puts("Do you want to place a reserved piece.\n(1 for yes to place a reserved piece\n0 for no to continue turn normally)");
            int choice;
            scanf("%d", &choice);
            while(choice > 1 || choice < 0)
            {
                puts("Choose again number invalid");
                scanf("%d", &choice);
            }
            if(choice == 1)
                reservation(&players[1], board);
            else
                Myturn(&players[1], board); // This function will be the turn system
        }
        else{
            puts("There are no reserved pieces");
            Myturn(&players[1], board); // This function will be the turn system
        }
        turn = RED;
        printf("----------------------\nIt's %s's turn\n----------------------\n", players[0].name);

    }
}

bool WinChecker(square board[BOARD_SIZE][BOARD_SIZE], player myplayer)
{
    for(int i = 0; i < BOARD_SIZE; i++)
        for(int j = 0; j < BOARD_SIZE; j++)
            if(board[i][j].type == VALID && board[i][j].stack != NULL) //The analysed piece must be VALID and cannot be empty
                if(board[i][j].stack->p_color == myplayer.player_color || myplayer.reserved > 0) //If there is a top piece that is the players colour
                    return false; //No winner found
    return true;
}

bool Available(square board[BOARD_SIZE][BOARD_SIZE], player myplayer)
{
    for(int i = 0; i < BOARD_SIZE; i++)
        for(int j = 0; j < BOARD_SIZE; j++)
            if(board[i][j].type == VALID && board[i][j].stack != NULL)
                if(board[i][j].stack->p_color == myplayer.player_color)
                    return true; //If there is an available piece return true
    return false;
}

void Winner(player winner)
{
    printf("%s HAS ONE THE GAME!!!!\n", winner.name);
    switch(winner.player_color)
    {
        case(RED):
            printf("%s's colour is RED\n",winner.name);
            break;
        case(GREEN):
            printf("%s's colour is GREEN\n",winner.name);
            break;
        default:
            puts("ERROR");
    }
    printf("%s's has %d reserved pieces.\n", winner.name, winner.reserved);
    printf("%s's has %d captured pieces.\n", winner.name, winner.captured);
    puts("WELL DONE!!");
}

void TurnSwitch(color *turn)
{
    if(turn == RED)
        *turn = GREEN; //Turn switch
    else
        *turn = RED;
}