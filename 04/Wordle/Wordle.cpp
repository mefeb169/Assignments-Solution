/* main.cpp
	Wordle Reload is a game that allows you to guess either a 3 letter word or 5 letter word.
	You have a set amount of time to guess a word.  At the conlusion of game play
	you will be provided stats on your overall game play.

	Author: Berenice Vazquez
	Date: 02/21/22
	Class: CS 141, Spring 2022, UIC
	System: Windows 10 CLion

*/

#include <iostream>   // For Input and Output
#include <string>
#include <math.h>
#include <vector>     // For vectors
#include <cctype>     // For tolower() function
#include <ctime>      // For timer
#include <fstream>    // For file input and output
#include <cassert>    // For assert statement used to validate file open

using namespace std;

//functions declarations
void getThreeLetterWords(vector <string> wordleWord);
void getFiveLetterWords(vector <string> wordleWord);
void startThreeLettersGame();
void startFiveLettersGame();
int estimateTotalElapsedTime(time_t startTime, time_t endTime);
void menuController();
void showStats();
int timeLimitChecker(time_t startTime, int gameType);
void calculateStats(int elapsedTime);

//global variables
//vector variable to store words list from file
vector <string> wordleWords;
vector <string> threeLetterWords;
vector <string> fiveLetterWords;
int totalGuessedWords = 0;
bool isLongestStreak = false;
int tempStreak = 0;
int longestStreak = 0;
int totalElapsedTime=0;

//--------------------------------------------------------------------------------
// Display welcome message, introducing the user to the program and
// describing the instructions for the game
void gameDisplayInstructions()
{
	cout << "Program 3: Wordle Reload \n"
		<< "CS 141, Spring 2022, UIC \n"
		<< " \n"
		<< "The objective of this game is to guess the randomly selected \n"
		<< "word within a given number of attempts. You can select either \n"
		<< "a three or five word board. \n"
		<< "At the conclusion of the game, stats will be displayed.  \n"
		<< "Indicators will be given if characters of the user entered \n"
		<< "word are reflected in the guessed word. \n"
		<< "  - If the character is in the correct position, the character \n"
		<< "    will display as an uppercase value.\n"
		<< "  - If the character is within the random word, the character \n"
		<< "    will display as a lowercase value.\n"
		<< "  - If you enter a character that is not in the word, an asterisk '*' \n"
		<< "    will display."
		<< " \n"
		<< endl;
}//end displayWelcomeMessage()

//wordle file text
void readWordsIntoDictionary(vector <string>& wordleWord)
{
	// Read in dictionary into dictionary vector
	ifstream inStream;                      // Declare an input stream for reading
	inStream.open("wordlewords.txt");       // Open dictionary file
	assert(inStream.fail() == false);     // Ensure file open worked

	// If you had previously used vector dictionary, then you might want to clear it
	// before continuing to use it, though that is not the case here.
	wordleWord.clear();

	// Keep repeating while input from the file yields a word
	string newWord;                         // Store a single input word
	while (inStream >> newWord)
	{           // While there is another word to be read
		// Add this new word to the end of the vector, growing it in the process
		wordleWord.push_back(newWord);
	}

	// Close the dictionary file
	inStream.close();
}

//binary search
int binarySearch(string searchWord, vector<string> wordleWord)
{
	int currentPoint = 0;
	int beginPoint = 0;
	int endPoint = wordleWord.size() - 1;


	while (endPoint >= beginPoint)
	{
		int searchResult = searchWord.compare(wordleWord[currentPoint]);

		//if word is found and having same size
		if (searchResult == 0)
		{
			return currentPoint;
		}

		//if words given has small length than found one from words list
		else if (searchResult < 0)
		{
			endPoint = currentPoint - 1;
		}

		//if words given has greater length than found one from words list
		else
		{
			beginPoint = currentPoint + 1;
		}

		currentPoint++;
	}
	return -1; // not found
}

//check if word exists
void checkExists(char board[5][5], vector <string> wordleWord) {

	for (int row = 0; row < 5; row++) {
		string candidateString;

		for (int col = 0; col < 5; col++) {
			candidateString += board[row][col];
		}
		int result = binarySearch(candidateString, wordleWord);

		if (result == -1) {
			cout << "Row " << row << " word does not exist in dictionary" << endl;
		}
		else {
			cout << "Row " << row << " word exist in dictionary" << endl;
		}
	}
}

