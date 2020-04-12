//
// Created by Joseph Tobi Ogunbiyi on 28/03/2020.
//

#ifndef PROJECT2FOCUS_LOGIC_H
#define PROJECT2FOCUS_LOGIC_H
#include "game.h"
#include <stdio.h>
void Myturn(player *me, square board[BOARD_SIZE][BOARD_SIZE]);
void ProcessMoves(const char moves[], int steps, int row, int col, int position[]);
void movement(square board[BOARD_SIZE][BOARD_SIZE], int row, int col, int position[]);
void updates(int position[], square board[BOARD_SIZE][BOARD_SIZE], int originalRow, int originalCol);
#endif //PROJECT2FOCUS_LOGIC_H
