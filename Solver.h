/*
 * Solver.h
 *
 *  Created on: 10 May 2018
 *      Author: chen
 */

#ifndef SOLVER_H_
#define SOLVER_H_

int backtracking(int blockLength, int blockHeight, int** board, int** solvedBoard,int det);
int solveCell(int counter,int blockLength, int blockHeight, int** board, int** solvedBoard,int*** triedBoard, int direction, int det);
int randomizedOption(int blockLength, int blockHeight,int* options);
int checkIfTriedAll(int* options, int*** triedBoard, int row, int col,int blockLength,int blockHeight);


#endif /* SOLVER_H_ */