//three letter option
void startThreeLettersGame()
{
	time_t startTime = NULL;

	//fetching all words from wordle list which has three letters in it
	getThreeLetterWords(wordleWords);

	//finding random word for game
	int randomWordLocation = rand() % threeLetterWords.size();
	string RandomSelectedWord = threeLetterWords[randomWordLocation];

	//show information about three letters game
	cout << "To get started, enter your first 3 letter word.\n"
		<< "You have 4 attempts to guess the random word.\n"
		<< "The timer will start after your first word entry.\n"
		<< "Try to guess the word within 20 seconds.\n\n";

	//total attempts
	int availableAttempts = 4;
	int userAttempts = 0;

	while (userAttempts < availableAttempts)
	{
		//taking input from user
		string userWord = "";
		cout << "Please enter word --> ";
		cin >> userWord;
		cout << "\n\n";


		//check if word is 3 letters
		if (userWord.length() != 3)
		{
			cout << "Invalid word entry - please enter a word that is 3 characters long." << endl;
			continue;
		}

		//find(wordleWords.begin(),wordleWords.end(), userWord); //alternative of below statement
		if (binarySearch(userWord, threeLetterWords) == -1)
		{
			cout << "Not a playable word, please select another word." << endl;
			continue;
		}

		else
		{
			//starting timer only for first time
			if (userAttempts == 0)
			{
				startTime = time(NULL);
			}

			//validating word given by user
			//if word is matched

			
			if (userWord == RandomSelectedWord && timeLimitChecker(startTime, 1) <= 21)
			{
				cout << " [" << (char)toupper(userWord[0]) << "] [" << (char)toupper(userWord[1]) << "] [" << (char)toupper(userWord[2]) << "]\n\n";
				cout << "Nice Work! You gussed the correct word\n";

				//calculating results 
				int elapsedTime = timeLimitChecker(startTime, 1);
				calculateStats(elapsedTime);

				//stoping timer and calculating total elapsed time
				elapsedTime = estimateTotalElapsedTime(startTime, time(NULL));

				cout << " - You completed the board in: " << elapsedTime << " seconds.\n";
				cout << " - It took you " << userAttempts + 1 << "/4 attempts.\n";

				menuController();
			}

			else if (timeLimitChecker(startTime, 1) <= 21)
			{
				// [*] [*] [*]
				char output[3]; int position = 0;//output for one word
				//checking for position of letters and validity
				for (int i = 0; i < userWord.size(); i++)
				{
					bool isSkip = false;

					for (int j = 0; j < RandomSelectedWord.size(); j++)
					{
						//if letter is same of user and selected word
						if (userWord[i] == RandomSelectedWord[j])
						{
							//position is same
							if (i == j)
							{
								//adding capital letter
								output[position] = (char)toupper((userWord[i]));
								position++;
								isSkip = true;
								break;
							}

							//adding small letter
							else
							{
								output[position] = (char)tolower((userWord[i]));
								position++;
								isSkip = true;
								break;
							}
						}
					}
					if (isSkip == false)
					{
						output[position] = '*';
						position++;
					}
					isSkip = false;
				}

				//adding attempt to master output
				char masterOutput[4][3];
				masterOutput[userAttempts][0] = output[0];
				masterOutput[userAttempts][1] = output[1];
				masterOutput[userAttempts][2] = output[2];

				userAttempts++;
				for (int i = 0; i < userAttempts; i++)
				{
					for (int j = 0; j < 3; j++)
					{
						cout << " [";
						cout << masterOutput[i][j];
						cout << "]";
					}
					cout << "\n";
				}
				cout << "\n";
			}

			else
			{
				cout << "Your time has expired. Try again.\n" <<
					" - You are " << timeLimitChecker(startTime, 1) - 21 << " seconds over the 20 second time limit.\n\n";

				isLongestStreak = false;
				tempStreak = 0;

				menuController();
			}
		}
	}

	if (userAttempts >= availableAttempts)
	{
		cout << "Maximum amount of attempts have been reached. Try again.\n";

		isLongestStreak = false;
		tempStreak = 0;

		menuController();
	}
}

