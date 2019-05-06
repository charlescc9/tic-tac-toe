#include "player.h"

Player::Player(int t) {
    player_type = t;
}

bool Player::checkHorizontal(int row, int col, int symbol, int board[grid_size][grid_size]) {
    if (col == 0) {
        return board[row][1] == symbol && board[row][2] == symbol;
    } else if (col == 1) {
        return board[row][0] == symbol && board[row][2] == symbol;
    } else {
        return board[row][0] == symbol && board[row][1] == symbol;
    }
}

bool Player::checkVertical(int row, int col, int symbol, int board[grid_size][grid_size]) {
    if (row == 0) {
        return board[1][col] == symbol && board[2][col] == symbol;
    } else if (row == 1) {
        return board[0][col] == symbol && board[2][col] == symbol;
    } else {
        return board[0][col] == symbol && board[1][col] == symbol;
    }
}

bool Player::checkDiagonal(int row, int col, int symbol, int board[grid_size][grid_size]) {
    if (abs(row - col) == 1) {
        return false;
    } else if (row == 0 && col == 0) {
        return board[1][1] == symbol && board[2][2] == symbol;
    } else if (row == 0 && col == 2) {
        return board[1][1] == symbol && board[2][0] == symbol;
    } else if (row == 1 && col == 1) {
        return (board[0][0] == symbol && board[2][2] == symbol) || (board[0][2] == symbol && board[2][0] == symbol);
    } else if (row == 2 && col == 0) {
        return board[0][2] == symbol && board[1][1] == symbol;
    } else {
        return board[0][0] == symbol && board[1][1] == symbol;
    }
}

vector<pair<int, int>> Player::getEmptySpaces(int board[grid_size][grid_size]) {
    vector<pair<int, int>> empty_spaces;
    for (int i = 0; i < grid_size; ++i) {
        for (int j = 0; j < grid_size; ++j) {
            if (board[i][j] == Empty) {
                empty_spaces.emplace_back(i, j);
            }
        }
    }
    return empty_spaces;
}

pair<int, int> Player::getMoveHuman() {
    pair<int, int> move;
    string input, row, col;

    // Loop while invalid input
    bool invalid = true;
    while (invalid) {

        // Get user input
        cout << "Please enter a 0-indexed row and column separated by a comma" << endl;
        cin >> input;

        // Check if valid
        int comma = input.find(',');
        row = input.substr(0, comma);
        col = input.substr(comma + 1, input.size());
        if (row.size() != 1 || col.size() != 1 || comma == -1 || !isdigit(row.at(0)) || ! isdigit(col.at(0))) {
            cout << "Error: invalid input, please try again" << endl;
            cin.clear();
        } else {
            move.first = stoi(row);
            move.second = stoi(col);
            invalid = false;
        }
    }

    return move;
}

pair<int, int> Player::getMoveRandomAI(int board[grid_size][grid_size]) {

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

pair<int, int> Player::getMoveSmartAI(int player, int board[grid_size][grid_size]) {
    int opponent = player == X ? O : X;

    // Get all empty spaces
    vector<pair<int, int>> empty_spaces = getEmptySpaces(board);

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

pair<int, int> Player::getMove(int symbol, int board[grid_size][grid_size]) {
    pair<int, int> move;

    // Get appropriate move for player type
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
            cout << "Error: Invalid player type" << endl;
    }

    return move;
}
