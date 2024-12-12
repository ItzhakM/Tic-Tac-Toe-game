#include <iostream>
#include <vector>

using namespace std;

// Function to print the Tic-Tac-Toe board
void printBoard(const vector<vector<char>>& board) {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            cout << board[i][j];
            if (j < 2) {
                cout << " | ";
            }
        }
        cout << endl;
        if (i < 2) {
            cout << "---------+---------+---------\n";
        }
    }
}

// Function to check for a win condition
bool checkWin(const vector<vector<char>>& board, char player) {
    // ... (same as before)
}

// Function to check for a draw
bool checkDraw(const vector<vector<char>>& board) {
    // ... (same as before)
}

// Minimax algorithm to find the best move for the AI
int minimax(vector<vector<char>> board, int depth, bool isMax) {
    // ... (implementation of the Minimax algorithm)
}

// Function for the AI's turn
void aiTurn(vector<vector<char>>& board) {
    int bestScore = -1000;
    int row = -1, col = -1;

    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (board[i][j] == ' ') {
                board[i][j] = 'O';
                int score = minimax(board, 0, false);
                board[i][j] = ' ';

                if (score > bestScore) {
                    bestScore = score;
                    row = i;
                    col = j;
                }
            }
        }
    }

    board[row][col] = 'O';
}

int main() {
    vector<vector<char>> board(3, vector<char>(3, ' '));
    char currentPlayer = 'X';

    while (true) {
        printBoard(board);

        if (currentPlayer == 'X') {
            // Human player's turn
            int row, col;
            cout << "Player " << currentPlayer << ", enter your move (row, col): ";
            cin >> row >> col;

            if (row < 1 || row > 3 || col < 1 || col > 3 || board[row - 1][col - 1] != ' ') {
                cout << "Invalid move. Try again.\n";
                continue;
            }

            board[row - 1][col - 1] = currentPlayer;
        } else {
            // AI's turn
            aiTurn(board);
        }

        if (checkWin(board, currentPlayer)) {
            printBoard(board);
            cout << "Player " << currentPlayer << " wins!\n";
            break;
        } else if (checkDraw(board)) {
            printBoard(board);
            cout << "It's a draw!\n";
            break;
        }

        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    }

    return 0;
}

