/*********************************************************************
 * ** Program name: Matrix.cpp
 * ** Author: Alexandra Carper
 * ** Date: 1/11/2018
 * ** Description: The readMatrix function prompts the user for the 
 * **			integers in the matrix and validates the user 
 * 			input. It takes the 2d array that was 
 *			dynamically allocated in the main function and 
 *			the size that was chosen to fill the array with
 *			the values.
 * *********************************************************************/
#include <iostream>
#include "Matrix.hpp"
using std::cout;
using std::cin;
using std::endl;

int** readMatrix(int** matrix, int size)		//Initialize array and								//size
{

	bool inputValidation = false;			//Initialize to false

	cout << "Enter integers starting with first row of matrix." << endl;
	while(!inputValidation)
	{
		inputValidation = true;			//Assume valid input
		for(int i = 0; i < size; i++)		//Loop through rows
		{
			for(int j = 0; j < size; j++)	//Loop through columns
			{
				cin >> matrix[i][j];	//User input
				if(cin.fail())		//If incorrect input
							//data type
				{
					cin.clear();	//Clear input stream
					cin.ignore();	//Skip newline 

					cout << "Please enter an integer."
					<< endl;	
					
					cin >> matrix[i][j];	//Prompt again
				}
			}
		}
	}
	
	return matrix;					//Return array to main
}

