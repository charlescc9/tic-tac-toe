#ifndef TICKTACKTOE_PLAYER_H
#define TICKTACKTOE_PLAYER_H

#include "common.h"

using namespace std;

class Player {

private:
    // Variables
    int player_type;

    // Methods
    static pair<int, int> getMoveHuman();
    static pair<int, int> getMoveRandomAI(const vector<vector<int>> &board);
    static pair<int, int> getMoveSmartAI(int symbol, const vector<vector<int>> &board);

public:
    // Constructor
    explicit Player(int t);

    // Method
    pair<int, int> getMove(int symbol, const vector<vector<int>> &board);
};


#endif //TICKTACKTOE_PLAYER_H
