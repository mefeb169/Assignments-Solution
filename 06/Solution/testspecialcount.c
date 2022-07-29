/* This program is to test specialcharcount function.
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
 * This function prints the frequency stored in array charfreq[] to output screen.
 * Input: charfreq - array having the frequency of special words
          size     - the total number of special words
 * example:
 * he -> 20
 * she -> 30          
 */
void displayspecialfreq(long charfreq[], int size)
{	int i;
	for( i = 0; i < size; i++)
	  {
	  	switch(i)
	  	{
	  		case 0:
	  			printf("he -> %d\n", charfreq[i]);
	  			break;
	  		case 1:
	  			printf("she -> %d\n", charfreq[i]);
	  			break;
	  		case 2:
	  			printf("they -> %d\n", charfreq[i]);
	  			break;
	  		case 3:
	  			printf("him -> %d\n", charfreq[i]);
	  			break;
	  		case 4:
	  			printf("me -> %d\n", charfreq[i]);
	  			break;
	  	}	  	
	  }
}

int main()
{
	  char *path = "..\\data\\";           // the path of the directory including the *.txt files to be processed
	  char *filetowrite = "..\\result\\specialresult.txt";    // the frequency of all alphabetical letters will be written in this file
	  
	  long charfreq[SPECIALSIZE] = {0}; // array to store the frequency of 5 special characters
	  
	  specialcount(path, filetowrite, charfreq); // count the frequency of special characters and write into file
	  
	  displayspecialfreq(charfreq, SPECIALSIZE); // print the array to output screen	  

	  getchar();
}
