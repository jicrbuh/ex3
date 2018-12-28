# SW project exercise 3


In this assignment, we implement the Sudoku puzzle game.
Sudoku is a number-placement puzzle where the objective is to fill a 9x9 grid with digits so
that each column, each row, and each 3x3 block contains all digits from 1 to 9. 


This is a command-line program which consists of two parts; initialization and the game itself. It
receives one command-line parameter "seed", for the randomized creation of the board.
<br />  
To generate the board, we first solve the board, using a
[backtracking algorithm](https://en.wikipedia.org/wiki/Backtracking). This algorithm attempts to solve a Sudoku board by filling in its
empty cells.  Two variants of
the backtracking algorithm are used, randomized and deterministic.
  
In each turn, the user can initialize a new game, try to add a number to the board, or ask for a hint.
