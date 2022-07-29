#ifndef COUNT_H_INCLUDED
#define COUNT_H_INCLUDED
/* charcount.h - This header file include type definitions (including function prototypes) and macros 
   used for the programing assignment zero.
*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h> 
#include <errno.h>
#include "dirent.h"
#include <string.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>

#define ALPHABETSIZE 52     //The total number of alphabetical letter from A - Z and a - z(case sensitive)
#define SPECIALSIZE 5   // The total number of these special words: he, she, they, him, me 

void alphabetlettercount(char *path, char *filetowrite, long alphabetfreq[])
{
	
	int i;
	DIR* d = opendir(path);
	struct dirent* dir;
	FILE* fptr, *ofptr;
	char c;


	if (d)
	{
		while ((dir = readdir(d)) != NULL)
		{
			char tempPath[100];

			strcpy(tempPath, path);
			strcat(tempPath, dir->d_name);

			fptr = fopen(tempPath, "r");

			if (strcmp(dir->d_name, ".") == 0 || strcmp(dir->d_name, "..") == 0)
			{
				strcpy(tempPath, "");
				continue;
			}

			if (fptr != NULL)
			{
				//loop through file to find char frequency
				while ((c = getc(fptr)) != EOF)
				{
					if (c >= 65 && c <= 90)
					{
						//capital letter
						alphabetfreq[c - 'A'] += 1;
					}

					else if (c >= 97 && c <= 122)
					{
						//smal letter
						alphabetfreq[c - 71] += 1;
					}
				}
				fclose(fptr);

				strcpy(tempPath, "");
			}
		}
		closedir(d);
	}

	//write data to output file 
	ofptr = fopen(filetowrite, "w+");

	if (ofptr == NULL) 
	{
		printf("Can't open output file.");
		exit(0);
	}

	for ( i = 0; i < 52; i++)
	{
		if (i <= 25)
		{
			//printf("%c %d\n", i + 65, alphabetfreq[i]);
			fprintf(ofptr, "%c -> %d\n", i + 65, alphabetfreq[i]);
		}

		else if (i > 25)
		{
			//printf("%c %d\n", i + 71, alphabetfreq[i]);
			fprintf(ofptr, "%c -> %d\n", i + 71, alphabetfreq[i]);
		}
	}
}
/**
  The alphabetlettercount function counts the frequency of each alphabet letter (A-Z a-z, case sensitive) in all the .txt files under
  directory of the given path and write the results to a file named as filetowrite.
  
  Input: 
      path - a pointer to a char string [a character array] specifying the path of the directory; and
      filetowrite - a pointer to a char string [a character array] specifying the file where results should be written in.
      alphabetfreq - a pointer to a long array storing the frequency of each alphabet letter from A-Z a - z:
      alphabetfreq[0]: the frequency of 'A'
      alphabetfreq[1]: the frequency of 'B'
         ... ...
      alphabetfreq[25]:the frequency of 'Z'
      alphabetfreq[26]:the frequency of 'a'
         ... ...
      alphabetfreq[51]:the frequency of 'z'

  
  Output: a new file named as filetowrite with the frequency of each alphabet letter written in
 
*/

void specialcount(char *path, char *filetowrite,  long charfreq[])
{
		DIR* d = opendir(path);
	struct dirent* dir;
	FILE* fptr, * ofptr;
	char c;
	char* read = _strdup("");

	if (d)
	{
		while ((dir = readdir(d)) != NULL)
		{
			char tempPath[100];

			strcpy(tempPath, path);
			strcat(tempPath, dir->d_name);

			fptr = fopen(tempPath, "r");

			if (strcmp(dir->d_name, ".") == 0 || strcmp(dir->d_name, "..") == 0)
			{
				strcpy(tempPath, "");
				continue;
			}

			if (fptr != NULL)
			{
				//loop through file to find char frequency
				while (!feof(fptr))
				{
					fscanf(fptr, "%s", read);

					if (_stricmp(read, "he") == 0)
					{
						//storing to array 0
						charfreq[0] += 1;
					}

					else if (_stricmp(read, "she") == 0)
					{
						//storing to array 1
						charfreq[1] += 1;
					}

					else if (_stricmp(read, "they") == 0)
					{
						//storing to array 2
						charfreq[2] += 1;
					}

					else if (_stricmp(read, "him") == 0)
					{
						//storing to array 3
						charfreq[3] += 1;
					}

					else if (_stricmp(read, "me") == 0)
					{
						//storing to array 4
						charfreq[4] += 1;
					}
				}
				fclose(fptr);

				strcpy(tempPath, "");
			}
		}
		closedir(d);
	}

	//write data to output file 
	ofptr = fopen(filetowrite, "w+");

	if (ofptr == NULL)
	{
		printf("Can't open output file.");
		exit(0);
	}

	fprintf(ofptr, "%s -> %d\n", "he", charfreq[0]);
	fprintf(ofptr, "%s -> %d\n", "she", charfreq[1]);
	fprintf(ofptr, "%s -> %d\n", "they", charfreq[2]);
	fprintf(ofptr, "%s -> %d\n", "hmi", charfreq[3]);
	fprintf(ofptr, "%s -> %d\n", "me", charfreq[4]);
}
/**
  The specialcharcount function counts the frequency of the following 5 special words:
  "he"   "she"   "they"    "him"    "me"
   
  in all the .txt files under directory of the given path and write the results to a file named as filetowrite.
  
  Input: 
  
      path - a pointer to a char string [a character array] specifying the path of the directory; and
      filetowrite - a pointer to a char string [a character array] specifying the file where results should be written in.
      charfreq - a pointer to a long array storing the frequency of the above 5 special words
      
      charfreq[0]: the frequency of "he"
      charfreq[1]: the frequency of "she"
      charfreq[2]: the frequency of "they"
      charfreq[3]: the frequency of "him"
      charfreq[4]: the frequency of "me"

  
  Output: a new file named as filetowrite with the frequency of the above 5 special words written in
  
  Steps recommended to finish the function:
  1) Find all the files ending with .txt and store in filelist.
  2) Read all files in the filelist one by one and count the frequency of each of the above special words. The array 
  long charfreq[] always has the up-to-date frequencies of special words counted so far. If the word is upper case, convert
  it to lower case first. 
  3) Write the result in the output file: filetowrite in following format: 
  
     character -> frequency
     
     example:
     he -> 20
     she -> 11
     they -> 20
     him -> 11
     me -> 12     
     
  Assumption:  
  1) You can assume there is no sub-directory under the given path so you don't have to search the files 
  recursively.    
  2) Only .txt files are counted and other types of files should be ignored.
  
*/
#endif
