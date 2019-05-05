#ifndef TICTACTOE_PLAYER_H
#define TICTACTOE_PLAYER_H

#include "common.h"

using namespace std;

class Player {

private:
    // Variables
    int player_type;

    // Methods
    vector<pair<int, int>> getEmptySpaces(const vector<vector<int>> &board);
    pair<int, int> getMoveHuman();
    pair<int, int> getMoveRandomAI(const vector<vector<int>> &board);
    pair<int, int> getMoveSmartAI(const vector<vector<int>> &board);

public:
    // Constructor
    explicit Player(int t);

    // Method
    pair<int, int> getMove(const vector<vector<int>> &board);
};


#endif //TICTACTOE_PLAYER_H
