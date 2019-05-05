#include <iostream>
#include "board.h"
#include "player.h"

using namespace std;

int main(int argc, char** argv) {

    // Parse player type arguments
    if (argc < 3) {
        cout << "\ntick-tack-toe takes two command line arguments for Player 1 type and Player 2 type:" << endl;
        cout << "0: Human" << endl << "1: Random AI" << endl << "2: Smart AI" << endl;
        return 1;
    } else {
        bool valid_player1_type = !strcmp(argv[1], "0") || !strcmp(argv[1], "1") || !strcmp(argv[1], "2");
        bool valid_player2_type = !strcmp(argv[2], "0") || !strcmp(argv[2], "1") || !strcmp(argv[2], "2");
        if (!valid_player1_type || !valid_player2_type) {
            cout << "\nInvalid command line arguments" << endl;
            cout << "tick-tack-toe takes two command line arguments for Player 1 type and Player 2 type:" << endl;
            cout << "0: Human" << endl << "1: Random AI" << endl << "2: Smart AI" << endl;
            return 1;
        }
    }
    int player1_type = stoi(argv[1]);
    int player2_type = stoi(argv[2]);

    // Initialize board and players
    Board game_board;
    Player player1(player1_type);
    Player player2(player2_type);

    // Get player moves until game ends
    pair<int, int> move;
    game_board.displayBoard();
    while (true) {

        // Get player move
        if (game_board.active_player == 1) {
            cout << "\nPlayer 1: " << endl;
            move = player1.getMove(X, game_board.board);
        } else {
            cout << "\nPlayer 2: " << endl;
            move = player2.getMove(X, game_board.board);
        }

        // Check if move is valid
        if (!game_board.checkIfValidMove(move.first, move.second)) {
            cout << "Row and Column must be between 0 and 2" << endl;
        } else if (!game_board.checkIfEmptySpace(move.first, move.second)) {
            cout << "Space already occupied" << endl;
        } else {

            // Perform move and check if player won
            bool is_winning_move = game_board.makeMove(move.first, move.second);
            if (is_winning_move) {
                cout << "\nPlayer " << (game_board.active_player == 1 ? "1 " : "2 ") << "won the game!" << endl;
                game_board.displayBoard();
                break;
            }

            // Check if tie game
            bool is_tie_game = game_board.checkIfTieGame();
            if (is_tie_game) {
                cout << "\nTie game..." << endl;
                game_board.displayBoard();
                break;
            }
        }

        // Display board on CLI
        game_board.displayBoard();
    }

    return 0;
}