//five letter option
void startFiveLettersGame()
{
	time_t startTime = NULL;

	//fetching all words from wordle list which has three letters in it
	getFiveLetterWords(wordleWords);

	//finding random word for game
	int randomWordLocation = rand() % fiveLetterWords.size();
	string RandomSelectedWord = fiveLetterWords[randomWordLocation];

	//show information about three letters game
	cout << "To get started, enter your first 3 letter word.\n"
		<< "You have 6 attempts to guess the random word.\n"
		<< "The timer will start after your first word entry.\n"
		<< "Try to guess the word within 40 seconds.\n\n";

	//total attempts
	int availableAttempts = 5;
	int userAttempts = 0;

	while (userAttempts < availableAttempts)
	{
		//taking input from user
		string userWord = "";
		cout << "Please enter word --> ";
		cin >> userWord;
		cout << "\n\n";


		//check if word is 3 letters
		if (userWord.length() != 5)
		{
			cout << "Invalid word entry - please enter a word that is 5 characters long." << endl;
			continue;
		}

		//find(wordleWords.begin(),wordleWords.end(), userWord); //alternative of below statement
		if (binarySearch(userWord, fiveLetterWords) == -1)
		{
			cout << "Not a playable word, please select another word." << endl;
			continue;
		}

		else
		{
			//starting timer only for first time
			if (userAttempts == 0)
			{
				startTime = time(NULL);
			}

			//validating word given by user
			//if word is matched
			if (userWord == RandomSelectedWord && timeLimitChecker(startTime, 2) <= 41)
			{
				cout << " [" << (char)toupper(userWord[0]) << "] [" << (char)toupper(userWord[1]) << "] [" << (char)toupper(userWord[2]) << "] [" << (char)toupper(userWord[3]) << "] [" << (char)toupper(userWord[4]) << "]\n\n";
				cout << "Nice Work! You gussed the correct word\n";

				//stoping timer and calculating total elapsed time
				int elapsedTime = estimateTotalElapsedTime(startTime, time(NULL));

				calculateStats(elapsedTime);

				cout << " - You completed the board in: " << elapsedTime << " seconds.\n";
				cout << " - It took you " << userAttempts + 1 << "/6 attempts.\n";

				menuController();
			}

			else if (timeLimitChecker(startTime, 2) <= 41)
			{
				// [*] [*] [*]
				char output[5]; int position = 0;//output for one word
				//checking for position of letters and validity
				for (int i = 0; i < userWord.size(); i++)
				{
					bool isSkip = false;

					for (int j = 0; j < RandomSelectedWord.size(); j++)
					{
						//if letter is same of user and selected word
						if (userWord[i] == RandomSelectedWord[j])
						{
							//position is same
							if (i == j)
							{
								//adding capital letter
								output[position] = (char)toupper((userWord[i]));
								position++;
								isSkip = true;
								break;
							}

							//adding small letter
							else
							{
								output[position] = (char)tolower((userWord[i]));
								position++;
								isSkip = true;
								break;
							}
						}
					}
					if (isSkip == false)
					{
						output[position] = '*';
						position++;
					}
					isSkip = false;
				}

				//adding attempt to master output

				char masterOutput[6][5];
				masterOutput[userAttempts][0] = output[0];
				masterOutput[userAttempts][1] = output[1];
				masterOutput[userAttempts][2] = output[2];
				masterOutput[userAttempts][3] = output[3];
				masterOutput[userAttempts][4] = output[4];

				userAttempts++;
				for (int i = 0; i < userAttempts; i++)
				{
					for (int j = 0; j < 5; j++)
					{
						cout << " [";
						cout << masterOutput[i][j];
						cout << "]";
					}
					cout << "\n";
				}
				cout << "\n";
			}

			else
			{
				cout << "Your time has expired. Try again.\n" <<
					" - You are " << timeLimitChecker(startTime, 1) - 41 << " seconds over the 40 second time limit.\n\n";

				isLongestStreak = false;
				tempStreak = 0;

				menuController();
			}
		}
	}

	if (userAttempts >= availableAttempts)
	{
		cout << "Maximum amount of attempts have been reached. Try again.\n";

		isLongestStreak = false;
		tempStreak = 0;

		menuController();
	}
}

