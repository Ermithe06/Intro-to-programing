/* Name: Ermithe Tilusca
Date: 3/23/25
Assignment: #5
Due Date: 3/27/25
About this project: creats an array of size SIZE. Declare SIZE as a constant variable and set it to some value between 5 and 20, use it as the size of our array. 
The value it stores can change from run to run for testing different size arrays. It can be used referring to the array's max SIZE 
(instead of using a hard-coded literal value like 10 or 20). 
Assumptions: assume SIZE will be between 5 and 20 and that the user will 
always enter the appropriate number of values, and that these values will 
be integers. 

All work below was performed by Ermithe Tilusca*/

#include <iostream>
#include <cstdlib> //for srand(), rand()
#include <ctime> // for time()
#include <iomanip> //for decimal places
#include <cmath> 
using namespace std;

//function declaration
void printArray (int list[], const int SIZE);
void getMinMax (int list[], const int SIZE, int &, int &);
int getTheSum (int list[], const int SIZE);
void getRotation (int list[], const int SIZE);
void getSortedArray (int list[], const int SIZE);
void getMedian (int list[], const int SIZE, double &);
void getHighestFrequency (int list[], const int SIZE);

//main function
int main()
{
	//seed the random number generator
        srand(time(0));
		
	//size of the array
	const int SIZE = 7;
	int list [SIZE];
	cout << "When SIZE = " << SIZE << "\n\n";
	
	//print the funtion called printArray
	printArray(list, SIZE);

	// declare min and max variables
        int min;
	int max;
    
        //print the function to get min and max
        getMinMax(list, SIZE, min, max);
	cout << "Minimum: " << min << "\n";
	cout << "Maximum: " << max << "\n";
	
	//print the function called sum
	int theSum = getTheSum(list, SIZE);
	cout << "Sum: " << theSum << "\n";

	//set to 1 decimal place precision
	cout << fixed << showpoint << setprecision(1);

	//calculate the mean of the array
	double mean = (theSum/static_cast<double>(SIZE));
	cout << "Mean: " << mean << "\n";

	//print the function to get the rotated array
	getRotation(list, SIZE);

	//print the function to get the sorted array
	getSortedArray (list, SIZE);

	//print the function to get the median
	double median;
    	getMedian (list, SIZE, median);
    	cout << "Median: " << median << "\n";
	    
	//print the function to get the highest frequency and the value(s)
	getHighestFrequency (list, SIZE); 
   
	return 0;
}

//function definition

//get the data of the array
void printArray(int list[], const int SIZE)
{
	//filling up the array manually or randomly
	char userChoice;
	
	do
	{
		cout << "Enter (c)ustom or (r)andom values? --> ";
		cin >> userChoice;
	}while(userChoice != 'c' && userChoice != 'r');
	
	if(userChoice == 'r')
	{
		for (int i = 0; i < SIZE; i++) 
		{
			list[i] = rand() % 100 + 1;  // Random number between 1 and 100
        	}
    	}
	else
	{
		cout << "Enter " << SIZE << " numbers: ";
		for (int i = 0; i < SIZE; i++)
        	{
			cin >> list[i];
		}
	}
	cout << "\n";
	
	//display the data that was filled in and add comma between elements
	cout << "Array analysis:" << "\n";
	cout << "-------------------------------" << "\n";
	cout << "Your array: ";
	for (int i = 0; i < SIZE; i++)
	{
		cout << list[i];
        	if (i < SIZE - 1) // Does not add a comma after the last element
                cout << ",";
        }
	cout << "\n\n";
}

//Function to get the minimum and maximum of the array
void getMinMax (int list[], const int SIZE, int & min, int & max)
{
	//setting max and min to the first element
        min = list[0];
        max = list[0];
        
        //Try to find any element smaller than the first element and assign it to minimum, repeat until all elements are scanned to find minimum
        for(int i = 1; i < SIZE; i++)
        {
                if(list[i] < min)
                {
                        min = list[i];
                }
        }
                
        //Try to find any element bigger than the first element and assign it to maximum, repeat until all elements are scanned to find maximum
        for(int i = 1; i < SIZE; i++)
        {
                if(list[i] >  max)
                {
                        max = list[i];
                }
        }             
}

