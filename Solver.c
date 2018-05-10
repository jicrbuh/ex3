#include <stdio.h>
#include <time.h>
int solveCell(int counter,int blockLength, int blockHeight, int** board, int** solvedBoard, int direction);
int* cellOptions(int row, int col, int blockLength, int blockHeight, int** board);
void copyBoardMinus(int blockLength,int blockHeight, int **origBoard, int **copyBoard);
int checkIfTriedAll(int* options, int*** triedBoard, int row, int col, blockLength, blockHeight);


int backtracking(int blockLength, int blockHeight, int** board, int** solvedBoard,int det){
	int counter=0;
	int direction=1;
	int dim = blockLength*blockHeight;
	int *tried;
	int **triedRows;
	int ***triedBoard;
	triedBoard = calloc(dim*dim*dim,sizeof(int));
	triedRows = calloc(dim*dim, sizeof(int*));
	tried = calloc(dim, sizeof(int**));
	createInitMatrix3d(blockLength,blockHeight, triedRows, triedBoard,tried);
	copyBoardMinus(blockLength, blockHeight, board,solvedBoard);
	while (counter<dim*dim) {
		if (solveCell(counter, blockLength,blockHeight, board, solvedBoard,direction,det) == -1) {
			int row=counter/dim;
			int col=counter%dim;
			solvedBoard[row][col] = 0;
			counter--;
			direction =0;
			if (counter<0) {
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

int solveCell(int counter,int blockLength, int blockHeight, int** board, int** solvedBoard, int*** triedBoard, int direction, int det) {

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
			return -1;
		}
		int try = randomizedOption(blockLength,blockHeight,options);
		while (triedBoard[row][col][try-1]==1) {
			try = randomizedOption(blockLength,blockHeight,options);
		}
		solvedBoard[row][col] = try;
		triedBoard[row][col][try-1] = 1;
	}
	return -1;
}

int randomizedOption(int blockLength, int blockHeight,int* options){
	int i;
	int counter=0;
	int dim =blockLength*blockHeight;
	int random;
	for (i=1;i<dim+1;i++){
		if(options[i]==1){
			counter++;
		}
	}
	if (counter == 1) {
		for (i=1;i<dim+1;i++) {
			if (options[i]==1) {
				return i;
			}
		}
	}
	random = rand() % counter;
	for (i=1;i<dim+1;i++) {
		if(options[i]==1) {
			random--;
			if (random == 0) {
				return i;
			}

		}
	}
}
// 1 - no available options
int checkIfTriedAll(int* options, int*** triedBoard, int row, int col, blockLength, blockHeight) {
	int i;
	int dim = blockLength*blockHeight;
	for (i=0 ; i<dim ; i++) {
		if (options[i] != triedBoard[row][col][i]) {
			return 0;
		}
	}
	return 1;
}
