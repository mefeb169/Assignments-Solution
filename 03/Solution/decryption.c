#include"railcipher.h"

#define IN 1
#define OUT 0

static char** colmnSentence[MAX_NUM_SENTENCES];

//merges the inputted decrypted text to variable colmnSentence
void tokenizeEncryptedText(char* line, char** tokens)
{
	int i = 0;
	char* temp;

	//Strtok split string into series of words or token using a delimeter like comma
	temp = strtok(line, " "); //temp is a pointer to first character of line

	//Dynamic memory allocation
	tokens[i] = (char*)malloc(strlen(temp) * sizeof(char));

	//copying temp to token 
	strcpy(tokens[i++], temp);

	//Null means to continue old temp
	while (temp = strtok(NULL, " "))
	{
		tokens[i] = (char*)malloc(strlen(temp) * sizeof(char)); //giving memory to token variable according to the size of temp
		strcpy(tokens[i++], temp);
	}
}

//the function separate the given text to column according to values of total words  no of columns which is K and line to decrypt
void separateColumns(int noOfWordsInTotal, int noOfColumns, char* line)
{
	//finding no of rows in each column
	int noOfRows = noOfWordsInTotal / noOfColumns;

	//variable for loop
	int starti = 0, endi = 0, spccount = noOfRows, spcNo = 0, l = 0, k = 0;

	//going through the whole decrypted text
	for (int i = 0; i < strlen(line); i++)
	{
		//column temp line
		char tempLine[MAX_LINE_LENGTH * 2];

		//using previous location of word to get next line
		starti = endi;

		//if there is space
		if (line[i] == ' ')
		{
			spcNo++; //increasing space no
		}

		// if space no matches the no of rows for wach column
		if (spcNo == spccount)
		{
			// last location of temp column sentence
			endi = i;

			//going through no of n spaces
			for (int j = starti; j < endi; j++)
			{
				//storing data to templine from Line given as parameter
				tempLine[k] = line[j];
				tempLine[k + 1] = '\0'; //terminating string
				k++;
			}
			
			//allocation of memory to colmnSentence of the size of noOfRows
			colmnSentence[l] = (char**)malloc(noOfRows * sizeof(char*),MAX_NUM_SENTENCES);

			//merginig Encrypted text to colmn sentence //colmnStence is a dynamic 2d variable to store our drawn table
			tokenizeEncryptedText(tempLine, colmnSentence[l++]);

			//resetting variables
			spcNo = 0;
			k = 0;
		}
	}
}

//prints decrypted text
void printResults(int* DecKey, int noOfColmns, int totalWords)
{
	//dec key is the list of correct sequence of columns 
	//like if encryption key is (3,5,2,1,0,4) then decryption key will be (4,3,2,0,5,1)

	//printing decrypted text
	printf("\n\nDecryption Successful:\n\n");
	printf("\n\nThe decrypted text is:\n\n");

	//Loop variables
	int i = 0, j = 0;

	//Looping through no of rows
	for (i = 0; i < totalWords / noOfColmns; i++)
	{
		//going through no of column
		for (j = 0; j <= noOfColmns; j++)
		{
			//if last words then put Dot at end as it will be the last word
			if (j == noOfColmns)
			{
				printf(".");
				printf("\n");
				break;
			}		

			//variable to compare the null from colmnsentence variable 
			char nullChar[200] = { 'n', 'u', 'l', 'l' ,'\0'};

			//comparing strings
			int value = strcmp(colmnSentence[DecKey[j]][i], nullChar);

			// if null value is find ignore it and put dot as it will be the last word of that row
			if(value == 0)
			{
				printf(".");
				printf("\n");
				break;
			}

			// if lies between the number of columns and greater than zero
			// printing space after each words
			if (j > 0 && j < noOfColmns)
			{
				if (j + 1 <= noOfColmns)
				{
					printf(" ");
				}
			}

			//printing decrypted text
			printf("%s", colmnSentence[DecKey[j]][i]);
		}
	}
	printf("\n\n\n\n");
}

//returns last character of the line
char getDecryptedLine(char* line, int maxLength)
{
	//checking if user enters end of file
	char lastCharacter;

	int i;


	//taking input from user 
	printf("\nEnter the line to decrypt. NOTE: Enter all the text only in one time\n\n");
	for (i = 0; i < maxLength - 1 && (line[i] = getchar()) != '\n' && line[i] != EOF; i++);

	line[i++] = ' ';//end of string sign

	lastCharacter = line[i]; //last char of our keys string

	line[i] = '\0';//end of string sign

	return lastCharacter; //returning last char
}

//driver of Decryption Process
void handleDecryption(void)
{
	//variable to store keys string like (3,5,2,1,0,4)
	int keys[MAX_KEY_LENGTH];

	char temp, line[MAX_LINE_LENGTH]; //line is the all the encrypted text
	int i = 0, j, k, nwords, nlines, maxwords = -1;

	//taking keys string as input
	k = getKeys(keys);

	// if entered string is not enter and less than K eg 6 according to assignment
	if (getchar() != '\n' || k < 1)
	{
		printf("Error: syntax  of Decryption command is not valid!\n");
		return;
	}

	//checking whether entered key string is valid or not
	if (!isvalidkey(keys, k))
	{
		printf("Error: invalid key! key of length %d must be a permutation of non-negative integers less than %d\n", k, k);
		return;
	}


	i = 0;
	while (1)
	{

		//getting last character of inputted line
		temp = getDecryptedLine(line, MAX_LINE_LENGTH); //getting decrypted text (all in once)

		//checking if last character is end of file
		if (temp == EOF)
		{
			break;
		}

		//counting words of cipher text 
		nwords = wordCount(line);

		//if words are zero
		if (!nwords) // !(true if non-Zero) //if(nwords == 0)
		{
			i--;
			if (temp == EOF)
			{
				break;
			}
			continue;
		}

		separateColumns(nwords, k, &line); //separating columns of the given encrypted text accoring to the K value and Key string value
		break;
	}

	//finding decryption key for decrypted text based on input encryption key
	int decKey[100];

	//finding decretypted key to decrypt text
	for (int i = 0; i < k; i++)
	{
		for (int j = 0; j < k; j++)
		{
			if (keys[j] == i)
			{
				decKey[i] = j;
			}
		}
	}

	//printing decrypted text
	printResults(decKey, k, nwords);

}