//Function to get the sum of the array
int getTheSum(int list[], const int SIZE)

{
	int sum = 0; //Initialize sum to 0

	for (int i = 0; i < SIZE; i++)
	{
		sum += list[i]; //add the elements
	}
	return sum; //return the sum
}

//Function to rotate the array to the right by half the array length
void getRotation (int list[], const int SIZE)
{
	//get the array into two halves
	int half = ceil(static_cast<double>(SIZE)/2.0);

	for(int i = 0; i < half; i++) //loop 1 less than half, so rotate each element the number half is
	{
		 int temp = list[SIZE - 1]; // store the last value

		for(int j = SIZE - 1; j >= 0; j --) //j descend, so the last value move the second last value to take the last value place, repeat the amount half is
		{
			list[j] = list [j-1];
		}

		list[0] = temp; // move last value to the front
	}
    	// Print the rotated array
    	cout << "Rotated: ";
    	for (int i = 0; i < SIZE; i++) 
	{
        	cout << list[i];
		if (i < SIZE - 1) // Does not add a comma after the last value
                {
			cout << ",";
		}
    	}
    cout << "\n";
}

//Function to sort array's content
void getSortedArray (int list[], const int SIZE)
{
	//bubble sort algorithm 
	for (int i = 0; i < SIZE - 1; i++) 
    	{
        	for (int j = 0; j < SIZE - 1 - i; j++) 
        	{ 
            		if (list[j] > list[j + 1]) // If the first value is greater than the second, swap them 
            		{
                		int temp = list[j];
                		list[j] = list[j + 1];
                		list[j + 1] = temp;
            		}
        	}
	}

 	//Print the sorted array
        cout << "Sorted: ";
        for (int i = 0; i < SIZE; i++)
        {       
                cout << list[i];
                if (i < SIZE - 1) // Does not add a comma after the last element
                {       
                        cout << ",";
                }
        }
    	cout << "\n";
}


//Function to get median
void getMedian(int list[], const int SIZE, double & median)
{
    		//Calculate the median
		if(SIZE%2 == 1) //calculate the median when SIZE is odd
		{
			median = static_cast<double>(list[(SIZE - 1)/2]);
		}
		else //calculate median when SIZE is even
		{
			double lower= list[(SIZE)/2];
			double higher =  list[(SIZE/2)-1];
			double total = lower + higher;
			median = total/2.0;
		}
}

//Function to get highest frequency and the value(s)
void getHighestFrequency(int list[], const int SIZE)
{
	//declare and initialized highestFrequency, value
	int highestFrequency = 1;
	int value = 1;	

	//set firstNum to false
	bool firstNum = false;

	//find highest frequency
        for (int i = 0; i < SIZE - 1; i++)
        {
		int frequency = 1; //declare and initialized frequency
		for (int j = i + 1; j < SIZE; j++)
                {
			if(list[i] == list[j])
                	{
                        	frequency++;
                	}
		}

		if (frequency > highestFrequency)
		{
			highestFrequency = frequency;			
		}
	}
	
	cout << "Highest Frequency Count: " << highestFrequency << "\n";
	cout << "Value(s) that appear " << highestFrequency << " times: ";	

	//print the value when it is at highest frequency	
	for(int i = 0; i < SIZE; i++)
	{
        	if(list[i] == list[i + highestFrequency - 1]) 
        	{
                	value = list[i];
			
			//print no space before the first value number, but does before all the other values
			if(firstNum == true)
			{
				cout << " ";
			}
			else
			{
				firstNum = true;
			}

			cout << value;
        	}
	}
	
	cout << "\n";
}
