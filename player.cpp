#include "player.h"

using namespace std;

Player::Player(int t) {
    player_type = t;
}

bool Player::checkHorizontal(int row, int col, int symbol, const vector<vector<int>> &board) {
    if (col == 0) {
        return board.at(row).at(1) == symbol && board.at(row).at(2) == symbol;
    } else if (col == 1) {
        return board.at(row).at(0) == symbol && board.at(row).at(2) == symbol;
    } else {
        return board.at(row).at(0) == symbol && board.at(row).at(1) == symbol;
    }
}

bool Player::checkVertical(int row, int col, int symbol, const vector<vector<int>> &board) {
    if (row == 0) {
        return board.at(1).at(col) == symbol && board.at(2).at(col) == symbol;
    } else if (row == 1) {
        return board.at(0).at(col) == symbol && board.at(2).at(col) == symbol;
    } else {
        return board.at(0).at(col) == symbol && board.at(1).at(col) == symbol;
    }
}

bool Player::checkDiagonal(int row, int col, int symbol, const vector<vector<int>> &board) {
    if (abs(row - col) == 1) {
        return false;
    } else if (row == 0 && col == 0) {
        return board.at(1).at(1) == symbol && board.at(2).at(2) == symbol;
    } else if (row == 0 && col == 2) {
        return board.at(1).at(1) == symbol && board.at(2).at(0) == symbol;
    } else if (row == 1 && col == 1) {
        return (board.at(0).at(0) == symbol && board.at(0).at(0) == symbol) ||
               (board.at(0).at(2) == symbol && board.at(2).at(0) == symbol);
    } else if (row == 2 && col == 0) {
        return board.at(0).at(2) == symbol && board.at(1).at(1) == symbol;
    } else {
        return board.at(0).at(0) == symbol && board.at(1).at(1) == symbol;
    }
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

pair<int, int> Player::getMoveSmartAI(int player, const vector<vector<int>> &board) {
    vector<pair<int, int>> empty_spaces = getEmptySpaces(board);
    int opponent = player == X ? O : X;

    // Last move
    if (empty_spaces.size() == 1) {
        return empty_spaces.at(0);
    }

    // Win if possible
    for (auto space : empty_spaces) {
        if (checkHorizontal(space.first, space.second, player, board) ||
            checkVertical(space.first, space.second, player, board) ||
            checkDiagonal(space.first, space.second, player, board)) {
            return space;
        }
    }

    // Block opponent if about to win
    for (auto space : empty_spaces) {
        if (checkHorizontal(space.first, space.second, opponent, board) ||
                checkVertical(space.first, space.second, opponent, board) ||
                checkDiagonal(space.first, space.second, opponent, board)) {
            return space;
        }
    }

    // Move to center first
    for (auto space : empty_spaces) {
        if (space.first == 1 && space.second == 1) {
            return space;
        }
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
