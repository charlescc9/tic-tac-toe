#ifndef TICTACTOE_BOARD_H
#define TICTACTOE_BOARD_H

#include "common.h"

class Board {

public:
    // Constructor
    Board();

    // Variables
    int board[grid_size][grid_size];
    int active_player;

    // Methods
    bool checkIfEmptySpace(int row, int col);
    void makeMove(int row, int col);
    bool checkIfWinningBoard();
    bool checkIfTieGame();
    void switchActivePlayer();
    void displayBoard();
};

#endif //TICTACTOE_BOARD_H
