/*********************************************************************
 * ** Program name: Main.cpp
 * ** Author: Alexandra Carper
 * ** Date: 1/11/2018
 * ** Description: The main function asks the user to choose the size of
 * 		   the matrix, 2x2 or 3x3. It then dynamically allocates
 * 		   memory space for the matrix and uses readMatrix to 
 * 		   prompt the user to enter 4 or 9 integers to fill the 
 * 		   matrix. Main calls on the determinant function to 
 * 		   calculate the determinant, and finally displays both
 * 		   the matrix and the determinant.
 * *********************************************************************/

#include <iostream>
#include "Matrix.hpp"
#include "Determinant.hpp"
using std::cin;
using std::cout;
using std::endl;

int** readMatrix(int** matrix, int size);
int determinant(int** matrix, int size);

int main()
{ 
	int size;				//Declare size to pass
	
	
	cout << "Would you like to create a 2x2 or 3x3 matrix?" << endl;
	cout << "Enter 2 for 2x2 and 3 for 3x3." << endl;
	cin >> size;				//User inputs 2 or 3
	while(cin.fail())			//If not int
	{
		cout << "Error! Please enter a 2 or 3!" << endl;
		cin.clear();			//Clear stream
		cin.ignore();
		cin >> size;			//Try again
	}
	if(size != 2 && size != 3)		//If not 2 or 3
	{
		cout << "Error! Please enter a 2 or 3!" << endl;
		cin >> size;			//Try again
	}
	
	int** matrix = new int*[size];		//Dynamically allocate array
	for(int i = 0; i < size; i++)		//Loop to allocate columns
	{
		matrix[i] = new int[size];	
	}
	
	int** mat = readMatrix(matrix, size);	//Call readMatrix function
	int det = determinant(matrix, size);	//Call determinant function

	cout << "Matrix: " << endl;		//Display matrix
	for(int i = 0; i < size; i++)
	{
		for(int j = 0; j < size; j++)
		{
			cout << mat[i][j];
			cout << " ";
		}
	cout << endl;				//Use square format
	}
	
	cout << "|A| = " << det << endl;	//Display determinant
	
	for(int i = 0; i < size; i++)		//Delete allocated memory for 
						//rows
	{
		delete[] matrix[i];		
	}
	
	delete[] matrix;			//Delete pointer to array of 
						//pointers
	
	return 0;
}
