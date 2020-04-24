//
// Created by Joseph Tobi Ogunbiyi on 02/04/2020.
//

#include "Stack.h"
#include <stdio.h>
#include "game.h"
#include <stdlib.h>
void reservedstack(square board[BOARD_SIZE][BOARD_SIZE], size_t Row, size_t Col, player *me)
{
    piece *top = board[Row][Col].stack; //Top points to the last piece on the stack
    board[Row][Col].num_pieces = 0; //Sets the number of pieces to 0 as we don't split a stack that we move but we move the whole stack

    piece *new_piece = (piece *)malloc(sizeof(piece)); //Assign space for this piece
    new_piece->p_color = me->player_color;             //Makes this piece the colour of the player
    new_piece->next = top;
    board[Row][Col].stack = new_piece;

    square *checker = &board[Row][Col];                 //Checker will point to the whole new square
    checker->num_pieces = 0;                            //We set it to 0 so we can check how many pieces are in the stack
    piece *curr = checker->stack;                       //Curr will point to the stack
    while(curr != NULL)
    {
        checker->num_pieces++; //Increment
        //printf("%d pieces\n",checker->num_pieces);
        curr = curr->next;     //Next position in list
    }
    int count = 1;             //Count will be a checker for a stack overload
    curr = checker->stack;
    piece *last = NULL;
    while(curr != NULL)
    {
        if(count < 5){
            curr = curr->next;
            count++;
        } else{ //If it is greater than 5
            last = curr; //Last will point to curr
            curr = curr->next;
            while(curr!=NULL)
            {
                piece *toRemove = curr;
                curr = curr->next;
                color this_piece = toRemove->p_color;
                free(toRemove);
                checker->num_pieces--;
                if (me->player_color == this_piece)
                    me->reserved++;
                else
                    me->captured++;
            }
            last->next = NULL;
        }
    }
    printf("%d number of pieces\n", checker->num_pieces);
    printf("%s has %d pieces captured\n",me->name, me->captured);
    printf("%s has %d pieces reserved\n",me->name, me->reserved);

}
void stacking(const int position[], square board[BOARD_SIZE][BOARD_SIZE], size_t originalRow, size_t originalCol, player *me)
{
    piece *top = board[originalRow][originalCol].stack; //Top points to the last piece on the stack
    board[originalRow][originalCol].stack = NULL;
    board[originalRow][originalCol].num_pieces = 0; //Sets the number of pieces to 0 as we don't split a stack that we move but we move the whole stack

    if(board[position[0]][position[1]].stack == NULL)//If the square we're moving to is empty
    {
        board[position[0]][position[1]].stack = top;//We'll let it equal to top so the new position now has the stack
        goto skip; //We jump to the next part because we don't need to do the following
    }

    piece *curr = top;        //Curr points to top
    while(curr->next != NULL) //When the next part of the stack is not NULL
        curr = curr->next;    //Increment
    curr->next = board[position[0]][position[1]].stack;
    board[position[0]][position[1]].stack = top;

    skip:;                                              //We have now jumped to the next part of the code
    square *checker = &board[position[0]][position[1]]; //Checker will point to the whole new square
    checker->num_pieces = 0;                            //We set it to 0 so we can check how many pieces are in the stack
    curr = checker->stack;                              //Curr will point to the stack
    while(curr != NULL)
    {
        checker->num_pieces++; //Increment
        //printf("%d pieces\n",checker->num_pieces);
        curr = curr->next;     //Next position in list
    }
    int count = 1;             //Count will be a checker for a stack overload
    curr = checker->stack;
    piece *last = NULL;
    while(curr != NULL)
    {
        if(count < 5){
            curr = curr->next;
            count++;
        } else{ //If it is greater than 5
            last = curr; //Last will point to curr
            curr = curr->next;
            while(curr!=NULL)
            {
                piece *toRemove = curr;
                curr = curr->next;
                color this_piece = toRemove->p_color;
                free(toRemove);
                checker->num_pieces--;
                if (me->player_color == this_piece)
                    me->reserved++;
                else
                    me->captured++;
            }
            last->next = NULL;
        }
    }
    //checker->num_pieces = count;
    printf("%d number of pieces\n", checker->num_pieces);
    printf("%s has %d pieces captured\n",me->name, me->captured);
    printf("%s has %d pieces reserved\n",me->name, me->reserved);
}