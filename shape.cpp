/* Name: Ermithe Tilusca
Date: 1/29/2025
Assignment: #2
Due Date: 2/4/2025
About this project: A program that calculates the area and perimeter of
different geometric shapes. The user can choose between a circle,
rectangle, and triable, and the program will calculate and display the
area and the perimeter of the chosen shape using appropriate formulas and
if/else if/else statements.
Assumptions: Assumes that the user will always enter positive, non-zero 
numerial values for all numerical entries. Assumes that the user will 
only enter single characters (not words) when prompted for menu choices.
       
All work below was performed by Ermithe Tilusca */
       
       
#include <iostream>
#include <iomanip>  
#include <cmath>
using namespace std;
       
int main()
{
        //constant variable, PI is always th same value
        const double PI = 3.14159;
       
        //char variable for user's shape choice
        char shape;
       
        //double variables for circle  
        double radius;
        double Cperimeter;
        double Carea;
       
        //variables for rectangle
        double Rlength;
        int Rwidth;
        double Rperimeter;
        double Rarea;
       
        //double variables for triangle
        double lengthBigSide;
        double lengthSmSide1;
        double lengthSmSide2;
        double semiPerimeter;
	double Tperimeter;
	double Tarea;
	       
        //present menu
        cout << "Choose a shape:" << endl;  
        cout << "C - Circle" << endl;
        cout << "T - Triangle" << endl;
        cout << "R - Rectangle" << endl;
        cout << "Choice: ";
               
        //Users' shape choice
        cin >> shape;
        cout << endl;
         
        //set one decimal place
        cout << fixed << showpoint << setprecision(1);
               
        //if user choice is a circle
        if (shape == 'C' )
        {              
                //the circle's radius
                cout << "Radius: ";
                cin >> radius;
       
                //the circle's perimeter
                Cperimeter = 2 * PI * radius;
                cout << "PERIMETER: " << Cperimeter << endl;
       
                //the circle's area
                Carea = PI * (radius*radius);
                cout << "AREA: " << Carea << endl;
        }
       
         else if (shape == 'R')
        {
                //the rectangle's length and width
                cout << "Length: ";
                cin >> Rlength;
                cout << "Width: ";  
                cin >> Rwidth;
         
                //the rectangle's perimeter
                Rperimeter = 2 * (Rlength + Rwidth);
                cout << "PERIMETER: " << Rperimeter << endl;
       
                //the rectangle's area  
                Rarea = Rlength * Rwidth;
                cout << "AREA: " << Rarea << endl;
        }
               
        else if (shape == 'T')
        {
                //triangle's side information
                cout << "Length of the Biggest side: ";
                cin >> lengthBigSide;
                cout << "Length of the two smaller sides: ";
                cin >> lengthSmSide1 >> lengthSmSide2;
               
         	//error, biggest side is not larger than smaller sides
                if (lengthBigSide < lengthSmSide1 || lengthBigSide < lengthSmSide2)
                {
                        cout << "Invalid entries, ";
                        cout <<"make sure you enter the biggest side value first." << endl;
		}
       
		//sides entered by user do not form a valid triangle
                else if ((lengthSmSide1 + lengthSmSide2)< lengthBigSide)
        	{
			cout << "It is impossible for the side lengths of";
			cout << lengthSmSide1 << lengthSmSide2 << "and";
			cout << lengthBigSide << "to form the sides of a triangle." << endl;				
		}

		else
		{
			//no error, print out the triagle's perimeter and area
			Tperimeter = lengthSmSide1 + lengthSmSide2 + lengthBigSide;
			semiPerimeter = (lengthSmSide1 + lengthSmSide2 + lengthBigSide)/2;
			Tarea = sqrt( semiPerimeter * (semiPerimeter - lengthSmSide1) * (semiPerimeter - lengthSmSide2) * (semiPerimeter - lengthBigSide));		
			cout << "PERIMETER: " << Tperimeter << endl;
			cout << "AREA: " << Tarea << endl;
		}
	}
               
        else
        {
		//the user choose something that is not C, R, nor T        			       		
	        cout << "Invalid menu choice. Exiting program." << endl;
        }
         
        return 0;
}
     
