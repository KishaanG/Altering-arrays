/*

	Author: Kishaan G.
	Description: Array assignment.
	Last modified: June 6 2022.

*/


#include <iostream>
#include <ctime>
using namespace std;

// =============== Prototypes ===================

void keyToContinue();
int getInt(string);
int menu(string, string [], int, string);

// ===========================

int getArraySize();
void getArrayContents(int [], int);
void displayArray(int [], int);
void makeArrayRandom(int [], int);
int getContainerOfSmallestValue(int [], int);
double getAverageOfArray(int [], int);
void lowestToHighestOfArray(int [], int);
void highestToLowestOfArray(int [], int);
void changeContentsOfAPos(int [], int);
void swapPositionsInArray(int [], int, int);
void swapPositionsInArrayInterface(int &, int &, int);
void arrayFunctionsMenu();

// =============== Definitions ==================

void keyToContinue()
{
	cin.ignore();
	cout << "Type any key to continue..." << endl;
	getchar();
	return;
}

// =============================

int getInt(string prompt)
{
	int response;
	cout << prompt << endl; // Displays a propmt then gets an int input.
	cin >> response;
	return response;
}

// =============================

int menu(string prompt, string options[], int numberOfOptions, string errorMsg)
{
	int userChoice = 0;
	do
	{
		cout << prompt << endl;
		for(int i = 0; i < numberOfOptions; i++)
		{
			cout << i + 1 << ") " << options[i] << endl;
		}
		cin >> userChoice;
		if(userChoice < 1 or userChoice > numberOfOptions)
		{
			cout << errorMsg << endl;
			keyToContinue();
			system("clear");
		}
	}while (userChoice < 1 or userChoice > numberOfOptions);
	
	return userChoice;
}

// =============================

int getArraySize()
{
	int arraySize = 0;
	do
	{
		arraySize = getInt("What would you like to be the size of the array?"); // Gets the array size. 
		if(arraySize < 1)
		{ // Checks if the user inputs an array too small. 
			cout << "The array has to be larger than zero." << endl;
			keyToContinue();
			system("clear");
		}
	} while(arraySize < 1);
	system("clear");
	return arraySize;
}

// =============================

void getArrayContents(int _mainArray[], int arraySize)
{
	for(int i = 0; i < arraySize; i++) /// This will iterate through the array and get an integer for each spot.
	{
		cout << "What would you like to be in spot " << i << " in the array?" << endl;
		cin >> _mainArray[i];
		system("clear");
	}
	system("clear");
	return;
}

// =============================

void displayArray(int _mainArray[], int arraySize)
{
	for(int i = 0; i < arraySize; i++) /// This will iterate through each position of the array and display it.
	{
		cout << _mainArray[i] << endl;
	}
	keyToContinue();
	system("clear");
	return;
}

// =============================

void makeArrayRandom(int _mainArray[], int arraySize)
{
	int randNum = 0;
	srand(time(NULL));
	
	for(int i = 0; i < arraySize; i++) // Iterate through the array and swaps it with a random int between 1 and 100. 
	{
		randNum = rand() % 100 + 1;
		_mainArray[i] = randNum;
	}
	return;
}

// =============================

int getContainerOfSmallestValue(int _mainArray[], int arraySize)
{
	int smallestNum = _mainArray[0]; // Sets the first position of the array as the smallest number. 
	int smallestNumPosition = 0;
	for(int i = 1; i < arraySize; i++) // Iterates through the array. 
	{		
		if(smallestNum > _mainArray[i]) // Checks if the position in the array is smaller than the smallest number previously checked. 
		{
			smallestNum = _mainArray[i];
			smallestNumPosition = i;
		}
	}
	return smallestNumPosition;
}

// =============================

double getAverageOfArray(int _mainArray[], int arraySize)
{
	double sumOfArray = 0;
	for(int i = 0; i < arraySize; i++)
	{
		sumOfArray += _mainArray[i]; // Adds up all the numbers in the array. 
	}
	return sumOfArray / arraySize; // Divdes the sum of the array by the amount of numbers in the array. 
}

// =============================

void lowestToHighestOfArray(int _mainArray[], int arraySize)
{
	int storage = 0;
	for(int i = 0; i < arraySize; i++)
	{ // Iterates through the array.
		for(int j = i + 1; j < arraySize; j++)
		{ // Iterates through the positions in the array after the one stored in i.
			if(_mainArray[j] < _mainArray[i])
			{ // If a position after is smaller, it swaps the numbers.
				swapPositionsInArray(_mainArray, i, j);
			}
		}
	}
	system("clear");
	return;
}

// =============================

