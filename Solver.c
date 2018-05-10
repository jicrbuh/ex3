#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int solveCell(int counter,int blockLength, int blockHeight, int** board, int** solvedBoard, int*** triedBoard, int direction,int det);
int* cellOptions(int row, int col, int blockLength, int blockHeight, int** board);
void copyBoardMinus(int blockLength,int blockHeight, int **origBoard, int **copyBoard);
int checkIfTriedAll(int* options, int*** triedBoard, int row, int col, int blockLength, int blockHeight);
void createInitMatrix3d(int blockLength,int blockHeight, int *tried, int **rows, int ***triedBoard);
int randomizedOption(int blockLength, int blockHeight,int* options);


int backtracking(int blockLength, int blockHeight, int** board, int** solvedBoard,int det){
	int counter=0;
	int direction=1;
	int dim = blockLength*blockHeight;
	int ***triedBoard = calloc(dim , sizeof(int **));
	int **rows = calloc(dim * dim , sizeof(int *));
	int *tried = calloc(dim * dim * dim , sizeof(int));
	createInitMatrix3d(blockLength, blockHeight, tried, rows, triedBoard);
	copyBoardMinus(blockLength, blockHeight, board,solvedBoard);
	while (counter<dim*dim) {
		printf("round1\n");
		if (solveCell(counter, blockLength,blockHeight, board, solvedBoard,triedBoard, direction,det) == -1) {
			printf("going back/n");
			int row=counter/dim;
			int col=counter%dim;
			solvedBoard[row][col] = 0;
			counter--;
			direction =0;
			if (counter<0) {
				printf("counter<0/n");
				return -1;
			}
		}
		else {
			counter++;
			direction =1;
		}
	}
	return 1;
}

int solveCell(int counter,int blockLength, int blockHeight, int** board, int** solvedBoard,int*** triedBoard, int direction, int det) {

	int dim = blockLength*blockHeight;
	int row=counter/dim;
	int col=counter%dim;
	int val = solvedBoard[row][col];
	int i;
	int *options;

	printf("row %d, col %d, val %d, counter %d, currVal %d\n",row,col,val,counter,val);
	options = cellOptions( row,  col,  blockLength,  blockHeight,  solvedBoard);
	//if val =5 we check all options greater than 5
	if (solvedBoard[row][col]<0){
		if(direction>0){
			return 1;
		}
		else{
			return -1;
		}
	}
	if (det == 1) {
		for (i=val+1;i<dim+1;i++) {
			if (options[i] == 0){
				printf("checking option %d\n",i);
				solvedBoard[row][col] = i;
				return 1;
			}
		}
	}
	else {
		if (checkIfTriedAll(options, triedBoard, row, col, blockLength, blockHeight)==1) {
			printf("tried all failed\n");
			return -1;
		}
		int try = randomizedOption(blockLength,blockHeight,options);
		printf("try = %d\n",try);
		while (triedBoard[row][col][try-1]==1) {
			printf("in loop\n");
			try = randomizedOption(blockLength,blockHeight,options);
		}
		solvedBoard[row][col] = try;
		triedBoard[row][col][try-1] = 1;
		return 1;
	}
	return -1;
}

int randomizedOption(int blockLength, int blockHeight,int* options){
	int i;
	int counter=0;
	int dim =blockLength*blockHeight;
	int random;
	for (i=1;i<dim+1;i++){
		if(options[i]==0){
			counter++;
		}
	}
	if (counter == 1) {
		for (i=1;i<dim+1;i++) {
			if (options[i]==0) {
				return i;
			}
		}
	}
	random = rand() % (counter);
	printf("random = %d\n",random);
	for (i=1;i<dim+1;i++) {
		if(options[i]==0) {
			if (random == 0) {
				return i;
			}
			random--;
		}
	}
printf("problem\n");
return -1;
}
// 1 - no available options
int checkIfTriedAll(int* options, int*** triedBoard, int row, int col, int blockLength, int blockHeight) {
	int i;
	int dim = blockLength*blockHeight;
	for (i=0 ; i<dim ; i++) {
		if (options[i+1] != triedBoard[row][col][i]) {
			return 0;
		}
	}
	return 1;
}
