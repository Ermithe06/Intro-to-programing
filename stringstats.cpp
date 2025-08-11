/* Name: Ermithe Tilusca
Date: 4/2/2025
Assignment: #6
Due Date: 4/8/2025
About this project: prompt the user to enter a sentence, this can be any 
numbers of words/characters/spaces, with the newline character.Secondly, 
prompt the user for a WORD. This should be just a single word, no 
whitespace. Print out the statistics regarding the sentence. Ask the user 
if they wish to enter another sentence/word pair and perform the task 
over again. 
Assumptions: assume the sentence string that the user enters will be no 
more than 100 characters long. Also assume the maximum length of any word 
entered (whether a part of the sentence or just the standalone word) is 
20 characters. Assume that the sentence the user enters will have only 
exactly one whitespace between each word. Assume that anytime the user is 
prompted to enter only one word, that they will do so.

All work below was performed by Ermithe Tilusca */


#include <iostream>
#include <iomanip>
#include <cctype>
#include <string>
using namespace std;

//function declaration
int numPunc (const string & sentence);
int numVowels (const string & sentence);
int numWords (const string & sentence);
void wordLengths (const string & sentence);

int main()
{
	bool keepGoing = false; //initialized keepGoing to false
        
	//run the code once and repeat while user choose to repeat the process
	do
	{
		//prompt the user to enter a sentence
		string sentence;
		cout << "Enter a sentence: ";
		getline(cin, sentence); //string ends when user presses enter

		//prompt the user for a WORD
		string word;
		cout << "Enter a word: ";
		cin >> word; //a single word, no whitespace
		cout << "\n";

		//print out the statistics regarding the sentence
		cout << "SENTENCE ANALYSIS:" << "\n\n";

		//number of punctuation characters, vowels, and words
		int countPunc = numPunc(sentence); //store the function
		cout << "Punctuation Characters: " << countPunc << "\n";
		int countVowels = numVowels(sentence); //store the function
		cout << "Vowels: " << countVowels << "\n";
		int countWords = numWords(sentence); //store the function
		cout << "Words: " << countWords << "\n";

		//print the function to get the table of word lengths
		cout << "\n";
		cout << "Word Lengths: " << "\n";
		wordLengths(sentence);

		//check if the word is in the sentence
		string partOf = " IS NOT"; //initialize the string to IS NOT 
		int match = 0; //set the amount of letters in word match to sentence to 0	

		//check all the letters until there is less letters left in sentence than there is in word
		for(int i = 0; i <= sentence.size() - word.size(); i++)
		{
			match = 0; //reset match to 0 after each check round

			for(int j = 0; j < word.size(); j++) //check the letters in word
			{
				//if it is the same as the one in sentence, the amount of match find goes up and it check the next letters in word and sentence 
				if (sentence[i+j] == word[j])
				{
					match++;
		
				}
				else //if a letter in word is different from the one in sentence, it stops counting
				{
					break;
				}
			}
	
			if(match == word.size()) //if all the letters in word match those of a part of the sentence, word is part of the sentence
			{
				partOf = " IS";
				break;
			}
		}

		cout << "The word: \"" << word << " \"" << partOf << " part of the sentence you entered." << "\n\n"; 

		string userChoice; //declare userChoice string

		//user enter if they want to do another sentence
		cout << "Enter another sentence/word for analysis (yes/no): ";
		cin.ignore();
		getline(cin, userChoice);

		for(int i = 0; i < userChoice.size(); i++) //turn user response to lowercase
        	{
			userChoice[i] = tolower(userChoice[i]);
		} 
		
		while(userChoice != "yes" && userChoice != "no") //invalid response will promt the user to enter yes or no
		{
			cout << "Enter yes or no: ";
			getline(cin, userChoice);
		}
		if(userChoice == "yes") //if user choose yes, they want to keep going
                {
                         keepGoing = true;
                }       
                else if(userChoice == "no") //if user choose to not do another sentence, break
                {               
                        keepGoing=false;
                }         

		cout << "\n";		
	}while(keepGoing == true);

     return 0;
}

//function definition

//function to get number of punctuations in the sentence
int numPunc (const string & sentence)
{
	//initialized number of punctuations in sentence to zero
	int countPunc = 0;
        
	//check each character one at a time to see if it is a punctuation to update countPunc
        for(int i = 0; i < sentence.size(); i++)
        {
                if(ispunct (sentence[i]) != 0)
                         countPunc++;
        }
	return countPunc; //return updated number of punctuations
}

//function to get number of vowels in the sentence
int numVowels (const string & sentence)
{
	//initialized number of vowels in sentence to zero
	int countVowels = 0;
     
	//check each character one at a time to see if it is a vowel to update countVowel
        for(int i = 0; i < sentence.size(); i++)
        {                
                char lowerCase  = tolower(sentence[i]); //convert the whole sentence to lowercase
                if(lowerCase  == 'e' || lowerCase == 'i' || lowerCase == 'o' || lowerCase  == 'u' || lowerCase == 'a')
                         countVowels++;
        }
        return countVowels; //return updated number of vowels
}

//function to get number of words in the sentence
int numWords (const string & sentence)
{
	//initialized number of words in sentence to zero
	int countWords = 0;
        
	//check to see if there is a character or space
        for(int i = 0; i < sentence.size(); i++)
        {
                if(isspace (sentence[i]) != 0) //when there is a space update countWords, count space as a word then remove it
                {   
			countWords++; 
			if(isspace (sentence[i]) != 0 && isspace (sentence[i+1]) != 0)
			{
				countWords--;
			}
		}
        }
        
        countWords = countWords + 1; // add 1 to number of spaces in the sentence to get number of words
        return countWords; //return updated number of words
}

//function to get the length of each word in sentence
void wordLengths(const string &sentence)
{
	int table[21] = {0}; // an array of 21 integers that are initialized to zero
    	int wordSize = 0; //initialized the length of words to zero

    	// count the length of each words in sentence
    	for (int i = 0; i < sentence.size(); i++)
    	{
        	if (isalnum(sentence[i]) || ispunct(sentence[i])) //count punctuation, letters, and numbers as part of a word length 
        	{
            		wordSize++;
        	}
        	else if (isspace(sentence[i])) // end the word size when there is a space
        	{
            		if (wordSize > 0 && wordSize < 21) //count the amount of words equal each length 
            		{
                		table[wordSize]++;
            		}	
            		wordSize = 0; //restart word size, ready to count the next word size
        	}
    	}

	if (wordSize > 0 && wordSize < 21) //the last word of the sentence get added to the table 
    		{
        		table[wordSize]++;
    		}

	//print out the word lengths that are in the sentence and how much word is each length
	for (int i = 1; i < 21; i++)
    	{
        	if (table[i] > 0)
        	{
            		cout << i << " characters long: " << table[i] << " word";
            		if (table[i] >= 2) //if a word appear two or more times, put an s behind word to make it plural
			{
                		cout << "s";
			}
            		cout << "." << "\n"; //always print a period
        	}
	}
	cout << "\n";
}