void highestToLowestOfArray(int _mainArray[], int arraySize)
{
	int storage = 0;
	for(int i = 0; i < arraySize; i++)
	{
		for(int j = i + 1; j < arraySize; j++)
		{
			if(_mainArray[j] > _mainArray[i])
			{
				swapPositionsInArray(_mainArray, i, j);
			}
		}
	}
	system("clear");
	return;
}

// =============================

void changeContentsOfAPos(int _mainArray[], int arraySize)
{
	int replacePos = 0;
	do
	{
		replacePos = getInt("What position in the array would you like to change?");
		system("clear");
		if(replacePos < 0 or replacePos > arraySize - 1)
		{
			cout << "Please choose a position between 0 and " << arraySize - 1 << " inclusive." << endl;
			keyToContinue();
			system("clear");
		}
	} while(replacePos < 0 or replacePos > arraySize - 1);
	_mainArray[replacePos] = getInt("What number would you like to replace it with?");
	system("clear");
	return;
}

// =============================

void swapPositionsInArray(int _mainArray[], int position1, int position2)
{
	int storage = 0;
	storage = _mainArray[position1];
	_mainArray[position1] = _mainArray[position2];
	_mainArray[position2] = storage;
	return;
}

// =============================

void swapPositionsInArrayInterface(int & swapPos1, int & swapPos2, int arraySize)
{
	do
	{
		swapPos1 = getInt("What is the first position you would like to swap?");
		if(swapPos1 < 0 or swapPos1 > arraySize - 1)
		{
			system("clear");
			cout << "Please type a number between 0 and " << arraySize - 1 << " inclusive." << endl;
			keyToContinue();
			system("clear");
		}
	} while(swapPos1 < 0 or swapPos1 > arraySize - 1);
	system("clear");
	do
	{
		swapPos2 = getInt("What is the second position you would like to swap?");
		if(swapPos2 < 0 or swapPos2 > arraySize - 1)
		{
			system("clear");
			cout << "Please type a number between 0 and " << arraySize - 1 << " inclusive." << endl;
			keyToContinue();
			system("clear");
		}
	} while(swapPos2 < 0 or swapPos2 > arraySize - 1);
	system("clear");
	return;
}

// =============================

void arrayFunctionsMenu()
{
	int arraySize = getArraySize();
	int mainArray[arraySize];
	string menuOptions[9] = {"Display the contents of the array.", "Replace the contents of the array with random numbers.", "Display the position of the array with the smallest number.", "Display the smallest number in the array.", "Display the average of the array.", "Sort the array from smallest to largest or largest to smallest.", "Change the contents of a position in array.", "Swap the contents of two positions in the array.", "Quit"};
	string errorMsg = "That is not a valid choice.";
	string menuPrompt = "What would you like to do?";
	int userMenuChoice = 0;
	string orderArrayOptions[2] = {"Lowest to highest.", "Highest to lowest."};
	getArrayContents(mainArray, arraySize);
	int smallestNumInArrayPos = 0;
	int swapPos1 = 0;
	int swapPos2 = 0;
	
	do
	{
		smallestNumInArrayPos = getContainerOfSmallestValue(mainArray, arraySize);
		userMenuChoice = menu(menuPrompt, menuOptions, 9, errorMsg);
		switch(userMenuChoice)
		{
			case 1:
				system("clear");
				displayArray(mainArray, arraySize);
				break;
	
			case 2:
				system("clear");
				makeArrayRandom(mainArray, arraySize);
				break;
	
			case 3:
				system("clear");
				cout << smallestNumInArrayPos << " is the position with the smallest value." << endl;
				keyToContinue();
				system("clear");
				break;
	
			case 4:
				system("clear");
				cout << mainArray[smallestNumInArrayPos] << " is the smallest number in the array." << endl;
				keyToContinue();
				system("clear");
				break;
	
			case 5:
				system("clear");
				cout << getAverageOfArray(mainArray, arraySize) << " is the average of the array." << endl;
				keyToContinue();
				system("clear");
				break;
	
			case 6:
				system("clear");
				if(menu("Would you like to go from: ", orderArrayOptions, 2, "Please type either 1 or 2.") == 1)
				{
					lowestToHighestOfArray(mainArray, arraySize);
				}
				else
				{
					highestToLowestOfArray(mainArray, arraySize);
				}
				break;
	
			case 7:
				system("clear");
				changeContentsOfAPos(mainArray, arraySize);
				break;
	
			case 8:
				system("clear");
				swapPositionsInArrayInterface(swapPos1, swapPos2, arraySize);
				swapPositionsInArray(mainArray, swapPos1, swapPos2);
				break;
	
			case 9: // Quit option.
				break;
		}
	} while(userMenuChoice != 9);
	return;
}

int main()
{
	arrayFunctionsMenu();
	return 0;
}
