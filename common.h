#ifndef TICTACTOE_COMMON_H
#define TICTACTOE_COMMON_H

#include <iostream>
#include <random>

using namespace std;

// Constants
const int grid_size = 3;
const char SymbolString[] = {'-', 'X', 'O'};

// Enums
enum Symbols{Empty, X, O};
enum PlayerTypes{Human, RandomAI, SmartAI};

#endif //TICTACTOE_COMMON_H
