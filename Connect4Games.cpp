#include "Connect4Games.h"



const int rows = 7;
const int column = 6;
const char* it[rows][column];   //global array for the game in which the grid will be made


void player::printGrid() {  //print the empty Grid at the start of the game

	std::cout << "NEW GAME" << std::endl <<std::endl;

	for (int row = 0; row < 7; row++) {
		for (int column = 0; column < 6; column++)
		{
			auto i = it[row][column] = "|__|";
			std::cout << i;
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
}
	

const char* player::random() {   //function for deciding which player gets to start the game
	srand(time(NULL));

	int r = rand() % 2;

	if (r == 0) {
		return gameBlockPlayer1;
	}
	else {
		return gameBlockPlayer2;
	}
}

void player::play(int chosenCol, const char* player) {

	//Start checks for inserting player's game blocks

	if ((strcmp(emptyBlock, it[6][chosenCol])) == 0) {    //checks whether the very bottom row for the chosen column is empty
		it[6][chosenCol] = player;	//insert player's "R" or "G" block
		
									//check for a win horizontally across the columns				
		if ((chosenCol + 3) < column) {
			if ((strcmp(it[6][chosenCol], it[6][chosenCol + 1]) == 0) &&
				(strcmp(it[6][chosenCol + 1], it[6][chosenCol + 2]) == 0) &&
				(strcmp(it[6][chosenCol + 2], it[6][chosenCol + 3]) == 0))
			{

				std::cout << "Succesful connect!";
				std::cout << std::endl;
				successfulLine = 1;
				lastWinner = player;  //set flag for last winner
			}
		}
		else if (abs((chosenCol - 3)) >= 0)
		{
			if ((strcmp(it[6][chosenCol], it[6][chosenCol - 1]) == 0) &&
				(strcmp(it[6][chosenCol - 1], it[6][chosenCol - 2]) == 0) &&
				(strcmp(it[6][chosenCol - 2], it[6][chosenCol - 3]) == 0))
			{

				std::cout << "Succesful connect!";
				std::cout << std::endl;
				successfulLine = 1;
				lastWinner = player;  //set flag for last winner
			}
		}

		noOfTurns = noOfTurns + 1;		//track number of turns played in the game so far

		std::cout << "Number of game turns so far: \n" << noOfTurns;
		std::cout << std::endl;
		std::cout << std::endl;
		for (int row = 0; row < 7; row++) {				//print the game grid after block insertion
			for (int column = 0; column < 6; column++)
			{
				std::cout << it[row][column];
			}
			std::cout << std::endl;
		}
	}

	else {
		int checkLocation = 1;
		if (strcmp(emptyBlock, it[0][chosenCol]) == 0) {  //first check whether the first block of this column is empty, if it is then strcmp returns a 0

			while (checkLocation < rows) {
				
				if (strcmp(emptyBlock, it[checkLocation][chosenCol]) == 0)
				{
					checkLocation = checkLocation + 1;
				}
				
				else
				{
					int placement = checkLocation - 1;
					it[placement][chosenCol] = player;   //insert game block

					noOfTurns = noOfTurns + 1;		//track number of turns played in the game so far

					//check for a win vertically down the column
					if ((placement + 3) < rows)
					{
						if ((strcmp(it[placement][chosenCol], it[placement + 1][chosenCol]) == 0) &&
							(strcmp(it[placement + 1][chosenCol], it[placement + 2][chosenCol]) == 0) &&
							(strcmp(it[placement + 2][chosenCol], it[placement + 3][chosenCol]) == 0))
						{
							std::cout << "Succesful connect!";
							std::cout << std::endl;
							successfulLine = 1;
							lastWinner = player;  //set flag for last winner
						}
					}

					//check for a win horizontally across the columns
					if (successfulLine == 0) {
						if ((placement + 3) < column) {
							if ((strcmp(it[placement][chosenCol], it[placement][chosenCol + 1]) == 0) &&
								(strcmp(it[placement][chosenCol + 1], it[placement][chosenCol + 2]) == 0) &&
								(strcmp(it[placement][chosenCol + 2], it[placement][chosenCol + 3]) == 0))
							{

								std::cout << "Succesful connect!";
								std::cout << std::endl;
								successfulLine = 1;
								lastWinner = player;  //set flag for last winner
							}
						}
						else if (abs((placement - 3)) > 0)
						{
							if ((strcmp(it[placement][chosenCol], it[placement][chosenCol - 1]) == 0) &&
								(strcmp(it[placement][chosenCol - 1], it[placement][chosenCol - 2]) == 0) &&
								(strcmp(it[placement][chosenCol - 2], it[placement][chosenCol - 3]) == 0))
							{

								std::cout << "Succesful connect!";
								std::cout << std::endl;
								successfulLine = 1;
								lastWinner = player;  //set flag for last winner
							}
						}
					}

					//check for a diagonal win
					if (successfulLine == 0) {
						if (((placement + 3) < rows) && ((chosenCol + 3) < column))  //for checking from top left towards the bottom right diagonal
						{
							if ((strcmp(it[placement][chosenCol], it[placement + 1][chosenCol + 1]) == 0) &&
								(strcmp(it[placement + 1][chosenCol + 1], it[placement + 2][chosenCol + 2]) == 0) &&
								(strcmp(it[placement + 2][chosenCol + 2], it[placement + 3][chosenCol + 3]) == 0))
							{
								std::cout << "Successful connect!";
								std::cout << std::endl;
								successfulLine = 1;
								lastWinner = player;  //set flag for last winner
							}
						}

						else if (((placement - 3) <= 0) && ((chosenCol - 3) >= 0))   //for checking from top right towards the bottom left diagonal
						{
							if ((strcmp(it[placement][chosenCol], it[placement + 1][chosenCol - 1]) == 0) &&
								(strcmp(it[placement + 1][chosenCol - 1], it[placement + 2][chosenCol - 2]) == 0) &&
								(strcmp(it[placement + 2][chosenCol - 2], it[placement + 3][chosenCol - 3]) == 0))
							{
								std::cout << "Successful connect!";
								std::cout << std::endl;
								successfulLine = 1;
								lastWinner = player;  //set flag for last winner
							}
						}
					}	

					for (int row = 0; row < 7; row++) {				//print the game grid after last block insertion and win check
						for (int column = 0; column < 6; column++)
						{
							std::cout << it[row][column];
						}
						std::cout << std::endl;
					}

					std::cout << "Number of game turns so far: \n" << noOfTurns;
					std::cout << std::endl;
					std::cout << std::endl;
					break;
				}
			}
		}

		//in case the player tries to add a block when the column is full
		else if (strcmp(emptyBlock, it[0][chosenCol]) != 0) {
			std::cout << "Column Full!";
			std::cout << std::endl;
			std::cout << std::endl;

			for (int row = 0; row < 7; row++) {				//print the game grid after block insertion
				for (int column = 0; column < 6; column++)
				{
					std::cout << it[row][column];
				}
				std::cout << std::endl;
			}
		}
	}	
	lastPlayer = player;	//flag for the game winner
}


int main() {

	int chosenCol; //variable to store column chosen by the player to insert the block
	player PlayGame;

	PlayGame.printGrid();  //printing the empty grid before the start of the game

	const char* firstPlayer = PlayGame.random();

		while(1)
		if(PlayGame.lastWinner == 0){

			std::cout << "This is a two player game: You can either play as player R or G. The player who is able to succesfully connect the first 4 blocks horizontally, vertically or diagonally wins the game.\n" << std::endl;
			std::cout << "The first player to start the game is Player: " << firstPlayer << std::endl << std::endl;

			while (PlayGame.successfulLine == 0) { //if there has not been a 'Succesful 4' connection then proceed with the block placing logic
				std::cout << std::endl;
				std::cout << "Enter number of the column where you want to enter your game block. The columns are numbered from 0 to 1. \n" << std::endl;
				std::cin >> chosenCol;
				std::cout << std::endl;


				if (PlayGame.noOfTurns == 0)	//allow the player chosen by random number generator to start the game if it is the first game turn
				{
					PlayGame.play(chosenCol, firstPlayer);
				}
				else {	//toggle between each player per turn
					if (PlayGame.lastPlayer == " R  ") {
						const char* currentPlayer = PlayGame.gameBlockPlayer2;
						PlayGame.play(chosenCol, currentPlayer);
					}
					else if (PlayGame.lastPlayer == " G  ") {
						const char* currentPlayer = PlayGame.gameBlockPlayer1;
						PlayGame.play(chosenCol, currentPlayer);
					}
				}
			}

			PlayGame.successfulLine = 0;	//make sure these variables have been reset for the new game
			PlayGame.noOfTurns = 0;
			PlayGame.printGrid();
		}
		//after the first set of game is finished, decide who starts next
		else if (PlayGame.lastWinner == PlayGame.gameBlockPlayer2)
		{
			while (PlayGame.successfulLine == 0) { //if there has not been a 'Succesful 4' connection then proceed with the block placing logic
				std::cout << "The first player to start the game is Player: " << PlayGame.gameBlockPlayer1 << std::endl << std::endl;
				std::cout << "Enter number of the column where you want to enter your game block. The columns are numbered from 0 to 1. \n" << std::endl;
				std::cin >> chosenCol;
				std::cout << std::endl;


				if (PlayGame.noOfTurns == 0)
				{
					PlayGame.play(chosenCol, PlayGame.gameBlockPlayer1);

				}
				else {
					if (PlayGame.lastPlayer == " R  ") {
						const char* currentPlayer = PlayGame.gameBlockPlayer2;
						PlayGame.play(chosenCol, currentPlayer);
					}
					else if (PlayGame.lastPlayer == " G  ") {
						const char* currentPlayer = PlayGame.gameBlockPlayer1;
						PlayGame.play(chosenCol, currentPlayer);
					}
				}
			}
		}

		else if (PlayGame.lastWinner == PlayGame.gameBlockPlayer1)
		{

			while (PlayGame.successfulLine == 0) { //if there has not been a 'Succesful 4' connection then proceed with the block placing logic
				std::cout << "The first player to start the game is Player: " << PlayGame.gameBlockPlayer2 << std::endl << std::endl;
				std::cout << "Enter number of the column where you want to enter your game block. The columns are numbered from 0 to 1. \n" << std::endl;
				std::cin >> chosenCol;
				std::cout << std::endl;


				if (PlayGame.noOfTurns == 0)
				{
					PlayGame.play(chosenCol, PlayGame.gameBlockPlayer2);

				}
				else {
					if (PlayGame.lastPlayer == " R  ") {
						const char* currentPlayer = PlayGame.gameBlockPlayer2;
						PlayGame.play(chosenCol, currentPlayer);
					}
					else if (PlayGame.lastPlayer == " G  ") {
						const char* currentPlayer = PlayGame.gameBlockPlayer1;
						PlayGame.play(chosenCol, currentPlayer);
					}
				}
			}
		}
	
	return 0;
}