#ifndef TICTACTOE_BOARD_H
#define TICTACTOE_BOARD_H

#include "common.h"

using namespace std;

class Board {

private:
    // Methods
    bool checkIfWinningBoard();

public:
    // Constructor
    Board();

    // Variable
    int board[grid_size][grid_size];
    int active_player;

    bool checkIfEmptySpace(int row, int col);
    bool makeMove(int row, int col);
    bool checkIfTieGame();
    void displayBoard();
};


#endif //TICTACTOE_BOARD_H
