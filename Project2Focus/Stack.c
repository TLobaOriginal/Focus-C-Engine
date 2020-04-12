//
// Created by Joseph Tobi Ogunbiyi on 02/04/2020.
//

#include "Stack.h"
#include <stdio.h>
#include "Initialiser.h"
#include "game.h"
#include <stdlib.h>

set_empty_2(square * s){
s->type = VALID;
s->stack = NULL;
s->num_pieces = 0;
}

//Set squares  with a GREEN piece
set_green_2(square * s){
s->type = VALID;
s->stack = (piece *) malloc (sizeof(piece));
s->stack->p_color = GREEN;
s->stack->next = NULL;
s->num_pieces = 1;
}

//Set squares with a RED piece
set_red_2(square * s){
s->type = VALID;
s->stack = (piece *) malloc (sizeof(piece));
s->stack->p_color = RED;
s->stack->next = NULL;
s->num_pieces = 1;
}

void stacking(const int position[], square board[BOARD_SIZE][BOARD_SIZE], size_t originalRow, size_t originalCol, player *me)
{
     if(board[position[0]][position[1]].stack == NULL)
         board[position[0]][position[1]].stack = (piece *)malloc(sizeof(piece)); //Space has been given to the empty space
     if(board[position[0]][position[1]].stack == NULL)
     {
     /**If space cannot be given the empty space then an error will be returned**/
         perror("Not enough space");
         exit(0);
     }
     piece *top, *startptr, *startptr2;
     startptr = board[position[0]][position[1]].stack; //Starting pointer to the bottom of the stack
    if(position[0]==0 || position[0] ==7 || position[1]==0 || position[1] == 7)
        top = (piece* )malloc(sizeof(piece));
    else
    {
        top = receivetop(startptr);                        //This will initialise top as the top of the stack of the new position
        switch(top->p_color)
        {
            case(RED):
                puts("top is RED");
                break;
            case(GREEN):
                puts("top is GREEN");
                break;
            default:
                puts("ERROR");
                break;
        }
    }
    startptr2 = board[originalRow][originalCol].stack; //Piece will equal the bottom of the stack of the orginal positiiton that has to be moved
    switch(startptr2->p_color)
    {
        case(RED):
            puts("start is RED");
            break;
        case(GREEN):
            puts("start is GREEN");
            break;
        default:
            puts("ERROR");
            break;
    }
    /*piece * top2 = receivetop(startptr2);
   witch(top2->p_color)
   {
       case(RED):
           puts("top 2 is RED");
           break;
       case(GREEN):
           puts("top 2 is GREEN");
           break;
       default:
           puts("ERROR");
           break;
   }*/
    if(top->p_color != RED && top->p_color != GREEN)
    {
        board[position[0]][position[1]].stack = startptr2;
        set_empty_2(&board[originalRow][originalCol]);
    }
    else{
        top->next = startptr2;
        set_empty_2(&board[originalRow][originalCol]);
    }


        /*if(top->p_color != RED && top->p_color != GREEN)
            board[position[0]][position[1]].stack = bottom;
        else
            top->next = bottom->stack;*/

     piece *curr = startptr;
    board[position[0]][position[1]].num_pieces = 0;

     while(curr != NULL){
         switch(curr->p_color)
         {
             case(RED):
                 puts("RED");
                 break;
             case(GREEN):
                 puts("GREEN");
                 break;
             default:
                 puts("ERROR");
                 break;
         }
         curr = curr->next; //We go to the next pointer
         board[position[0]][position[1]].num_pieces++;
         printf("%d\n", board[position[0]][position[1]].num_pieces);
     }
     set_empty_2(&board[originalRow][originalCol]);
}

piece * receivetop(piece * newsquare)
{
    piece *top = newsquare;
    int i = 0;
    while(top != NULL)
    {
        i++;
        //printf("piece: %d\n", i);
        if(top->next != NULL)
        {
           /*switch(top->p_color)
            {
                case(RED):
                    puts("this piece is RED");
                    break;
                case(GREEN):
                    puts("this piece is GREEN");
                    break;
                default:
                    puts("ERROR");
                    break;
            }*/
            top = top->next;
        }
        else
            break;
    }
    return top;
}
