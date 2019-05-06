# tic-tac-toe

## How to Run
Clone this repository
This project uses CMake. After cloning the repository, simply
run `$ cmake .` followed by `$ make` in project directory.

tic-tac-toe takes two command line arguments for Player 1 type and Player 2 type:  
0: Human  
1: Random AI  
2: Smart AI 

For example, to run human vs human tic-tac-toe, execute `$ ./tic-tac-toe 0 0`

## Project Structure
This project has 6 code files:
* main.cpp: parses command line arguments and runs main loop of program
* common.h: contains definitions of constants and Enums
* board.cpp/.h: contains Board class
* player.cpp/.h: contains Player class


## Future Work
more intelligent AI -- minimax and AlphaTicTacToe  
Make different Player classes with inheritance   