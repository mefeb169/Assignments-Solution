///*
// * specialcount.c - this file implements the specialcount function.
// */
//
//
//#include <stdio.h> 
//#include "count.h"
//
//void specialcount(char *path, char *filetowrite, long charfreq[])
//{
//
//  	DIR* d = opendir(path);
//	struct dirent* dir;
//	FILE* fptr, * ofptr;
//	char c;
//	char* read = _strdup("");
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
//				while (!feof(fptr))
//				{
//					fscanf(fptr, "%s", read);
//
//					if (_stricmp(read, "he") == 0)
//					{
//						//storing to array 0
//						charfreq[0] += 1;
//					}
//
//					else if (_stricmp(read, "she") == 0)
//					{
//						//storing to array 1
//						charfreq[1] += 1;
//					}
//
//					else if (_stricmp(read, "they") == 0)
//					{
//						//storing to array 2
//						charfreq[2] += 1;
//					}
//
//					else if (_stricmp(read, "him") == 0)
//					{
//						//storing to array 3
//						charfreq[3] += 1;
//					}
//
//					else if (_stricmp(read, "me") == 0)
//					{
//						//storing to array 4
//						charfreq[4] += 1;
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
//	fprintf(ofptr, "%s -> %d\n", "he", charfreq[0]);
//	fprintf(ofptr, "%s -> %d\n", "she", charfreq[1]);
//	fprintf(ofptr, "%s -> %d\n", "they", charfreq[2]);
//	fprintf(ofptr, "%s -> %d\n", "hmi", charfreq[3]);
//	fprintf(ofptr, "%s -> %d\n", "me", charfreq[4]);
//		
//}
///**
//  The specialcharcount function counts the frequency of the following 5 special words:
//  "he"   "she"   "they"    "him"    "me"
//   
//  in all the .txt files under directory of the given path and write the results to a file named as filetowrite.
//  
//  Input: 
//  
//      path - a pointer to a char string [a character array] specifying the path of the directory; and
//      filetowrite - a pointer to a char string [a character array] specifying the file where results should be written in.
//      charfreq - a pointer to a long array storing the frequency of the above 5 special words
//      
//      charfreq[0]: the frequency of "he"
//      charfreq[1]: the frequency of "she"
//      charfreq[2]: the frequency of "they"
//      charfreq[3]: the frequency of "him"
//      charfreq[4]: the frequency of "me"
//
//  
//  Output: a new file named as filetowrite with the frequency of the above 5 special words written in
//  
//  Steps recommended to finish the function:
//  1) Find all the files ending with .txt and store in filelist.
//  2) Read all files in the filelist one by one and count the frequency of each of the above special words. The array 
//  long charfreq[] always has the up-to-date frequencies of special words counted so far. If the word is upper case, convert
//  it to lower case first. 
//  3) Write the result in the output file: filetowrite in following format: 
//  
//     character -> frequency
//     
//     example:
//     he -> 20
//     she -> 11
//     they -> 20
//     him -> 11
//     me -> 12     
//     
//  Assumption:  
//  1) You can assume there is no sub-directory under the given path so you don't have to search the files 
//  recursively.    
//  2) Only .txt files are counted and other types of files should be ignored.
//  
//*/
//
