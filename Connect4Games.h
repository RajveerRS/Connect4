#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include<array>


class player {

public:
	
	int noOfTurns = 0;  //tracker for how many turns there have been in the game
	bool successfulLine = 0;	//variable to store true when there's a winner
	const char* lastPlayer = 0;	//variable for player who had the last turn
	const char* lastWinner = 0;	//variable for player who won the last game

	const char* emptyBlock = "|__|";	//building block of the grid to play the game on
	const char* gameBlockPlayer1 = " R  ";
	const char* gameBlockPlayer2 = " G  ";


	void printGrid();	//for printing an empty grid
	void play(int chosenCol, const char* player);	//logic for the whole game
	const char* random();	//random number generator between numbers 0 and 1 to select the first player to start the game

};
