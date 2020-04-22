//
// Created by Joseph Tobi Ogunbiyi on 27/03/2020.
//

#include "game.h"
#include <stdio.h>
#include <stdlib.h>


//Set Invalid Squares (where it is not possible to place stacks)
void set_invalid(square * s){
s->type = INVALID;
s->stack = NULL;
s->num_pieces = 0;
}

//Set Empty Squares (with no pieces/stacks)
void set_empty(square * s){
s->type = VALID;
s->stack = NULL;
s->num_pieces = 0;
}

//Set squares  with a GREEN piece
void set_green(square * s){
s->type = VALID;
s->stack = (piece *) malloc (sizeof(piece));
s->stack->p_color = GREEN;
s->stack->next = NULL;
s->num_pieces = 1;
}

//Set squares with a RED piece
void set_red(square * s){
s->type = VALID;
s->stack = (piece *) malloc (sizeof(piece));
s->stack->p_color = RED;
s->stack->next = NULL;
s->num_pieces = 1;
}

//initializes the board
void initialize_board(square board [BOARD_SIZE][BOARD_SIZE]){

    for(int i=0; i< BOARD_SIZE; i++){
        for(int j=0; j< BOARD_SIZE; j++){
            //invalid squares
            if((i==0 && (j==0 || j==1 || j==6 || j==7)) || //(0,0),(0,1),(0,6),(0,7)
               (i==1 && (j==0 || j==7)) || //(1,0).(1,7)
               (i==6 && (j==0 || j==7)) || //(6,0).(6,7)
               (i==7 && (j==0 || j==1 || j==6 || j==7))) //(7,0),(7,1),(7,6),(7,7)
                set_invalid(&board[i][j]);

            else{
                //squares with no pieces
                if(i==0 || i ==7 || j==0 || j == 7) //All of row 1 and 7, column 0 and 7 are empty but yet still VALID
                    set_empty(&board[i][j]);
                else{
                    //squares with red pieces
                    if((i%2 == 1 && (j < 3 || j> 4)) ||
                       (i%2 == 0 && (j == 3 || j==4)))
                        set_red(&board[i][j]);
                        //green squares
                    else set_green(&board[i][j]);
                }
            }
        }


    }
}

void print_board_update(square board[BOARD_SIZE][BOARD_SIZE]){
    printf("****** The Board ******\n");
/*This updated version of print board allows to print the board and shows how many pieces are in a stack*/
    for(int i = 0; i < BOARD_SIZE; i ++)
    {
        for (int j = 0; j < BOARD_SIZE; j++)
        {
            if(board[i][j].type == VALID) //If it is a valid piece then
            {
                if(board[i][j].stack == NULL) //We check if it's an empty square
                    printf("|   ");
                else{
                    if (board[i][j].stack->p_color == GREEN && board[i][j].num_pieces == 1){ //If it is a square with one piece
                        printf("| G ");
                    }
                    else if(board[i][j].stack->p_color == RED && board[i][j].num_pieces == 1){
                        printf("| R ");
                    }
                    if(board[i][j].stack != NULL && board[i][j].num_pieces > 1) //With more than one piece we must show how many piece are there
                    {
                        if (board[i][j].stack->p_color == GREEN)
                        {
                            printf("| G%d", board[i][j].num_pieces);
                        }
                        else{
                            printf("| R%d", board[i][j].num_pieces);
                        }
                    }
                }
            }
            else //If it is not a valid piece then
                printf("| - ");
        }
        printf("|\n"); //Tot the next row
    }
}