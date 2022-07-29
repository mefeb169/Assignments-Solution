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
#include "alphabetcount.c"

#define ALPHABETSIZE 52     //The total number of alphabetical letter from A - Z and a - z(case sensitive)
#define SPECIALSIZE 5   // The total number of these special words: he, she, they, him, me 

void alphabetlettercount(char *path, char *filetowrite, long alphabetfreq[]);
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

void specialcount(char *path, char *filetowrite,  long charfreq[]);
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
