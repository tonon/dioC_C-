#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <GLFW/glfw3.h>
#include "interface.h"

GLFWwindow* window;

void initializeOpenGL() {
    if (!glfwInit()) {
        fprintf(stderr, "Failed to initialize GLFW\n");
        exit(EXIT_FAILURE);
    }

    window = glfwCreateWindow(600, 600, "Tic Tac Toe", NULL, NULL);
    if (!window) {
        glfwTerminate();
        fprintf(stderr, "Failed to open GLFW window\n");
        exit(EXIT_FAILURE);
    }

    glfwMakeContextCurrent(window);
    glViewport(0, 0, 600, 600);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0, 3, 0, 3, -1, 1);
}

void renderBoard(Player board[SIZE][SIZE]) {
    glClear(GL_COLOR_BUFFER_BIT);

    // Desenhar linhas do tabuleiro
    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_LINES);
    for (int i = 1; i < SIZE; i++) {
        glVertex2f(i, 0);
        glVertex2f(i, SIZE);
        glVertex2f(0, i);
        glVertex2f(SIZE, i);
    }
    glEnd();

    // Desenhar X e O
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (board[i][j] == PLAYER_X) {
                glColor3f(1.0f, 0.0f, 0.0f);
                glBegin(GL_LINES);
                glVertex2f(j, i);
                glVertex2f(j + 1, i + 1);
                glVertex2f(j, i + 1);
                glVertex2f(j + 1, i);
                glEnd();
            } else if (board[i][j] == PLAYER_O) {
                glColor3f(0.0f, 0.0f, 1.0f);
                glBegin(GL_LINE_LOOP);
                for (int k = 0; k < 360; k++) {
                    float theta = k * 3.14159f / 180.0f;
                    glVertex2f(j + 0.5f + 0.5f * cos(theta), i + 0.5f + 0.5f * sin(theta));
                }
                glEnd();
            }
        }
    }

    glfwSwapBuffers(window);
}

int getPlayerMove(int *row, int *col) {
    if (glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_LEFT) == GLFW_PRESS) {
        double xpos, ypos;
        glfwGetCursorPos(window, &xpos, &ypos);
        *col = (int)(xpos / 200);
        *row = 2 - (int)(ypos / 200); // Inverter a coordenada y
        return 1;
    }
    return 0;
}
