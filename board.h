#ifndef TICTACTOE_BOARD_H
#define TICTACTOE_BOARD_H

#include "common.h"

using namespace std;

class Board {

public:
    // Constructor
    Board();

    // Variable
    vector<vector<int>> board;
    int active_player;

    // Methods
    bool checkIfWinningBoard();
    bool checkIfValidMove(int row, int col);
    bool checkIfEmptySpace(int row, int col);
    bool makeMove(int row, int col);
    bool checkIfTieGame();
    void displayBoard();
};


#endif //TICTACTOE_BOARD_H
