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

pair<int, int> Player::getMoveRandomAI(const Board &game_board) {

    // Get all empty spaces
    vector<pair<int, int>> empty_spaces = game_board.getEmptySpaces();

    // Randomly select an empty space
    random_device device;
    mt19937 generator(device());
    uniform_int_distribution<int> distribution(0, empty_spaces.size() - 1);
    auto iterator(empty_spaces.begin());
    advance(iterator, distribution(generator));
    return *iterator;
}

int Player::miniMax(const Board &game_board) {
    return 0;
}

pair<int, int> Player::getMoveSmartAI(int symbol, const Board &game_board) {

    // Get all empty spaces
    vector<pair<int, int>> empty_spaces = game_board.getEmptySpaces();

    int best_score;
    if (symbol == X) {
        best_score = numeric_limits<int>::max();
        for (auto & empty_space : empty_spaces) {

            // Copy game board
            Board game_board_copy;
            game_board_copy.board = game_board.board;
            game_board_copy.active_player = game_board.active_player;

            // Move
            game_board_copy.makeMove(empty_space.first, empty_space.second);

            // Score
            int score = game_board_copy.getBoardScore();
            if (score != 0) {
                return empty_space;
            }
            int foo = 123;
        }
    } else {
        best_score = numeric_limits<int>::min();
    }
}

pair<int, int> Player::getMove(int symbol, const Board &game_board) {

    pair<int, int> move;

    switch (player_type) {
        case Human:
            move = getMoveHuman();
            break;
        case RandomAI:
            move = getMoveRandomAI(game_board);
            break;
        case SmartAI:
            move = getMoveSmartAI(symbol, game_board);
            break;
        default:
            move.first = -1;
            move.second = -1;
    }

    return move;
}

