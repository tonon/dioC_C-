#include "game_logic.h"

void initializeBoard(Player board[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            board[i][j] = EMPTY;
        }
    }
}

int checkWin(Player board[SIZE][SIZE]) {
    // Verifica linhas, colunas e diagonais
    for (int i = 0; i < SIZE; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != EMPTY)
            return board[i][0];
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != EMPTY)
            return board[0][i];
    }
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != EMPTY)
        return board[0][0];
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != EMPTY)
        return board[0][2];
    
    return 0; // Nenhum vencedor
}

int makeMove(Player board[SIZE][SIZE], int row, int col, Player player) {
    if (board[row][col] == EMPTY) {
        board[row][col] = player;
        return 1; // Movimento válido
    }
    return 0; // Movimento inválido
}
