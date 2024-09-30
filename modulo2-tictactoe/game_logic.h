#ifndef GAME_LOGIC_H
#define GAME_LOGIC_H

#define SIZE 3

typedef enum { EMPTY, PLAYER_X, PLAYER_O } Player;

void initializeBoard(Player board[SIZE][SIZE]);
int checkWin(Player board[SIZE][SIZE]);
int makeMove(Player board[SIZE][SIZE], int row, int col, Player player);

#endif // GAME_LOGIC_H
