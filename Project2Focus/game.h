//
// Created by Joseph Tobi Ogunbiyi on 27/03/2020.
//

#ifndef PROJECT2FOCUS_GAME_H
#define PROJECT2FOCUS_GAME_H
#define BOARD_SIZE 8
#define PLAYERS_NUM 2

#include "stdbool.h"

//colors that a piece can have
typedef enum color {
    RED,
    GREEN
}color;

// Square types
//INVALID: squares that are on the sides and where no piece can be placed
//VALID: squares where it is possible to place a piece or a stack
typedef enum square_type {
    VALID,
    INVALID
}square_type;

//Player
typedef struct player{
    //the color associated with the player
    color player_color;
    //The players name will be max 14 characters
    char name[21];
    //Number of pieces captured
    int captured;
    int reserved;
    //Number of pieces that the player has
    int total_pieces;
    //win or false
    bool win;

}player;

// A piece
typedef struct piece {
    //the color associated with a piece
    color p_color;

    // This is a pointer to the next pieces
    // to create a stack. For this lab you do not have to think too much about it.
    struct piece * next;

}piece;

// A Square of the board
typedef struct square {
    // type of the square (VALID/INVALID)
    square_type type;

    //the piece or the top piece on the stack
    piece * stack;

    //number of pieces on the square
    int num_pieces;

}square;


//Function to create the board
void initialize_board(square board[BOARD_SIZE][BOARD_SIZE]);
void set_empty(square * s);
void set_green(square * s);
void set_red(square * s);
void set_invalid(square * s);
#endif //PROJECT2FOCUS_GAME_H
