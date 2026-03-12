#include <stdbool.h>
#include <stdio.h>

void initialize_board(char board[3][3]) {
    for (int row = 0; row < 3; row++) {
        for (int col = 0; col < 3; col++) {
            board[row][col] = ' ';
        }
    }
}

void initialize_game(char board[3][3], bool player1Turn, bool gameOver) {
    initialize_board(board);
    player1Turn = true; // Player 1 starts the game
    gameOver = false; // Game is not over at the start
}

void play_turn(char board[3][3], bool player1Turn) {
    char currentPlayer = player1Turn ? 'X' : 'O';
    printf("Player %c's turn. Enter row and column (0-2): ", currentPlayer);
    int row, col;
    scanf("%d %d", &row, &col);
    if(row < 0 || row > 2 || col < 0 || col > 2) {
        printf("Invalid input. Please enter row and column between 0 and 2.\n");
        play_turn(board, player1Turn); // Retry the turn
        return;
    }
    if (board[row][col] == ' ') {
        board[row][col] = currentPlayer; // Place the player's mark on the board
    } else {
        printf("Cell already occupied. Try again.\n");
        play_turn(board, player1Turn); // Retry the turn
    }
}

void print_board(char board[3][3], bool gameOver) {
    if(!gameOver) {
        printf("Current board:\n");
    } else {
        printf("Final board:\n");
    }
    for (int row = 0; row < 3; row++) {
        for (int col = 0; col < 3; col++) {
            printf("| %c | ", board[row][col]);
        }
        printf("\n");
    }
}

void validate_game(char board[3][3], bool *gameOver) {
    // Check rows and columns for a win
    for (int i = 0; i < 3; i++) {
        if (board[i][0] != ' ' && board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
            printf("Player %c wins!\n", board[i][0]);
            print_board(board, *gameOver);
            *gameOver = true;
            return;
        }
        if (board[0][i] != ' ' && board[0][i] == board[1][i] && board[1][i] == board[2][i]) {
            printf("Player %c wins!\n", board[0][i]);
            print_board(board, *gameOver);
            *gameOver = true;
            return;
        }
    }
    // Check diagonals for a win
    if (board[0][0] != ' ' && board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
        printf("Player %c wins!\n", board[0][0]);
        print_board(board, *gameOver);
        *gameOver = true;
        return;
    }
    if (board[0][2] != ' ' && board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
        printf("Player %c wins!\n", board[0][2]);
        print_board(board, *gameOver);
        *gameOver = true;
        return;
    }
    // Check for a draw
    bool draw = true;
    for (int row = 0; row < 3; row++) {
        for (int col = 0; col < 3; col++) {
            if (board[row][col] == ' ') {
                draw = false; // Found an empty cell, not a draw
                break;
            }
        }
        if (!draw) break;
    }
    if (draw) {
        printf("It's a draw!\n");
        *gameOver = true;
    }
}

void play_game(char board[3][3], bool player1Turn, bool gameOver) {
    while (!gameOver) {
        print_board(board, gameOver);
        play_turn(board, player1Turn);
        validate_game(board, &gameOver);
        player1Turn = !player1Turn; // Switch turns
    }
}

bool restart_game() {
    printf("Do you want to play again? (y/n): ");
    char response;
    scanf(" %c", &response);
    if (response == 'y' || response == 'Y') {
        printf("Restarting the game...\n");
        return true;
    } else {
        printf("Thanks for playing!\n");
        return false;
    }
}

int main() {
    char board[3][3];
    bool player1Turn;
    bool gameOver;
    bool playing = true;
    while(playing) {
        initialize_game(board, player1Turn, gameOver);
        play_game(board, player1Turn, gameOver);
        playing = restart_game();
    }
    return 0;
}