#include"railcipher.h"

//below variables are used for words counting inputted in line
#define IN 1
#define OUT 0

//sentences will get load here //below is dynamic 2D variable
static char** sentences[MAX_NUM_SENTENCES];

//totoal no of words of all text
static int nwordsArray[MAX_NUM_SENTENCES];

//returns last character of the line
char getLine(char* line, int maxLength)
{
	//checking if user enters end of file
	char lastCharacter;

	int i;

	printf("\nEnter the line to encrypt. if no line enter press Ctrl+Z\n");

	//taking input from user 
	for (i = 0; i < maxLength - 1 && (line[i] = getchar()) != '\n' && line[i] != EOF; i++);
	lastCharacter = line[i++];

	line[i] = '\0';//end of string sign
	return lastCharacter;
}

int wordCount(char* line)
{
	// if state is out it means there is space before current loop
	// if state is in it means it means word ie started in previous loops
	int state = OUT, i = 0, count = 0;

	//going through each line of inputed line to counts words entered in it using delimeter space
	while (line[i])
	{
		if (!isspace(line[i++]))//if no space
		{
			//If there is space before
			if (state == OUT)
			{
				count++;
				//if word is started
				state = IN;
			}
		}
		else
		{
			//if space is found
			state = OUT;
		}
	}

	return count; // returning total numbers of words the line have
}

//gives total number of columns i.e Key k
int getKeys(int* keys)
{
	int i = 0;
	char temp[MAX_COMMAND_TOKEN_LENGTH] = "";

	//getting keys from user as input

	printf("Enter the Keys string.\t\t i.e (3,5,2,1,0,4)\n");

	// checking if user enters the last character  is (
	if (getCommandWord(temp, MAX_COMMAND_TOKEN_LENGTH, "(") != '(')
	{
		return 0;
	}

	//checking is last char is )
	while (getCommandWord(temp, MAX_COMMAND_TOKEN_LENGTH, ",)") != ')')
	{
		if (i == MAX_KEY_LENGTH)
		{
			return  0;
		}
		else
		{
			keys[i++] = atoi(temp);
		}
	}

	//atoi converts the character arry to int variable
	keys[i++] = atoi(temp);

	return i;
}

//merge given line into sentences 
void tokenize(char* line, char** tokens)
{
	int i = 0;
	char* temp;

	//Strtok split string into series of words or token using a delimeter like comma //temp will pointer to the first char of the toke
	temp = strtok(line, " ");

	//Dynamic memory allocation of 2d array
	tokens[i] = (char*)malloc(strlen(temp) * sizeof(char));

	//copying addresses of line to token
	strcpy(tokens[i++], temp);


	//Null means to continue old temp
	while (temp = strtok(NULL, " "))
	{
		//copying each character to tokens variable to reutrn
		tokens[i] = (char*)malloc(strlen(temp) * sizeof(char));
		strcpy(tokens[i++], temp);
	}

	//deleting the dot and possibly a new line from the last token!
	if (tokens[i - 1][strlen(tokens[i - 1]) - 2] == '.')
	{
		tokens[i - 1][strlen(tokens[i - 1]) - 2] = '\0';
	}
	//if no dot is find termination of string
	else
	{
		tokens[i - 1][strlen(tokens[i - 1]) - 1] = '\0';
	}
}

//checking if user enters valid key ,, key is maximum number of columns of text
int isvalidkey(int* keys, int k)
{
	//keys will be permutation string of K variable 
	//Like (3,5,2,1,0,4) where k should be 5
	int i, * flag = (int*)malloc(k * sizeof(int));

	//setting flag to zero
	for (i = 0; i < k; i++)
	{
		flag[i] = 0;
	}

	//if no of keys is greater the Key value 
	for (i = 0; i < k; i++)
	{
		if (keys[i] >= k)
		{
			return 0;
		}
		else
		{
			flag[keys[i]] = 1;
		}
	}

	//if flag has no value
	for (i = 0; i < k; i++)
	{
		if (!flag[i])
		{
			return 0;
		}
	}

	return 1;
}

//driver our encryption code
void handleEncryption(void)
{
	//keys will get store here which will be the permutation of entered column number
	int keys[MAX_KEY_LENGTH];

	//temp varible is for temporary purposes //while line will hold our inputted line for encryption
	char temp, line[MAX_LINE_LENGTH];

	//loops and counting variables
	int i = 0, j, k, nwords, nlines, maxwords = -1;

	//Getting Column numbers: i.e if encryptionkey by user is (3,5,2,1,0,4) then k = 6
	k = getKeys(keys);

	//if user enter 0 or press enter key just after typing 'encrypt'
	if (getchar() != '\n' || k < 1)
	{
		printf("Error: syntax  of encryption command is not valid!\n");
		return;
	}

	//sending key string and number of keys member(column number) //Checking whether column number matches the keys string length
	if (!isvalidkey(keys, k))
	{
		printf("Error: invalid key! key of length %d must be a permutation of non-negative integers less than %d\n", k, k);
		return;
	}

	//taking input from user for encryption text
	i = 0;
	while (1)
	{
		//temp will hold the last character of our inputted text
		temp = getLine(line, MAX_LINE_LENGTH);

		//If user enter sentences more than limit 
		if (i == MAX_NUM_SENTENCES)
		{
			break;
		}

		//if user enters the Ctrl Z (^Z)
		if (temp == EOF)
		{
			break;
		}

		//counting words of inputted line
		nwords = wordCount(line);

		//if there is no words in command
		if (!nwords) // !(true if non-Zero) //if(nwords == 0)
		{
			i--;

			//if we give command to stop iput of encryption text
			if (temp == EOF)
			{
				break;
			}
			continue;
		}

		//if user enters text which does not meet the column requirement
		if (maxwords < nwords)
		{
			maxwords = nwords;
		}

		//storing our words of inout line in permanent variable of words
		nwordsArray[i] = nwords;

		//giving size to sentence variable of our inputed no of words size
		sentences[i] = (char**)malloc(nwords * sizeof(char*));

		//merging line to sentences
		tokenize(line, sentences[i++]);
	}

	// if user enters the wrong input according to inputted columns number
	nlines = i; //no of inputed lines... rows
	if (k < maxwords)
	{
		printf("Error: the given key is too short for this plaintext.\nThe minimum key length must be %d\n", maxwords);
		return;
	}

	//shwoing results of encryptiom 
	printf("\nEncryption Successful.... \nRemember the Key Value and Encryption Key\n\n");
	printf("\nThe encrypted text is:\n\n");

	//looping throuhg the sentence variable to encrypt it according to given key
	for (i = 0; i < k; i++)
	{
		for (j = 0; j < nlines; j++)
		{
			// printing encrypted text
			printf("%s ", (keys[i] < nwordsArray[j]) ? sentences[j][keys[i]] : "null");
		}
	}
	printf("\n");
}
