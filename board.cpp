#include "board.h"

using namespace std;

Board::Board() {
    board = {{Empty, Empty, Empty},
             {Empty, Empty, Empty},
             {Empty, Empty, Empty}};
    active_player = 1;
}

void Board::displayBoard() {
    for (int i = 0; i < 3; ++i) {
        cout << SymbolString[board.at(i).at(0)] << " | "
        << SymbolString[board.at(i).at(1)] << " | " << SymbolString[board.at(i).at(2)] << endl;
    }
}

bool Board::makeMove(int row, int col) {
    board.at(row).at(col) = active_player == 1 ? X : O;
    if (checkIfWinningBoard()) {
        return true;
    } else {
        board.at(row).at(col) = active_player == 1 ? X : O;
        active_player = active_player == 1 ? 2 : 1;
        return false;
    }
}

bool Board::checkIfWinningBoard() {
    char symbol = active_player == 1 ? X : O;

    // Check horizontal
    for (int i = 0; i < grid_size; ++i) {
        if (board.at(i).at(0) == symbol && board.at(i).at(1) == symbol && board.at(i).at(2) == symbol) {
            return true;
        }
    }

    // Check vertical
    for (int i = 0; i < grid_size; ++i) {
        if (board.at(0).at(i) == symbol && board.at(1).at(i) == symbol && board.at(2).at(i) == symbol) {
            return true;
        }
    }

    // Check left diagonal
    if (board.at(0).at(0) == symbol && board.at(1).at(1) == symbol && board.at(2).at(2) == symbol) {
        return true;
    }

    // Check right diagonal
    return board.at(0).at(2) == symbol && board.at(1).at(1) == symbol && board.at(2).at(0) == symbol;
}

bool Board::checkIfValidMove(int row, int col) {
    return row >= 0 && row < grid_size && col >= 0 && col < grid_size;
}

bool Board::checkIfEmptySpace(int row, int col) {
    return board.at(row).at(col) == Empty;
}

bool Board::checkIfTieGame() {

    // False if any empty spaces
    for (int i = 0; i < grid_size; ++i) {
        for (int j = 0; j < grid_size; ++j) {
            if (board.at(i).at(j) == 0) {
                return false;
            }
        }
    }

    // True otherwise
    return true;
}
