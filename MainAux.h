/*
 * MainAux.h
 *
 *  Created on: 10 May 2018
 *      Author: chen
 */

#ifndef MAINAUX_H_
#define MAINAUX_H_

void printDashes(int numberOfTimes);
void printBoard(int **board,int blockLength,int blockHeight);
void createInitMatrix(int blockLength,int blockHeight, int *rows, int **board);
void createInitMatrix3d(int blockLength,int blockHeight, int **rows, int ***board, int *tried);
void copyBoardMinus(int blockLength,int blockHeight, int **origBoard, int **copyBoard);



#endif /* MAINAUX_H_ */