//filtering 3 letter words from all words
void getThreeLetterWords(vector <string> wordleWord)
{
	for (int i = 0; i < wordleWord.size(); i++)
	{
		if (wordleWord[i].length() == 3)
		{
			threeLetterWords.push_back(wordleWord[i]);
		}
	}
}

//filtering 5 letter words from all words
void getFiveLetterWords(vector <string> wordleWord)
{
	for (int i = 0; i < wordleWord.size(); i++)
	{
		if (wordleWord[i].length() == 5)
		{
			fiveLetterWords.push_back(wordleWord[i]);
		}
	}
}

//finding time difference 
int estimateTotalElapsedTime(time_t startTime, time_t endTime)
{
	int elapsedSeconds = 0;

	elapsedSeconds = difftime(endTime, startTime);

	return elapsedSeconds;
}

int timeLimitChecker(time_t startTime, int gameType)
{
	//checking time if limit is reached
	int elapsedTime = estimateTotalElapsedTime(startTime, time(NULL));

	return elapsedTime;
}

void menuController()
{
	//making variables null
	threeLetterWords.clear();
	fiveLetterWords.clear();


	int userChoice = 0;

	cout << "\nSelect a menu option:\n"
		<< "   1. To play Wordle Reload 3 letter play\n"
		<< "   2. To play Wordle Reload 5 letter play\n"
		<< "   3. Exit the program\n"
		<< "Your choice --> ";
	cin >> userChoice;
	cout << endl;

	//3 letter wordle reload
	if (userChoice == 1)
	{
		startThreeLettersGame();
	}

	//5 letter worlde reload
	else if (userChoice == 2)
	{
		startFiveLettersGame();
	}

	//exit program option
	else if (userChoice == 3)
	{
		showStats();
		exit(0);
	}

	else
	{
		cout << "\n\nInvalid Choice\n\n";
		menuController();
	}
}

void calculateStats(int elapsedTime) 
{
	totalElapsedTime += elapsedTime;
	totalGuessedWords++;

	isLongestStreak = true;
	tempStreak++;
	if (tempStreak > longestStreak)
	{
		longestStreak = tempStreak;
	}
}

void showStats()
{
	cout << "Overall Stats:\n"<<
		" - You Guessed: "<<totalGuessedWords<<"\n"<<
		" - Your longest streak: "<<longestStreak<<"\n"<<
		"- Average word completion time: " << ((totalGuessedWords == 0) ? ("N/A") : to_string(totalElapsedTime / totalGuessedWords))<<"\n"<<
		"Exiting Program\n";
}

int main()
{
	srand(1);

	//Display game instructions
	gameDisplayInstructions();

	// Read in words from the dictionary and commonly misspelled words files into vectors.
	readWordsIntoDictionary(wordleWords);

	// Keep looping until user selects the option to exit
	menuController();

	////stats
	//cout << "Overall Stats:\n"
	//    << "   - You guessed: " << wordsGuessed << endl;
	//cout << "   - Your longest streak is: " << longestStreak << endl;
	//cout << "   - Average word completion time: " << completionTime << endl;
	//cout << "Exiting program" << endl;



	//    vector <string> three_letter_words;
	//    vector <string> five_letter_words;
	//    for(int i=0; i < userWord[i].length(); i++) {
	//        if (userWord[i].length() == 3) {
	//            threeLetterWords.push_back(userWord[i]);
	//        }
	//separate
	//        if (userWord[i].length() == 5) {
	//            fiveLetterWords.push_back(userWord[i]);
	//        }
	//    }


	//  while(attempts < 5 && guessed == 0){
	//          cout << "Please enter word --> ";
	//          cin >> userGuess;
	//
	//          for (int i=0; i < userGuess.length(); i++)
	//            userGuess[i] = tolower(userGuess[i]);
	//
	//          //check that word is 3 letters
	//          if(userGuess.length()!=3){
	//            cout << "Invalid word entry - please enter a word that is 3 characters long." << endl;
	//          }
	//          //check if valid word
	//          else if(binarySearchString3Letter(userGuess, threeLetterWords) == -1){
	//            cout << "Not a playable word, please select another word." << endl;
	//          }

	return 0;
}// End of Main