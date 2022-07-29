/* This program is to test alphabetcount function.
 * 
 */

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h> 
#include "dirent.h"
#include <string.h>
#include <stdlib.h>
#include <ctype.h> 
#include <stdbool.h> 
#include "count.h"

/*
 * Print the frequencies of alphabetical characters stored in array: charfreq[] to output screen in the format as:
 * letter -> frequency (one letter a line)
 * Input: charfreq - array having the frequency of each alphabet letter
          size     - the total number of alphabet letters
 * example:
 * a -> 20
 * b -> 30
 */
 
void displayalphabetfreq(long charfreq[], int size)
{
	int i ;
	for( i = 0; i < size/2; i++)   // print upper case letter frequency
	  {
	  	printf("%c -> %d\n", (char)(i+65), charfreq[i]);
	  }

       	for(i = size/2; i < size; i++)  // print lower case letter frequency
	  {
	  	printf("%c -> %d\n", (char)(i+65 + 6), charfreq[i]);  
	  }
}

int main()
{
	  
	  char *path = "..\\data\\";           // the data *.txt files are under this folder
	  char *filetowrite = "..\\result\\result.txt";    // the frequency of all alphabetical letters will be written in this file
	  
	  long alphabetfreq[ALPHABETSIZE] = {0}; // array to store the frequency of each alphablet letter
	  
	  
	  alphabetlettercount(path, filetowrite, alphabetfreq);  // process the data files
	  
	  displayalphabetfreq(alphabetfreq, ALPHABETSIZE);  // print the frequency stored in the array to output screen

	  getchar();
}
