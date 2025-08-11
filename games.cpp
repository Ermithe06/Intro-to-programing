/* Name: Ermithe Tilusca
Date: 2/24/2025
Assignment: #4
Due Date: 2/28/2025
About this project: This program presents the user with a menu, on which 
includes four games: Guess the Number, High Low, Collect Pairs, and Math 
Quiz. These games all involve randomness. The menu also allows the user 
to view statistics, reset statistics and read rules of the games.
Assumptions: None

All work below was performed by Ermithe Tilusca */

/*Headers/Libraries*/
#include <iostream> 
#include <cstdlib> // for srand(), rand()
#include <ctime> // for time()
#include <iomanip>

using namespace std;

/*Function Declarations*/
void printRules();
int menu();
int guessNumber();
int highLow();
int mathQuiz();
void viewStats(int, int);
int collectPairs();

int main()
{
	//seed the random number generator
        srand(time(0));

	//declare and initialize the variables for wins and losses
	int wins = 0;
	int losses = 0;

	//declare a variable to store menu choice
	int menuChoice;

	//menu choice updated by the return value of the  menu() function
	do
	{
		//bring user choice from menu
        	menuChoice = menu();

		if (menuChoice == 1)
		{
			if (guessNumber() == 1)
			{
				wins++;
			}
			else 
			{
				losses++;
			}
		}
		else if (menuChoice == 2)
		{
			if (highLow() == 1)
			{
				wins++;
			}
			else
			{
				losses++;
			}
		}
		else if(menuChoice == 3)
		{
			if (collectPairs() == 1)
			{
				wins++;
			}
			else
			{
				losses++;
			}
		}
		else if(menuChoice == 4) 
                {
                        if (mathQuiz() == 1)
                        {
                                wins++;  
                        }
                        else
                        {
                                losses++;
                        }
                }

		else if (menuChoice == 5)
		{
			viewStats(wins,losses);
		}
		else if (menuChoice == 6)
		{
			wins = 0;
			losses = 0;
			cout << "Statistics Reset!";
		}
		else if (menuChoice == 7)
		{
			printRules();
		}		
		else if (menuChoice == 0)
		{
			viewStats(wins, losses);
			cout << "\n" << "Thanks for playing!" << "\n";
		}


	} while (menuChoice < 8 && menuChoice >= 0);
	
	return 0;
}

/*Function definition for COLLECTPAIRS
obtain a pair of each type: 1's, 2's, 3's, 4's, 5's, and 6's when a pair of 
dice are rolled. Simulate rolling a pair of dice 100 times.
When encounter the first (and only the first) of any pair, print out a message indicating that that 
pair has been found and accounted for. The messages of the pairs found must print out in the order in which they were found.
After the 100 rolls, if the user has encountered a pair of every kind, they win.
If the user did not encounter all of the pairs after their 100 rolls, they lose. */

int collectPairs()
{
    bool found1 = false, found2 = false, found3 = false;
    bool found4 = false, found5 = false, found6 = false;
    bool allPairsFound = false;

    //Rolling a pair of dice 100 times for pairs!   
    for (int roll = 1; roll <= 100; roll++) 
	{
        	int dice1 = rand() % 6 + 1;  
        	int dice2 = rand() % 6 + 1;

		// A pair was rolled
        	if (dice1 == dice2) 
		{
            		switch (dice1) 
			{
                		case 1:
                    			if (!found1) 
					{
                        			found1 = true;
						cout << "PAIR OF " << dice1 << "s found\n";
                    			}
                    			break;
                		case 2:
                    			if (!found2) 
					{
                        			found2 = true;
						cout << "PAIR OF " << dice1 << "s found\n";
                    			}
                    			break;
                		case 3:
                    			if (!found3) 
					{
                        			found3 = true;
						cout << "PAIR OF " << dice1 << "s found\n";
                    			}
                    			break;
                		case 4:
                    			if (!found4) 
					{
                        			found4 = true;
						cout << "PAIR OF " << dice1 << "s found\n";
                    			}
                    			break;
                		case 5:
                    			if (!found5) 	
					{
                        			found5 = true;
						cout << "PAIR OF " << dice1 << "s found\n";
                    			}
                    			break;
                		case 6:
                    			if (!found6) 	
					{
                        			found6 = true;
						cout << "PAIR OF " << dice1 << "s found\n";
                    			}
                    			break;
            		}
        	}

        // Check if all pairs have been found
        if (found1 && found2 && found3 && found4 && found5 && found6) {
            allPairsFound = true;

	    //stop rolling
            break;
        }
    }

    // Check if user win or loss condition
    if (allPairsFound)
    {    
	cout << "You WIN!";
	return 1;
    }
    else
    {	
        cout << "Sorry, you lose.";
	return 0;
}

}

