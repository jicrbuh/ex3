#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "SPBufferset.h"
#include "Parser.h"
#include "Solver.h"
#include "Game.h"
#include "MainAux.h"

#include <time.h>
#define BLOCK_HEIGHT 3
#define BLOCK_LENGTH 3
#define SEED 3//change!!
//check git
//void parseString(int* parsedCommand, char userInput[]);
//int findFirstToken(char userCommmand[]);
void printBoard(int **board,int blockLength,int blockHeight);
int set(int row, int col, int blockLength, int blockHeight, int** board, int val);
void createInitMatrix(int blockLength,int blockHeight, int *rows, int **board);
int backtracking(int blockLength, int blockHeight, int** board, int** solvedBoard,int det);
int main() {
	int dim = BLOCK_HEIGHT*BLOCK_LENGTH;
		int *rows;
		int **board;
		int **solvedBoard;
		int *solvedRows;

		SP_BUFF_SET();
		srand(SEED);
		rows = calloc(dim*dim,sizeof(int));
		board = calloc(dim, sizeof(int*));
		solvedRows = calloc(dim*dim,sizeof(int));
		solvedBoard = calloc(dim, sizeof(int*));
		int i=0;
		for (i=0 ; i<dim ; i++) {
			board[i] = rows + i*dim;
		}
		int j=0;
		for (i=0 ; i<dim ; i++) {
			for (j=0 ; j<dim ; j++) {
				board[i][j] = 0;
			}
		}
		createInitMatrix( BLOCK_LENGTH, BLOCK_HEIGHT,solvedRows,solvedBoard);

		board[0][0]=-1;
		//set(0,0,3,3,board,-1);
		board[0][1]=-2;
		//set(0,1,3,3,board,2);
		set(0,2,3,3,board,3);
		printf("%d\n",set(1,0,3,3,board,1));
		printf("%d\n",set(1,0,3,3,board,4));

		printf("backtracking: %d\n",backtracking( BLOCK_LENGTH,  BLOCK_HEIGHT,board,solvedBoard,1));
		printBoard(board,3,3);
		printBoard(solvedBoard,3,3);
		free(solvedBoard);
		free(board);
		//int parsedCommand[6];
		return 0;
}
