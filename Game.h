/*
 * Game.h
 *
 *  Created on: 10 May 2018
 *      Author: chen
 */

#ifndef GAME_H_
#define GAME_H_

int* leftTopCornerOfBlock(int row, int col, int blockLength, int blockHeight);
int* cellOptions(int row, int col, int blockLength, int blockHeight, int** board);
int set(int row, int col, int blockLength, int blockHeight, int** board, int val);


#endif /* GAME_H_ */
