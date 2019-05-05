#ifndef TICTACTOE_PLAYER_H
#define TICTACTOE_PLAYER_H

#include "common.h"
#include "board.h"

using namespace std;

class Player {

private:
    // Variables
    int player_type;

    // Methods
    pair<int, int> getMoveHuman();
    pair<int, int> getMoveRandomAI(const Board &game_board);
    int miniMax(const Board &game_board);
    pair<int, int> getMoveSmartAI(int symbol, const Board &game_board);

public:
    // Constructor
    explicit Player(int t);

    // Method
    pair<int, int> getMove(int symbol, const Board &game_board);
};


#endif //TICTACTOE_PLAYER_H
