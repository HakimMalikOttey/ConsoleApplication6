// ConsoleApplication6.cpp : Defines the entry point for the console application.
//
// Made by Hakim Ottey on 1/27/2018 for CSC215
#include "stdafx.h"
#include<iostream>
#include<cstdlib>
#include <time.h>
#include <windows.h>
using namespace std;
//WARNING: Possible error might come up where guess might try to divide by 0 for some weird reason. Need to talk to Tony ( the professor) about this
int main()
{
// random number generator
	srand(static_cast<unsigned int>(time(0)));
// tracks how many times the program failed to find a match between secretNumber and guess
	int count = 0;
//Creates a randomly generated number for secretNumber. This number will remain constant througout the duration of the program.
	int secretNumber = rand() % 64 + 1;
	cout << "The Enemy is hiding at Grid #" << secretNumber << endl;
//Starting number for max  in range and guess. During first run of the program, no numbers above 64 shall be guessed.
	int High = 64;
// Starting number for min in range and guess. During first run of the program, no number under 1 shall be guessed. 
	int Low = 1;
// Sets the scope that int guess will guess a number in.
	int range = High - Low;
	//int guess = rand() % range + Low;
	//int guess = (range / 2) + Low;
	int guess = 0;
	do{
// Might be repetetive, but this does the same thing as before, but the High and Low will constantly be getting higher ( in the case of the Low)
// and/or lower (in the case of the High) depending on the result of the guess. It uses the same High and Low from outside the loop, but such information will be replaced as the while loop continues
		cout << "Old range=" << range << endl;
		range = High - Low;
		cout << "New range=" << range << endl;
		
		guess = (range / 2) + Low;
		cout << "New guess=" << guess << endl;
		cout << "\n Initializing search #" << count << " for Connor...\n\n";
		Sleep(2000);
// Takes the guess the computer made and makes it the newest possible highest number than can be guessed. 
//Every time the computer failed to get a match between guess and secretNumber, the amount within count will be incremented by 1. This will keep track on how many tries it took to get the right answer
		if (guess > secretNumber) {
			cout << "\n Guess was too high." << "Guess was " << guess<<".";
			High = guess--;
			count = count++;
			cout << "\nNow changing cieling parameter to " << High<<"\n";
		}
// Takes the guess the computer made and makes it the newest possible lowest number than can be guessed. 
		if (guess < secretNumber) {
			cout << "\n Guess was too low."<<" Guess was "<<guess << ".";
			Low = guess++;
			count = count++;
			cout << "\nNow changing floor parameter to " << Low << "\n";
		}	

	} while (guess != secretNumber);
	// Prints out the guess the computer made, prints out the number that was generated for secret number,prints out the amount of tries it took to get a match, and closes out the program

	cout << "HK has found Connor. HK searched at coordinate " << guess << " and Connor was located at coordinate " << secretNumber << ".";
	cout << "\n it took " << count << " attempts";
	system("pause");
	return 0;
	} 


