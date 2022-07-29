///*
// * alphabetcount.c - this file implements the alphabetlettercount function.
// */
//
//#define _CRT_SECURE_NO_WARNINGS
//
////#include "count.h"
//
///**
//  The alphabetlettercount function counts the frequency of each alphabet letter (A-Z a-z, case sensitive) in all the .txt files under
//  directory of the given path and write the results to a file named as filetowrite.
//  
//  Input: 
//      path - a pointer to a char string [a character array] specifying the path of the directory; and
//      filetowrite - a pointer to a char string [a character array] specifying the file where results should be written in.
//      alphabetfreq - a pointer to a long array storing the frequency of each alphabet letter from A - Z a - z:
//      alphabetfreq[0]: the frequency of 'A'
//      alphabetfreq[1]: the frequency of 'B'
//         ... ...
//      alphabetfreq[25]:the frequency of 'Z'
//      alphabetfreq[26]:the frequency of 'a'
//         ...  ...
//      alphabetfreq[51]:the frequency of 'z'
//  
//  Output: a new file named as filetowrite with the frequency of each alphabet letter written in
//  
//  Steps recommended to finish the function:
//  1) Find all the files ending with .txt and store in filelist.
//  2) Read all files in the filelist one by one and count the frequency of each alphabet letter only (A-Z a - z). The array 
//  long alphabetfreq[] always has the up-to-date frequencies of alphabet letters counted so far. 
//  3) Write the result in the output file: filetowrite in following format: 
//  
//     letter -> frequency
//     
//     example:
//     A -> 200
//     B -> 101
//     ... ...
//     
//  Assumption:  
//  1) You can assume there is no sub-directory under the given path so you don't have to search the files 
//  recursively.    
//  2) Only .txt files are counted and other types of files should be ignored.
//  
//*/
//void alphabetlettercount(char *path, char *filetowrite, long alphabetfreq[])
//{
//	int i;
//	DIR* d = opendir(path);
//	struct dirent* dir;
//	FILE* fptr, *ofptr;
//	char c;
//
//
//	if (d)
//	{
//		while ((dir = readdir(d)) != NULL)
//		{
//			char tempPath[100];
//
//			strcpy(tempPath, path);
//			strcat(tempPath, dir->d_name);
//
//			fptr = fopen(tempPath, "r");
//
//			if (strcmp(dir->d_name, ".") == 0 || strcmp(dir->d_name, "..") == 0)
//			{
//				strcpy(tempPath, "");
//				continue;
//			}
//
//			if (fptr != NULL)
//			{
//				//loop through file to find char frequency
//				while ((c = getc(fptr)) != EOF)
//				{
//					if (c >= 65 && c <= 90)
//					{
//						//capital letter
//						alphabetfreq[c - 'A'] += 1;
//					}
//
//					else if (c >= 97 && c <= 122)
//					{
//						//smal letter
//						alphabetfreq[c - 71] += 1;
//					}
//				}
//				fclose(fptr);
//
//				strcpy(tempPath, "");
//			}
//		}
//		closedir(d);
//	}
//
//	//write data to output file 
//	ofptr = fopen(filetowrite, "w+");
//
//	if (ofptr == NULL) 
//	{
//		printf("Can't open output file.");
//		exit(0);
//	}
//
//	for ( i = 0; i < 52; i++)
//	{
//		if (i <= 25)
//		{
//			//printf("%c %d\n", i + 65, alphabetfreq[i]);
//			fprintf(ofptr, "%c -> %d\n", i + 65, alphabetfreq[i]);
//		}
//
//		else if (i > 25)
//		{
//			//printf("%c %d\n", i + 71, alphabetfreq[i]);
//			fprintf(ofptr, "%c -> %d\n", i + 71, alphabetfreq[i]);
//		}
//	}
//		
//	
//}
