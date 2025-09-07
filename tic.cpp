#include <iostream>
#include <vector>

using namespace std;

// Function to print the Tic-Tac-Toe board
void printBoard(const vector<vector<char>>& board) {
    cout << "  1 2 3" << endl;
    for (int i = 0; i < 3; i++) {
        cout << i + 1 << " ";
        for (int j = 0; j < 3; j++) {
            cout << board[i][j] << (j < 2 ? "|" : "");
        }
        cout << endl;
        if (i < 2) {
            cout << "  -+-+-" << endl;
        }
    }
}

// Function to check if a player has won
char checkWin(const vector<vector<char>>& board) {
    // Check rows
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ') {
            return board[i][0];
        }
    }

    // Check columns
    for (int i = 0; i < 3; i++) {
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != ' ') {
            return board[0][i];
        }
    }

    // Check diagonals
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ') {
        return board[0][0];
    }
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != ' ') {
        return board[0][2];
    }

    return ' '; // No winner yet
}

int main() {
    vector<vector<char>> board(3, vector<char>(3, ' '));
    char currentPlayer = 'X';
    int moves = 0;
    char winner = ' ';

    cout << "Welcome to Tic-Tac-Toe!" << endl;

    while (moves < 9 && winner == ' ') {
        printBoard(board);

        int row, col;
        cout << "Player " << currentPlayer << ", enter your move (row and column): ";
        cin >> row >> col;

        // Adjust to 0-based indexing
        row--;
        col--;

        if (row >= 0 && row < 3 && col >= 0 && col < 3 && board[row][col] == ' ') {
            board[row][col] = currentPlayer;
            moves++;
            winner = checkWin(board);
            currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
        } else {
            cout << "Invalid move. Try again." << endl;
        }
    }

    printBoard(board);

    if (winner != ' ') {
        cout << "Player " << winner << " wins!" << endl;
    } else {
        cout << "It's a draw!" << endl;
    }

    return 0;
}
