#ifndef TICTACTOE_PLAYER_H
#define TICTACTOE_PLAYER_H

#include "common.h"

class Player {

private:
    // Variables
    int player_type;

    // Methods
    static bool checkHorizontal(int row, int col, int symbol, int board[grid_size][grid_size]);
    static bool checkVertical(int row, int col, int symbol, int board[grid_size][grid_size]);
    static bool checkDiagonal(int row, int col, int symbol, int board[grid_size][grid_size]);
    static vector<pair<int, int>> getEmptySpaces(int board[grid_size][grid_size]);
    static pair<int, int> getMoveHuman();
    static pair<int, int> getMoveRandomAI(int board[grid_size][grid_size]);
    static pair<int, int> getMoveSmartAI(int player, int board[grid_size][grid_size]);

public:
    // Constructor
    explicit Player(int t);

    // Method
    pair<int, int> getMove(int symbol, int board[grid_size][grid_size]);
};

#endif //TICTACTOE_PLAYER_H
