#include "common.h"
#include "board.h"
#include "player.h"

int main(int argc, char** argv) {

    // Parse command line arguments
    if (argc < 3) {
        cout << "tic-tac-toe takes two command line arguments for Player 1 type and Player 2 type:" << endl;
        cout << "0: Human" << endl << "1: Random AI" << endl << "2: Smart AI" << endl;
        return 1;
    } else {
        bool valid_player1_type = !strcmp(argv[1], "0") || !strcmp(argv[1], "1") || !strcmp(argv[1], "2");
        bool valid_player2_type = !strcmp(argv[2], "0") || !strcmp(argv[2], "1") || !strcmp(argv[2], "2");
        if (!valid_player1_type || !valid_player2_type) {
            cout << "Error: Invalid command line arguments" << endl;
            cout << "tic-tac-toe takes two command line arguments for Player 1 type and Player 2 type:" << endl;
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

    // Main game loop
    pair<int, int> move;
    while (true) {

        // Get player move
        if (game_board.active_player == 1) {
            cout << "Player 1 (X): " << endl;
            move = player1.getMove(X, game_board.board);
        } else {
            cout << "Player 2 (O): " << endl;
            move = player2.getMove(O, game_board.board);
        }

        // Check if move is valid
        if (move.first < 0 || move.first >= grid_size || move.second < 0 || move.second >= grid_size) {
            cout << "Error: row and Column must be between 0 and 2" << endl;
        } else if (!game_board.checkIfEmptySpace(move.first, move.second)) {
            cout << "Error: space already occupied" << endl;
        } else {

            // Perform and display move
            game_board.makeMove(move.first, move.second);
            game_board.displayBoard();

            // Check if player won
            if (game_board.checkIfWinningBoard()) {
                cout << "Player " << (game_board.active_player == 1 ? "1 " : "2 ") << "won the game!" << endl;
                break;
            }

            // Check if tie game
            if (game_board.checkIfTieGame()) {
                cout << "Tie game..." << endl;
                break;
            }

            // Switch player
            game_board.switchActivePlayer();
        }
    }

    return 0;
}
