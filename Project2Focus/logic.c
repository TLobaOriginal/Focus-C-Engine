//
// Created by Joseph Tobi Ogunbiyi on 28/03/2020.
//

#include "logic.h"
#include "Initialiser.h"
#include "game.h"
#include "Stack.h"
#include <stdio.h>

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

    piece *top = receivetop(board[row][col].stack);
    /**We need to check to see if the position chosen is valid**/
    while((top == NULL ||top->p_color != me->player_color)
    || (board[row][col].type == INVALID))
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
        top = receivetop(board[row][col].stack);
    }

    movement(board, row , col , position);
    printf("row: %d column: %d\nOriginal row: %d Original column: %d\n", position[0] + 1, position[1] + 1, row+1, col+1);
    stacking(position, board, row, col, me);
    print_board_update(board);
}

void ProcessMoves(const char moves[], int steps, int row, int col, int position[])
{
    int vertical = 0, horizontal = 0;
    for(int i = 0; i < steps; i++)
    {
        if(moves[i] == 'w' || moves[i] == 'W')
            vertical--;
        else if(moves[i] == 's' || moves[i] == 'S')
            vertical++;
        else if(moves[i] == 'a' || moves[i] == 'A')
            horizontal--;
        else if(moves[i] == 'd' || moves[i] == 'D')
            horizontal++;
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

   // printf("%d\t%d\n", position[0], position[1]);
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
    ///HELPS US CALCULATE THE MOVES
    char space[move_number]; //This will create and array of characters the size of
    printf("Enter in your movements %d steps(W,A,S,D): ", move_number);
    for(int i = 0; i < move_number; i++)
        scanf("%c", &space[i]);
    for(int i = 0; i < move_number; i++)
    {
        printf("%c\n", space[i]);
        while((space[i] != 'a' && space[i] != 'A')&& (space[i] != 'd' && space[i] != 'D') &&
        (space[i] != 'w' && space[i] != 'W') && (space[i] != 's' && space[i] != 'S')){
            puts("Enter another set of moves (W,A,S,D)");
            scanf("%c",&space[i]);
        }
    }
    ProcessMoves(space, move_number, row, col, position);
}
