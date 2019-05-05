#include "player.h"

using namespace std;

Player::Player(int t) {
    player_type = t;
}

pair<int, int> Player::getMoveHuman() {
    pair<int, int> move;
    cout << "Please enter a 0-indexed row and column separated by a space" << endl;
    cin >> move.first >> move.second;
    return move;
}

pair<int, int> Player::getMoveRandomAI(const vector<vector<int>> &board) {

    // Get all empty spaces
    set<pair<int, int>> empty_spaces;
    for (int i = 0; i < board.size(); ++i) {
        for (int j = 0; j < board.size(); ++j) {
            if (board.at(i).at(j) == Empty) {
                empty_spaces.insert({i, j});
            }
        }
    }

    // Randomly select an empty space
    random_device device;
    mt19937 generator(device());
    uniform_int_distribution<int> distribution(0, empty_spaces.size() - 1);
    auto iterator(empty_spaces.begin());
    advance(iterator, distribution(generator));
    return *iterator;
}

pair<int, int> Player::getMoveSmartAI(int symbol, const vector<vector<int>> &board) {
    return {};
}

pair<int, int> Player::getMove(int symbol, const vector<vector<int>> &board) {

    pair<int, int> move;

    switch (player_type) {
        case Human:
            move = getMoveHuman();
            break;
        case RandomAI:
            move = getMoveRandomAI(board);
            break;
        case SmartAI:
            move = getMoveSmartAI(symbol, board);
            break;
        default:
            move.first = -1;
            move.second = -1;
    }

    return move;
}