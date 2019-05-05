#ifndef TICKTACKTOE_COMMON_H
#define TICKTACKTOE_COMMON_H

#include <iostream>
#include <vector>
#include <set>
#include <random>

// Constants
const int grid_size = 3;
const char SymbolString[] = {'-', 'X', 'O'};

// Enums
enum Symbols{Empty, X, O};
enum PlayerTypes{Human, RandomAI, SmartAI};

#endif //TICKTACKTOE_COMMON_H
