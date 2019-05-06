#include "board.h"

Board::Board() {

    // Initialize board to all empty spaces
    for (int i = 0; i < grid_size; ++i) {
        for (int j = 0; j < grid_size; ++j) {
            board[i][j] = Empty;
        }
    }

    // Player 1 starts
    active_player = 1;
}

bool Board::checkIfEmptySpace(int row, int col) {
    return board[row][col] == Empty;
}

void Board::makeMove(int row, int col) {
    board[row][col] = active_player == 1 ? X : O;
}

bool Board::checkIfWinningBoard() {
    char symbol = active_player == 1 ? X : O;

    // Check horizontal
    for (int i = 0; i < grid_size; ++i) {
        if (board[i][0] == symbol && board[i][1] == symbol && board[i][2] == symbol) {
            return true;
        }
    }

    // Check vertical
    for (int i = 0; i < grid_size; ++i) {
        if (board[0][i] == symbol && board[1][i] == symbol && board[2][i] == symbol) {
            return true;
        }
    }

    // Check left diagonal
    if (board[0][0] == symbol && board[1][1] == symbol && board[2][2] == symbol) {
        return true;
    }

    // Check right diagonal
    return board[0][2] == symbol && board[1][1] == symbol && board[2][0] == symbol;
}

bool Board::checkIfTieGame() {

    // False if any empty spaces
    for (int i = 0; i < grid_size; ++i) {
        for (int j = 0; j < grid_size; ++j) {
            if (board[i][j] == Empty) {
                return false;
            }
        }
    }

    // True otherwise
    return true;
}

void Board::switchActivePlayer() {
    active_player = active_player == 1 ? 2 : 1;
}

void Board::displayBoard() {
    for (int i = 0; i < 3; ++i) {
        cout << SymbolString[board[i][0]] << " | "
             << SymbolString[board[i][1]] << " | "
             << SymbolString[board[i][2]] << endl;
    }
    cout << endl;
}
