#ifndef TICTACTOE_PLAYER_H
#define TICTACTOE_PLAYER_H

#include "common.h"

using namespace std;

class Player {

private:
    // Variables
    int player_type;

    // Methods
    static bool checkHorizontal(int row, int col, int symbol, const vector<vector<int>> &board);
    static bool checkVertical(int row, int col, int symbol, const vector<vector<int>> &board);
    static bool checkDiagonal(int row, int col, int symbol, const vector<vector<int>> &board);
    static vector<pair<int, int>> getEmptySpaces(const vector<vector<int>> &board);
    static pair<int, int> getMoveHuman();
    static pair<int, int> getMoveRandomAI(const vector<vector<int>> &board);
    static pair<int, int> getMoveSmartAI(int player, const vector<vector<int>> &board);

public:
    // Constructor
    explicit Player(int t);

    // Method
    pair<int, int> getMove(int symbol, const vector<vector<int>> &board);
};


#endif //TICTACTOE_PLAYER_H