/*Function definition for GUESSNUMBER
Generate a random number between 1 and 100.
The user then has 6 tries to guess the secret number. 
If they guess the number within 6 tries, they win.
If they do not guess the number within 6 tries, they lose.*/
int guessNumber()
{
	int hiddenNum = rand() % 100 + 1;
	int userGuess;

	cout << "Guess the Number, 1 --> 100!" << "\n";
	
	for(int attempt = 1; attempt < 7; attempt++)
	{
		cout << "Attempt " << attempt << "/6 : ";
		cin >> userGuess;

		if (userGuess < hiddenNum)
		{
			cout << "TOO SMALL." << "\n";
		}
		else if (userGuess > hiddenNum)
		{
			cout << "TOO BIG." << "\n";
		}
		else if (userGuess == hiddenNum)
		{
			cout << "You WIN!" << endl;
			return 1;
		}			
	}

	cout << "Sorry, you lose. The number was" << hiddenNum << endl;	 
	return 0;
}

//(Bonus:) Enter a difficulty setting (1: easy, 2: medium, 3: hard) - 


/*Function definition for HIGHLOW
Generate a random number between 1 and 1000 as the starting random number.
The user needs to tell us whether the NEXT random number will be Higher or Lower than the current one, 
denoting this by entering H for higher or L for lower. The user must enter H or L here. Do not let them 
proceed until they do. If the user succeeds in guessing high or low correctly 5 times in a row, they win. 
If the user gets any of their guesses wrong before 5 correct guesses, they lose*/

int highLow()
{
	//checking if the next number will be higher or lower
	
	cout << "High or Low! Stay alive for 5 rounds to win! (Numbers range from 1 to 1,000)" << endl;

	for(int round = 1; round < 6; round++)
	{
		int theNum = rand() % 1000 + 1;
		int nextNum = rand() % 1000 + 1;
		char userGuess;
		cout << "Round " << round << " of 5. The number is" << theNum << "\n";
		cout << "\t... is the next number [H]igher or [L]ower?: ";
		cin >> userGuess;
		
		while (userGuess != 'H' && userGuess != 'L')
                {
                        cout << "Enter H or L:";
                        cin >> userGuess;
                }

		if((theNum < nextNum) && (userGuess == 'H'))
                {
                        cout << "The next number is: " << nextNum << "\n";
                        cout << "Correct!" << endl;
                }
		else if ((theNum > nextNum) && (userGuess == 'L'))
		{
			cout << "The next number is: " << nextNum << "\n";
                        cout << "Correct!" << endl;
		}
		else if ((theNum > nextNum) && (userGuess == 'H')) 
		{
			cout << "The next number is: " << nextNum << "\n";
			cout << "Sorry, you lose.";
			return 0;
		}
		else if ((theNum > nextNum) && (userGuess == 'L'))
                {   
                        cout << "The next number is: " << nextNum << "\n";
                        cout << "Sorry, you lose.";
			return 0;
                }


		theNum = nextNum;   
	}
	
		return 1;
}
/*Function definition for MATHQUIZ
Generate three random integers between the values of 0 and 10
Generate two random mathematical symbols (generate a random int value and correspond it to a symbol).*/

