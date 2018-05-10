#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "SPBufferset.h"


void printDashes(int numberOfTimes) {
	int i;
	for (i=0;i<numberOfTimes;i++) {
			printf("-");
		}
	printf("\n");
}
void printBoard(int **board,int blockLength,int blockHeight) {
	int dashLength = blockHeight*(2+3*blockLength) + 1;
	int i=0;
	int j;
	int k;
	SP_BUFF_SET();
	printDashes(dashLength);
	for (i=0 ; i<blockLength; i++) {
		for (j=0 ; j<blockHeight ; j++) {
			printf("|");
			for (k=0 ; k<blockHeight*blockLength ; k++) {
				if(board[j+3*i][k] < 0) {
					printf(" .%d",-board[j+blockHeight*i][k]);
				}
				else if(board[j+3*i][k] == 0) {
					printf("   ");
				}
				else {
					printf("  %d",board[j+blockHeight*i][k]);
				}
				if ((k+1)%blockLength == 0) {
					printf(" |");
				}
			}
			printf("\n");
		}
		printDashes(dashLength);
	}
}

void createInitMatrix(int blockLength,int blockHeight, int *rows, int **board) {
	int dim = blockLength*blockHeight;
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

}
//stores the previous random tries: board[i][j][k] = 1 if k+1 was previously tried.
void createInitMatrix3d(int blockLength,int blockHeight, int **rows, int ***board, int *tried) {
	int dim = blockLength*blockHeight;
	int i=0;
	int k=0;
	for (i=0 ; i<dim ; i++) {
		board[i] = rows + i*dim;
		for (k=0 ; k<dim ; k++) {
			rows[k] = tried + k*dim;
		}
	}
	int j=0;
	for (i=0 ; i<dim ; i++) {
		for (j=0 ; j<dim ; j++) {
			for (k=0 ; k<dim ; k++) {
				board[i][j][k] = 0;
			}
		}
	}

}

void copyBoardMinus(int blockLength,int blockHeight, int **origBoard, int **copyBoard){
	int dim = blockLength*blockHeight;
	int i=0;
	int j=0;
		for (i=0 ; i<dim ; i++) {
			for (j=0 ; j<dim ; j++) {
				if (origBoard[i][j]<0){
					copyBoard[i][j] = origBoard[i][j];
				}
				else {
					copyBoard[i][j] = -origBoard[i][j];
				}

			}
		}
}
