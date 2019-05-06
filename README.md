# tic-tac-toe

## How to Run
This project uses CMake. After cloning the repository, run `$ cmake .` followed by `$ make` in the project directory to 
compile the project.

tic-tac-toe takes two command line arguments for Player 1 type and Player 2 type:  
0: Human  
1: Random AI  
2: Smart AI 

This project supports human vs human games via `$ ./tic-tac-toe 0 0`, human vs AI games 
(e.g. `$ ./tic-tac-toe 0 1`), or AI vs AI games (e.g. `$ ./tic-tac-toe 1 2`).

## Project Structure
* CMakeLists.txt: CMake configuration script
* README.md: instructions for running and project description
* main.cpp: parses command line arguments and runs main loop
* common.h: contains constants and Enums
* board.cpp/.h: contains Board class that encapsulates all functionality dealing with creating, updating, and displaying
the board, as well as checking for end game conditions
* player.cpp/.h: contains Player class that chooses moves for each player types (note, if more AI players
are implemented and player.cpp becomes bloated, each player could be broken out into a separate class that inherits
from a base Player class):
    * Human: gets user input
    * Random AI: chooses random move from all available moves
    * Smart AI: tries to win, block opponent, and move to the best locations


## Possible Future Work: implementing more intelligent AIs
* Minimax AI: the [minimax algorithm](https://en.wikipedia.org/wiki/Minimax) is used in perfect information games 
like tic tac toe to determine the best move by recursively building a search tree that scores the move based on the 
possible outcomes. Since tic tac toe has a relatively shallow search tree, minimax could be run exhaustively for each 
player turn to find the best possible move
* AlphaTicTacToe AI: Although extreme overkill for this task, an interesting exercise would be to apply deep 
reinforcement learning to build a player similar to DeepMinds's 
[AlphaZero](https://science.sciencemag.org/content/362/6419/1140.full?ijkey=XGd77kI6W4rSc&keytype=ref&siteid=sci) work 
 