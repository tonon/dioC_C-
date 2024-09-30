#include <stdio.h>
#include <GLFW/glfw3.h>  // Inclua o cabeçalho da GLFW
#include "game_logic.h"
#include "interface.h"

int main() {
    Player board[SIZE][SIZE];
    Player currentPlayer = PLAYER_X;
    int row, col, winner = 0;

    initializeBoard(board);
    initializeOpenGL();

    while (!glfwWindowShouldClose(glfwGetCurrentContext())) {
        renderBoard(board);
        if (getPlayerMove(&row, &col)) {
            if (makeMove(board, row, col, currentPlayer)) {
                winner = checkWin(board);
                if (winner) break;
                currentPlayer = (currentPlayer == PLAYER_X) ? PLAYER_O : PLAYER_X;
            } else {
                printf("Invalid move. Try again.\n");
            }
        }
        glfwPollEvents();
    }

    renderBoard(board);
    if (winner) {
        printf("Player %c wins!\n", (winner == PLAYER_X) ? 'X' : 'O');
    } else {
        printf("Game ended without a winner.\n");
    }

    glfwTerminate();
    return 0;
}
