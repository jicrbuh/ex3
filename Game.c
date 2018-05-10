#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*returns the options for the cell*/

int* leftTopCornerOfBlock(int row, int col, int blockLength, int blockHeight) {
	int *indices = calloc(2,sizeof(int));
	indices[0] = (row/blockHeight)*blockHeight;
	indices[1] = (col/blockLength)*blockLength;
	return indices;
}
//only use when cell is empty (board[row][col]==0)
int* cellOptions(int row, int col, int blockLength, int blockHeight, int** board) {
	//options array will have (at return time) value 0 if valid
	int *options = calloc(blockLength*blockHeight+1, sizeof(int)); //first cell stays empty;
	int i=0;
	int j;
	int *indices = leftTopCornerOfBlock(row,col,blockLength,blockHeight);

	for (i=0 ; i<blockLength*blockHeight ; i++) { //initialize array to zeros
		options[i] = 0;
	}
	for (i=0 ; i<blockLength*blockHeight ; i++) { //iterates over the row and column and updates the options array
		options[abs(board[row][i])] = 1;
		options[abs(board[i][col])] = 1;
	}
	for (i=0 ; i<blockLength ; i++) {
		for(j=0; j<blockHeight;j++){
			options[abs(board[indices[0]+i][indices[1]+j])] = 1;
		}

	}
	return options;
}



int set(int row, int col, int blockLength, int blockHeight, int** board, int val) {
	if (board[row][col] < 0) {
		return -1;
	}
	if (cellOptions(row, col, blockLength, blockHeight, board)[val] == 0) { //val is in cellOptions
		board[row][col] = val;
	}
	else {
		return -2;
	}
	return 0;
}
