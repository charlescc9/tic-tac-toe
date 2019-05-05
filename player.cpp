#include "player.h"

using namespace std;

Player::Player(int t) {
    player_type = t;
}

vector<pair<int, int>> Player::getEmptySpaces(const vector<vector<int>> &board) {
    vector<pair<int, int>> empty_spaces;
    for (int i = 0; i < board.size(); ++i) {
        for (int j = 0; j < board.size(); ++j) {
            if (board.at(i).at(j) == Empty) {
                empty_spaces.emplace_back(i, j);
            }
        }
    }
    return empty_spaces;
}

pair<int, int> Player::getMoveHuman() {
    pair<int, int> move;
    cout << "Please enter a 0-indexed row and column separated by a space" << endl;
    cin >> move.first >> move.second;
    return move;
}

pair<int, int> Player::getMoveRandomAI(const vector<vector<int>> &board) {

    // Get all empty spaces
    vector<pair<int, int>> empty_spaces = getEmptySpaces(board);

    // Randomly select an empty space
    random_device device;
    mt19937 generator(device());
    uniform_int_distribution<int> distribution(0, empty_spaces.size() - 1);
    auto iterator(empty_spaces.begin());
    advance(iterator, distribution(generator));
    return *iterator;
}

pair<int, int> Player::getMoveSmartAI(const vector<vector<int>> &board) {

    // Get all empty spaces
    vector<pair<int, int>> empty_spaces = getEmptySpaces(board);

    // Last move
    if (empty_spaces.size() == 1) {
        return empty_spaces.at(0);
    }

    // Move to center first
    if (empty_spaces.size() == 9) {
        return {1, 1};
    }

    // Try to get corner
    for (auto space : empty_spaces) {
        if ((space.first == 0 && space.second == 0) ||
            (space.first == 0 && space.second == 2) ||
            (space.first == 2 && space.second == 0) ||
            (space.first == 2 && space.second == 2)) {
            return space;
        }
    }

    // Otherwise, just pick first edge
    return empty_spaces.at(0);
}

pair<int, int> Player::getMove(const vector<vector<int>> &board) {

    pair<int, int> move;

    switch (player_type) {
        case Human:
            move = getMoveHuman();
            break;
        case RandomAI:
            move = getMoveRandomAI(board);
            break;
        case SmartAI:
            move = getMoveSmartAI(board);
            break;
        default:
            move.first = -1;
            move.second = -1;
    }

    return move;
}

