#include <iostream>
#include <vector>
#include <iomanip>

// ANSI Color Codes
#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"
#define WHITE   "\033[37m"
#define BOLD    "\033[1m"
#define BG_BLACK "\033[40m"
#define BG_WHITE "\033[47m"

class TicTacToe {
private:
    std::vector<std::vector<char>> board;
    char currentPlayer;

public:
    TicTacToe() : board(3, std::vector<char>(3, ' ')), currentPlayer('X') {}

    void displayBoard() {
        std::cout << "\n" << CYAN << BOLD << "   1   2   3" << RESET << "\n";
        for (int i = 0; i < 3; i++) {
            std::cout << CYAN << BOLD << i + 1 << RESET << "  ";
            for (int j = 0; j < 3; j++) {
                char cell = board[i][j];
                if (cell == 'X') {
                    std::cout << RED << BOLD << cell << RESET;
                } else if (cell == 'O') {
                    std::cout << BLUE << BOLD << cell << RESET;
                } else {
                    std::cout << WHITE << cell << RESET;
                }
                if (j < 2) std::cout << YELLOW << " | " << RESET;
            }
            std::cout << "\n";
            if (i < 2) std::cout << YELLOW << "  -----------" << RESET << "\n";
        }
        std::cout << "\n";
    }

    bool makeMove(int row, int col) {
        // Check if position is valid and empty
        if (row < 0 || row > 2 || col < 0 || col > 2) {
            std::cout << RED << "❌ Invalid position! Please enter row and column between 1-3." << RESET << "\n";
            return false;
        }
        
        if (board[row][col] != ' ') {
            std::cout << RED << "❌ Position already taken! Please choose an empty cell." << RESET << "\n";
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
        std::cout << GREEN << BOLD << "🎮 === Welcome to Tic-Tac-Toe === 🎮" << RESET << "\n";
        std::cout << YELLOW << "Players will take turns. " << RED << BOLD << "X" << RESET << YELLOW << " goes first." << RESET << "\n";
        std::cout << CYAN << "Enter row and column (1-3) separated by space to make your move." << RESET << "\n";

        while (true) {
            displayBoard();
            
            if (currentPlayer == 'X') {
                std::cout << RED << BOLD << "Player X" << RESET << "'s turn.\n";
            } else {
                std::cout << BLUE << BOLD << "Player O" << RESET << "'s turn.\n";
            }
            std::cout << MAGENTA << "Enter row and column (1-3): " << RESET;
            int row, col;
            std::cin >> row >> col;

            // Convert to 0-based indexing
            row--; 
            col--;

            if (makeMove(row, col)) {
                if (checkWin()) {
                    displayBoard();
                    if (currentPlayer == 'X') {
                        std::cout << GREEN << BOLD << "🎉 Player " << RED << BOLD << currentPlayer << GREEN << BOLD << " wins! 🎉" << RESET << "\n";
                    } else {
                        std::cout << GREEN << BOLD << "🎉 Player " << BLUE << BOLD << currentPlayer << GREEN << BOLD << " wins! 🎉" << RESET << "\n";
                    }
                    break;
                }
                
                if (isBoardFull()) {
                    displayBoard();
                    std::cout << YELLOW << BOLD << "🤝 It's a tie! The board is full." << RESET << "\n";
                    break;
                }
                
                switchPlayer();
            }
        }

        // Ask if players want to play again
        char playAgain;
        std::cout << CYAN << "Do you want to play again? (y/n): " << RESET;
        std::cin >> playAgain;
        
        if (playAgain == 'y' || playAgain == 'Y') {
            std::cout << GREEN << "🔄 Starting new game..." << RESET << "\n\n";
            resetGame();
            playGame();
        } else {
            std::cout << MAGENTA << BOLD << "👋 Thanks for playing!" << RESET << "\n";
        }
    }
};

int main() {
    TicTacToe game;
    game.playGame();
    return 0;
}
