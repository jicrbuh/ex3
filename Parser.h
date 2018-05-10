/*
 * Parser.h
 *
 *  Created on: 10 May 2018
 *      Author: chen
 */

#ifndef PARSER_H_
#define PARSER_H_

void insertsTokens(int i, int j, char token[], int command[]);
int findFirstToken(char userCommmand[]);
void parseString(int* parsedCommand, char userInput[]);


#endif /* PARSER_H_ */