int mathQuiz()
{
	int userChoice;
	int num1;
	int num2;
	int num3;
	char sym1;
	char sym2;
	int userAnswer;
	int theAnswer;

	cout << "(Bonus:) Enter a difficulty setting (1: easy, 2: medium, 3: hard) - " ;
	cin >> userChoice;

	if(userChoice == 1)
	{
		num1 = rand() % 10;
		num2 = rand() % 10; 
		num3 = rand () % 10;
	}
	else if(userChoice == 2)
	{
		num1 = rand () % 21 - 10;
		num2 = rand () % 21 - 10;
		num3 = rand () % 21 - 10;
	}
	else if(userChoice == 3)
	{
		num1 = rand () % 31 - 10;
		num2 = rand () % 31 - 10;
		num3 = rand () % 31 - 10;
	}
	else
	{
		cout << "Enter 1, 2, or 3... ";
		cin >> userChoice;
	}

	switch (rand() % 3 + 1)
        {
                case 1:
                        sym1 = '+';
                        break;
                case 2:
                        sym1 = '-';
                        break;  
                case 3:
                        sym1 = '*';
                        break;
        }
        
        switch (rand() % 3 + 1)
        {
                case 1:
                        sym2 = '+';
                        break;
                case 2: 
                        sym2 = '-';
                        break;
                case 3:
                        sym2 = '*';
                        break;
        }
         
	if (sym1 == '*' && sym2 == '*'){
    		theAnswer = num1 * num2 * num3;
	}else if (sym1 == '*'){
    		if (sym2 == '+'){
        		theAnswer = (num1 * num2) + num3;
    		}else{
        		theAnswer = (num1 * num2) - num3;
		}
	}else if (sym2 == '*') {
    		if (sym1 == '+')
        		theAnswer = num1 + (num2 * num3);
    		else
        		theAnswer = num1 - (num2 * num3);
	}else if (sym1 == '-'){
                if (sym2 == '+'){
                        theAnswer = (num1 - num2) + num3;
                }else{
                        theAnswer = (num1 - num2) - num3;
                }
        }else if (sym2 == '-') {
                if (sym1 == '+')
                        theAnswer = num1 + (num2 - num3);
                else
                        theAnswer = num1 - (num2 - num3);
        }else if (sym1 == '+'){
                if (sym2 == '+'){
                        theAnswer = (num1 + num2) + num3;
                }
        }



	cout << "Solve: " << num1 << sym1 << num2 << sym2 << num3;
	cout << "\n" << " =";
	cin >> userAnswer;

	if (userAnswer == theAnswer)
	{
		cout << "CORRECT!";
		return 1;
	}	
	else
	{
		cout << "Wrong. Answer: " << theAnswer;
		return 0;
	}
}

/*Function definition for VIEWSTATS
takes in two integer parameters representing the total number of wins and losses that the user has.*/

void viewStats(int wins, int losses)
{
	double totalGames;
	double percentage = 0.0;

	cout << "STATISTICS:" << "\n";
	cout << "-------------------------" << "\n";
	cout << "Wins: " << wins << "\tLosses: " << losses << "\n";

	totalGames =  wins + losses;
      
        percentage = static_cast<double>(wins)/totalGames;
	cout << "Total Win Percent:  " << percentage*100 << "%";

}

/*Function definition for MENU
this function prints the menu to the user and allow them to then select any of the options. 
If they select a number besides one on the menu, print an error message and force them to 
re-enter until they enter a valid value */

int menu()
{
	cout << "GAME MENU:" << "\n";
	cout << "--------------------------" << "\n";
	cout << "1: PLAY Guess the Number" << "\n";
	cout << "2: PLAY High Low" << "\n";
	cout << "3: PLAY Collect Pairs" << "\n";
	cout << "4: PLAY Math Quiz" << "\n";
	cout << "5: VIEW Statistics" << "\n";
	cout << "6: RESET Statistics" << "\n";
	cout << "7: RULES" << "\n";
	cout << "0: QUIT" << "\n";
	cout << "--------------------------" << "\n";
	cout << "> ";

	int choice;

	//users choice
	cin >> choice;

	//spaces
	cout << "\n" << "\n";
	
	while(choice > 7 || choice < 0)
        {
                cout << "Enter an item on the Menu: ";
		cin >> choice;
        }
	
	//return value out
	return choice;

}

/*Function definition for PRINTRULES
this function prints the rules of all of the games available to the user in this program
that is all this function is responsible for*/
void printRules()
{
	cout << "\nRULES:\n\nGuess the Number Game:\n";
	cout << "You'll only get 6 tries to guess a number between 1 and 100!\n";
	cout << "Guess Wisely!\n\n";
	cout << "High/Low Game:\nMake it through 5 rounds of guessing whether the next random number\n";
	cout << "between 1 and 1,000 is higher or lower than the previous, and you win!\n\n";
	cout << "Collect the Pairs Game:\nRoll two dice 100 times. If in the 100 times you roll a pair\n";
	cout << "of each type (1's, 2's, 3's, 4's, 5's, 6's) at least once, then you win!\n\n";
	cout << "Math Quiz Game:\nAnswer the math equation correctly to win!\n\n";
	return;
}
