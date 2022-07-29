#include"railcipher.h"

//our program will start from below and finally return to it after completion
int main(void) 
{
	// We will geet command text from user in below variable
	char command[MAX_COMMAND_TOKEN_LENGTH];//placeholder for a command...
	char lastCharacter; //last char of our command i.e key or column no


	// Reception
	printf("Welcome to RailCipher Encrypter and Decrypter\n\n");

	printf("**********************************************\n");
	printf("Command: encrypt no of maximum columns\t\t Example: encrypt 5\n");
	printf("Command: decrypt no of maximum columns\t\t Example: decrypt 5\n");
	printf("Command: quit to exit the console\n");
	printf("**********************************************\n\n");
	
	// Input Command
	printf("Enter the Command! ");

	//taking input and finding last chaacter of input command
	lastCharacter = getCommandWord(command, MAX_COMMAND_TOKEN_LENGTH, " ");

	//if user enter quit command
	if (!strcmp(command, "quit"))
	{
		return 0;
	}

	//if user enter encryption command
	else if (!strcmp(command, "encrypt"))
	{
		if (lastCharacter == '\n')
		{
			//if user does not give Key no of encryption or decryption
			//key is no of maximum columns or no of words in one row
			printf("Key is missing for encrypt command!.\n");
		}

		else 
		{
			//if user enter encryption command
			handleEncryption();
		}
	}

	// if user enters decryption command
	else if (!strcmp(command, "decrypt"))
	{
		if (lastCharacter == '\n')
		{
			//if user does not give Key no of encryption or decryption
			//key is no of maximum columns or no of words in one row
			printf("Key is missing for decrypt command!\n");
		}
		else
		{
			// if user enters decryption command
			handleDecryption();
		}
	}

	//nothing matches command credentials
	else
		printf("Invalid command!\n");

	return 0;
}

//getting command from user
char getCommandWord(char command[], int maxLength, char* delimiter) 
{

	char c;
	int i = 0, j, n = strlen(delimiter);

	//if user enters nothing and just press enter or enter white spaces
	while (isspace(c = getchar()));//skip leading white spaces

	//if user is in given limits
	//not exceeding than maximum credentials
	while (i < maxLength - 1 && c != EOF) 
	{
		j = -1;

		//search untill find delimeter //delimeter is a separator like space or colon
		while (delimiter[++j] && delimiter[j] != c);

		//if no delimeter is found
		if (j != n)
		{
			break;
		}

		//if space is foung
		if (isspace(c))
		{
			break;
		}

		//if command is ok
		else 
		{
			//entering text to our command variable
			command[i++] = c;

			//get char reads a single character from console
			c = getchar();
		}
	}

	//terminating array
	command[i] = '\0'; //end of string sign //compiler reads /0 as null and consider it as termination

	//if no space is found
	if (!isspace(c))
	{
		return c;
	}

	//always run for demimeters character
	while (*delimiter)
	{
		//if user enter space as delimeter
		if (isspace(*(delimiter++)))
		{
			return c;
		}
	}

	//ignoring white spaces
	while (isspace(c))//skip trailing white spaces
	{
		c = getchar();
	}

	return c; //returning last character of command
}
