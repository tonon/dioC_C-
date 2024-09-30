#ifndef INTERFACE_H
#define INTERFACE_H

#include "game_logic.h"

void initializeOpenGL();
void renderBoard(Player board[SIZE][SIZE]);
int getPlayerMove(int *row, int *col);  // Certifique-se de que a função retorna um int

#endif // INTERFACE_H
