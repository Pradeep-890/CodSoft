#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Function to display the Tic-Tac-Toe board
void DisplayBoard(const vector<vector<char>>& board) {
    cout << "Tic-Tac-Toe Board:" << endl;
    for (int row = 0; row < 3; ++row) {
        for (int col = 0; col < 3; ++col) {
            cout << board[row][col];
            if (col < 2) {
                cout << " | ";
            }
        }
        cout << endl;
        if (row < 2) {
            cout << "---------" << endl;
        }
    }
}

// Function to check if a player has won
bool CheckWin(const vector<vector<char>>& board, char player) {
    // Check rows, columns, and diagonals for a win
    for (int i = 0; i < 3; ++i) {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player) {
            return true; // Row win
        }
        if (board[0][i] == player && board[1][i] == player && board[2][i] == player) {
            return true; // Column win
        }
    }
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player) {
        return true; // Diagonal win (top-left to bottom-right)
    }
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player) {
        return true; // Diagonal win (top-right to bottom-left)
    }
    return false;
}

// Function to check if the game is a draw
bool CheckDraw(const vector<vector<char>>& board) {
    for (int row = 0; row < 3; ++row) {
        for (int col = 0; col < 3; ++col) {
            if (board[row][col] == ' ') {
                return false; // Empty cell found, game is not a draw
            }
        }
    }
    return true; // All cells are filled, game is a draw
}

int main() {
    vector<vector<char>> board(3, vector<char>(3, ' ')); // Initialize the 3x3 board with empty cells
    char currentPlayer = 'X';
    bool gameWon = false;
    bool gameDraw = false;

    cout << "Welcome to Tic-Tac-Toe!" << endl;

    while (!gameWon && !gameDraw) {
        DisplayBoard(board);
        cout << "Player " << currentPlayer << ", enter your move (row and column): ";
        int row, col;
        cin >> row >> col;

        // Check if the input is valid
        if (row >= 1 && row <= 3 && col >= 1 && col <= 3 && board[row - 1][col - 1] == ' ') {
            board[row - 1][col - 1] = currentPlayer;

            // Check if the current player has won
            if (CheckWin(board, currentPlayer)) {
                DisplayBoard(board);
                cout << "Player " << currentPlayer << " wins!" << endl;
                gameWon = true;
            } else {
                // Check for a draw
                if (CheckDraw(board)) {
                    DisplayBoard(board);
                    cout << "It's a draw!" << endl;
                    gameDraw = true;
                } else {
                    // Switch players
                    currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
                }
            }
        } else {
            cout << "Invalid move. Try again." << endl;
        }
    }

    cout << "Do you want to play again? (yes/no): ";
    string playAgain;
    cin >> playAgain;

    if (playAgain == "yes") {
        // Reset the board and variables for a new game
        board.assign(3, vector<char>(3, ' '));
        currentPlayer = 'X';
        gameWon = false;
        gameDraw = false;
    } else {
        cout << "Thanks for playing! Goodbye!" << endl;
    }

    return 0;
}
