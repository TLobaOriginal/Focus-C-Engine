//
// Created by Joseph Tobi Ogunbiyi on 21/04/2020.
//

#ifndef PROJECT2FOCUS_TURN_H
#define PROJECT2FOCUS_TURN_H
#include "Initialiser.h"
#include <stdbool.h>
void ThisTurn(player players[PLAYERS_NUM], square board[BOARD_SIZE][BOARD_SIZE], color turn);
bool WinChecker(square board[BOARD_SIZE][BOARD_SIZE], player myplayer);
void Winner(player winner, player loser);
bool Available(square board[BOARD_SIZE][BOARD_SIZE], player myplayer);
void Intro();
#endif //PROJECT2FOCUS_TURN_H

