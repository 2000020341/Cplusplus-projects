#include <iostream>
#include <vector>
#include <iomanip>

class TicTacToe {
private:
    std::vector<std::vector<char>> board;
    char currentPlayer;

public:
    TicTacToe() : board(3, std::vector<char>(3, ' ')), currentPlayer('X') {}

    void displayBoard() {
        std::cout << "\n   1   2   3\n";
        for (int i = 0; i < 3; i++) {
            std::cout << i + 1 << "  ";
            for (int j = 0; j < 3; j++) {
                std::cout << board[i][j];
                if (j < 2) std::cout << " | ";
            }
            std::cout << "\n";
            if (i < 2) std::cout << "  -----------\n";
        }
        std::cout << "\n";
    }

    bool makeMove(int row, int col) {
        // Check if position is valid and empty
        if (row < 0 || row > 2 || col < 0 || col > 2) {
            std::cout << "Invalid position! Please enter row and column between 1-3.\n";
            return false;
        }
        
        if (board[row][col] != ' ') {
            std::cout << "Position already taken! Please choose an empty cell.\n";
            return false;
        }

        board[row][col] = currentPlayer;
        return true;
    }

    bool checkWin() {
        // Check rows
        for (int i = 0; i < 3; i++) {
            if (board[i][0] == currentPlayer && board[i][1] == currentPlayer && board[i][2] == currentPlayer) {
                return true;
            }
        }

        // Check columns
        for (int j = 0; j < 3; j++) {
            if (board[0][j] == currentPlayer && board[1][j] == currentPlayer && board[2][j] == currentPlayer) {
                return true;
            }
        }

        // Check diagonals
        if (board[0][0] == currentPlayer && board[1][1] == currentPlayer && board[2][2] == currentPlayer) {
            return true;
        }
        if (board[0][2] == currentPlayer && board[1][1] == currentPlayer && board[2][0] == currentPlayer) {
            return true;
        }

        return false;
    }

    bool isBoardFull() {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (board[i][j] == ' ') {
                    return false;
                }
            }
        }
        return true;
    }

    void switchPlayer() {
        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    }

    char getCurrentPlayer() {
        return currentPlayer;
    }

    void resetGame() {
        board = std::vector<std::vector<char>>(3, std::vector<char>(3, ' '));
        currentPlayer = 'X';
    }

    void playGame() {
        std::cout << "=== Welcome to Tic-Tac-Toe ===\n";
        std::cout << "Players will take turns. X goes first.\n";
        std::cout << "Enter row and column (1-3) separated by space to make your move.\n";

        while (true) {
            displayBoard();
            
            std::cout << "Player " << currentPlayer << "'s turn.\n";
            std::cout << "Enter row and column (1-3): ";
            int row, col;
            std::cin >> row >> col;

            // Convert to 0-based indexing
            row--; 
            col--;

            if (makeMove(row, col)) {
                if (checkWin()) {
                    displayBoard();
                    std::cout << "🎉 Player " << currentPlayer << " wins! 🎉\n";
                    break;
                }
                
                if (isBoardFull()) {
                    displayBoard();
                    std::cout << "It's a tie! The board is full.\n";
                    break;
                }
                
                switchPlayer();
            }
        }

        // Ask if players want to play again
        char playAgain;
        std::cout << "Do you want to play again? (y/n): ";
        std::cin >> playAgain;
        
        if (playAgain == 'y' || playAgain == 'Y') {
            resetGame();
            playGame();
        } else {
            std::cout << "Thanks for playing!\n";
        }
    }
};

int main() {
    TicTacToe game;
    game.playGame();
    return 0;
}
