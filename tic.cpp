#include <iostream>
using namespace std;

char board[3][3];

// This function prints the current game board
void printBoard() {
    cout << "\n";
    for(int i = 0; i < 3; ++i) {
        cout << " ";
        for(int j = 0; j < 3; ++j) {
            cout << board[i][j];
            if(j < 2) cout << " | ";
        }
        cout << "\n";
        if(i < 2) cout << "---|---|---\n";
    }
    cout << "\n";
}

// Checks if the board is full (draw)
bool isDraw() {
    for(int i = 0; i < 3; ++i)
        for(int j = 0; j < 3; ++j)
            if(board[i][j] == ' ')
                return false;
    return true;
}

// Checks if the current player has won
bool isWin(char player) {
    // Check rows and columns
    for(int i = 0; i < 3; ++i) {
        if(board[i][0] == player && board[i][1] == player && board[i][2] == player)
            return true;
        if(board[0][i] == player && board[1][i] == player && board[2][i] == player)
            return true;
    }
    // Check diagonals
    if(board[0][0] == player && board[1][1] == player && board[2][2] == player)
        return true;
    if(board[0][2] == player && board[1][1] == player && board[2][0] == player)
        return true;
    return false;
}

// Resets the board to start a new game
void resetBoard() {
    for(int i = 0; i < 3; ++i)
        for(int j = 0; j < 3; ++j)
            board[i][j] = ' ';
}

int main() {
    char player = 'X';
    int row, col;
    char playAgain;

    do {
        resetBoard();
        bool gameOver = false;
        cout << "Let's play Tic-Tac-Toe!\n";
        printBoard();

        while(!gameOver) {
            cout << "Player " << player << ", enter your move (row and column, 1-3 for each): ";
            cin >> row >> col;
            // Adjust for 0-based indexing
            row--; col--;

            // Check for valid move
            if(row < 0 || row > 2 || col < 0 || col > 2) {
                cout << "Invalid position. Try again.\n";
                continue;
            }
            if(board[row][col] != ' ') {
                cout << "That spot's taken. Try again.\n";
                continue;
            }

            board[row][col] = player;
            printBoard();

            if(isWin(player)) {
                cout << "Player " << player << " wins!\n";
                gameOver = true;
            } else if(isDraw()) {
                cout << "It's a draw!\n";
                gameOver = true;
            } else {
                // Switch player
                player = (player == 'X') ? 'O' : 'X';
            }
        }

        cout << "Play again? (y/n): ";
        cin >> playAgain;
        // Alternate starting player for fun
        player = (player == 'X') ? 'O' : 'X';
    } while(playAgain == 'y' || playAgain == 'Y');

    cout << "Thanks for playing!\n";
    return 0;
}
