# tic-tac-toe

## How to Run
This project uses CMake. After cloning the repository,
run `$ cmake .` followed by `$ make` in project directory to compile the project.

tic-tac-toe takes two command line arguments for Player 1 type and Player 2 type:  
0: Human  
1: Random AI  
2: Smart AI 

Therefore this project supports human vs human via `$ ./tic-tac-toe 0 0`, human vs AI 
(e.g. `$ ./tic-tac-toe 0 1`), or AI vs AI (e.g. `$ ./tic-tac-toe 1 2`).

## Project Structure
* CMakeLists.txt: CMake script
* README.md: instructions for running program and project description
* main.cpp: parses command line arguments and runs main loop
* common.h: contains definitions of constants and Enums
* board.cpp/.h: contains Board class that encapsulates all functionality dealing with creating, updating, and displaying
the board, as well as checking for end game conditions
* player.cpp/.h: contains Player class that encapsulates all functionality dealing with choosing moves for all three
player types:
    * Human: gets user input
    * Random AI: chooses random move from all available moves
    * Smart AI: tries to win, block opponent, and move to the best locations


## Possible Future Work -- more intelligent AI
This work could be extended to include better AIs:
* Minimax AI: the [minimax algorithm](https://en.wikipedia.org/wiki/Minimax) is used in perfect information games 
like tic tac toe to determine the best move by recursively building a search tree to score that move based on the 
possible outcomes. Since tic tac toe has a relatively shallow search tree, minimax could be run completely run at each 
player turn to find the best possible move
* AlphaTicTacToe AI: Although extreme overkill for this task, an interesting exercise would be to apply deep 
reinforcement learning to build a player similar to DeepMinds's 
[AlphaZero](https://science.sciencemag.org/content/362/6419/1140.full?ijkey=XGd77kI6W4rSc&keytype=ref&siteid=sci) work 
 