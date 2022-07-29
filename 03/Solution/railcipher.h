#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define MAX_NUM_SENTENCES 5000				//representing no of maximum sentences
#define MAX_COMMAND_TOKEN_LENGTH 25			//maximum no of command characters
#define MAX_KEY_LENGTH 100					//maximum no of entered number of columns
#define MAX_LINE_LENGTH 2500				//maximum length of inputted line for encryption

char getCommandWord(char command[], int maxLength, char* delimiter);
void handleEncryption(void);
void handleDecryption(void);
void handleDecryption(void);
