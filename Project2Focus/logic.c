//
// Created by Joseph Tobi Ogunbiyi on 28/03/2020.
//

#include "logic.h"
#include "Initialiser.h"
#include "game.h"
#include "Stack.h"
#include <stdio.h>

void reservation(player *me, square board[BOARD_SIZE][BOARD_SIZE])
{
    /**This function almost carries the same logic as regular game function "Myturn"
     * We look at the row and column we want to place a piece on*/
    int row;
    int col;
    printf("Row: ");
    scanf("%d", &row);
    printf("Column: ");
    scanf("%d", &col);
    row -= 1;
    col -= 1;
    /**We need to check to see if the position chosen is valid**/
    while(board[row][col].type == INVALID)
    {
        row = 0;
        col = 0;
        puts("INVALID PIECE");
        printf("Row: ");
        scanf("%d", &row);
        printf("Column: ");
        scanf("%d", &col);
        row -= 1;
        col -= 1;
    }
    reservedstack(board, row, col, me); //This function is for the new piece
    print_board_update(board);          //Prints the updated board
    me->reserved--;                     //Reduces the numbers of reserved pieces by 1
    printf("%s has %d reserved pieces now\n",me->name, me->reserved); //And declares how many reserved pieces are left
}

void Myturn(player *me, square board[BOARD_SIZE][BOARD_SIZE])
{
    //When we start we need to player to select his or her own pieces
    int row;
    int col;
    int position[2];
    printf("Row: ");
    scanf("%d", &row);
    printf("Column: ");
    scanf("%d", &col);
    row -= 1;
    col -= 1;
    /**We need to check to see if the position chosen is valid**/
    while((board[row][col].stack == NULL ||board[row][col].stack->p_color != me->player_color)
    || (board[row][col].type == INVALID)) //Should the appropriate conditions not be made
    {
        row = 0;
        col = 0;
        puts("INVALID PIECE");
        printf("Row: ");
        scanf("%d", &row);
        printf("Column: ");
        scanf("%d", &col);
        row -= 1;
        col -= 1;
    }

    movement(board, row , col , position); //We run the function that will deal with movement
    printf("row: %d column: %d\nOriginal row: %d Original column: %d\n", position[0] + 1, position[1] + 1, row+1, col+1);
    stacking(position, board, row, col, me);
    print_board_update(board);
}


void movement(square board[BOARD_SIZE][BOARD_SIZE], int row, int col, int position[])
{
    printf("You can move up to %d squares.\n", board[row][col].num_pieces);
    puts("How many moves do you want to make: ");

    int move_number; //move_number will only be allowed to be up to the size of the stack
    scanf("%d", &move_number);
    while(move_number > board[row][col].num_pieces || move_number == 0) //If number is too large
    {
        printf("Error pick again");
        scanf("%d", &move_number);
    }

    //HELPS US CALCULATE THE MOVES
    char these_moves[move_number]; //This will create and array of characters the size of
    printf("Enter in your movements %d steps(W,A,S,D): ", move_number);
    for(int i = 0; i < move_number; i++)
        scanf(" %c", &these_moves[i]);//This will scan the character we need

    for(int i = 0; i < move_number; i++)
    {
        while((these_moves[i] != 'a' && these_moves[i] != 'A') && (these_moves[i] != 'd' && these_moves[i] != 'D') &&
              (these_moves[i] != 'w' && these_moves[i] != 'W') && (these_moves[i] != 's' && these_moves[i] != 'S')){
            puts("WRONG ELEMENT");
            puts("Enter another set of moves (W,A,S,D)");
            scanf(" %c",&these_moves[i]);
        }
    }
    ProcessMoves(these_moves, move_number, row, col, position);
}

void ProcessMoves(const char moves[], int steps, int row, int col, int position[])
{
    int vertical = 0, horizontal = 0; //We set them to so they can be incremented
    for(int i = 0; i < steps; i++)
    {
        if(moves[i] == 'w' || moves[i] == 'W')
            vertical--; //If we choose to go up we will need to decrease the row number so we use the decrement operator
        else if(moves[i] == 's' || moves[i] == 'S')
            vertical++; //If we wish to go down we must increase the row number hence the increment operator
        else if(moves[i] == 'a' || moves[i] == 'A')
            horizontal--;//If we wish to go left we must decrease the horizontal figure
        else if(moves[i] == 'd' || moves[i] == 'D')
            horizontal++;//To go right we must increase the horizontal figure
    }
    if(position[0] != 0)
        position[0] = row + vertical; //This will change the rows by the vertical number (if W or S is pressed)
    else
        position[0] = row;
    //Now for the column number to be calculated
    if(position[1] != 0)
        position[1] = col + horizontal; //This will change the columns by the horozontal number (If A or S is pressed)
    else
        position[1] = col;
}