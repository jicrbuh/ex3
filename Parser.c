#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*inserts the tokens for hint and set to the command array*/
void insertsTokens(int i, int j, char token[], int command[]) {
	while( i<j ) {
		token = strtok(NULL, " \t\r\n");
		if (token != NULL){
			if (strcmp(token,"0") == 0) {
				command[i] =0;
			}
			else if (atoi(token) != 0) {
				command[i] = atoi(token);
			}
			else {
				command[0] = -1;
			}
		}
		//if token == null command is invalid
		else {
			command[0]=-1;
		}
		i++;
	}
}
/* return the corresponding integer of the first token according to the map:
 * 0 set
 * 1 hint
 * 2 validate
 * 3 restart
 * 4 exit
 * -1 invalid
 * -2 empty or only white space
 * */
int findFirstToken(char userCommmand[]) {
	if (strcmp(userCommmand,"exit") == 0) {
			return 4;
	}
	if (strcmp(userCommmand,"restart") == 0) {
				return 3;
		}
	if (strcmp(userCommmand,"validate") == 0) {
				return 2;
		}
	if (strcmp(userCommmand,"hint") == 0) {
					return 1;
			}
	if (strcmp(userCommmand,"set") == 0) {
						return 0;
				}
	return -1;
}




//set x y z, hint x,y, validate, restart, exit, couldn't parse
void parseString(int* parsedCommand, char userInput[]) {
	if (strspn(userInput, " \r\n\t") == strlen(userInput)) {
		parsedCommand[0] = -2;
		return;
	}
	char *token;
	int i=1;
	char str[20] = "";
	strcpy(str,userInput);
	token = strtok(str," \t\r\n");
	parsedCommand[0]=findFirstToken(token);
	//set
	if (parsedCommand[0]== 0 ) {
		insertsTokens(i,4,token,parsedCommand);
	}
	if (parsedCommand[0]== 1 ) {
		insertsTokens(i,3,token,parsedCommand);
	}
}



