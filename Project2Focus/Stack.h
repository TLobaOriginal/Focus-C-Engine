//
// Created by Joseph Tobi Ogunbiyi on 02/04/2020.
//

#ifndef PROJECT2FOCUS_STACK_H
#define PROJECT2FOCUS_STACK_H
#include "game.h"
#include <stdio.h>

void stacking(const int position[], square board[BOARD_SIZE][BOARD_SIZE], size_t originalRow, size_t originalCol, player *me);
piece * receivetop(piece * newsquare);
#endif //PROJECT2FOCUS_STACK_H
