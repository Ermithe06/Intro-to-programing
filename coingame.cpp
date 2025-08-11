/* Name: Ermithe Tilusca
Date: 2/15/2025
Assignment: #3
Due Date: 2/18/2025
About this project: this program asks the user to enter a dollar amount. 
The user is then prompted for the quantity of Half Dollars and other 
types of coins that add up to the dollar amount. If the total match the 
dollar ammount, the user win, otherwise they lose. They have the option 
to play again.
Assumptions: assumes the user will enter non-negative integer values for 
the coin quantities and will enter a non-negative amount to match.

All work below was performed by Ermithe Tilusca */


#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main()
{
	//double variable for dollar amount
	double dollarAmount;

	//constant double variables for the value of each coins
	const double halfDollars = .50;
	const double quarters = .25;
	const double dimes = .10;
	const double nickels = .05;
	const double pennies = .01;
                                
	//double variables for the quantity of each coins
	double numHalfDollars;
	double numQuarters;
	double numDimes;
	double numNickels;
	double numPennies;

	//double variable for the total amount the coins add up to
	double total;

	//double variable for how much more or less total is from dollar amount
	double offBy;

	//char variable to ask if user wants to play again
	char playAgain;

	//win or lose integer variables
	int win = 0;
	int lose = 0;

	//amount of games play
	int totalGames;

	//percentage of games win
	double percentage;

	//welcome message	
	cout << "Welcome to the \"Making Change\" game!\n";
	
	//do loop for what happens when the user plays the game
	do
	{
		//the start of the game, user input dollar amount
		cout << "\nEnter a dollar amount: ";
		cin >> dollarAmount;

		//set the amount to 2 decimal places
        	cout << fixed << showpoint << setprecision(2);

		//Display the amount that needs to be match
		cout << "Match the amount $" << dollarAmount << endl;
	
		//input the quantity of each coins to match the dollar amount
		cout << "Half Dollars: ";
		cin >> numHalfDollars;
		cout << "Quarters: ";
		cin >> numQuarters;
		cout << "Dimes: ";
		cin >> numDimes;
		cout << "Nickels: ";
		cin >> numNickels;
		cout << "Pennies: ";
		cin >> numPennies;       

		//calculate the total amount that the user entered in
		total = (halfDollars * numHalfDollars) + (quarters * numQuarters) + 
		(dimes * numDimes) + (nickels * numNickels) + (pennies * numPennies);

		//calculate how much more or less the total is from the match amount
		if(total >= dollarAmount)
		{
			offBy = total - dollarAmount;
		}		
		else
		{
			offBy = dollarAmount - total;
		}

		//check if the user entered the right amount and win
		if (total == dollarAmount)
		{
			cout << "You win!" << endl;
			win++;
		}

		else
		{
			cout << "You lost by: " << offBy << endl;
			lose++;
		}

		//ask user if they want to play again
		cout << "Play again? (y or n): ";
		cin >> playAgain;

		 //while user's input to play again is not yes or no
        	 while ( playAgain != 'y' && playAgain != 'Y' && playAgain != 'n' && playAgain != 'N')
        	{       
                	cout << "Please enter y or n: ";
                	cin >> playAgain;
        	}

		}while (playAgain == 'y' || playAgain == 'Y'); //play again if user input y or Y

		//if user does not want to play again
		if (playAgain == 'n' || playAgain == 'N')
		{
			//end of the game, print the user's results
			cout << "\nWins: " << win << "\n";
			cout << "Losses: " << lose << "\n";

			//set to one decimal place
			cout << fixed << showpoint << setprecision(1);
		
			//calculate total games played
			totalGames =  win + lose;
			percentage = static_cast<double>(win)/totalGames;		
			cout << "Win Percentage: " << percentage * 100 << "%" << "\n";
			cout << "Thanks for playing!" << "\n";
	}
	
       return 0;
}
