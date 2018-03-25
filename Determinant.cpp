/*******************************************************************
 * Program Name: Determinant.cpp
** Author: Alexandra Carper
** Date: 1/11/2018
** Description: The determinant function takes the dynamically 
		allocated 2d array and the size the user chose in 
		the main function as parameters and calculates
		the determinant of the matrix based on its size.
*********************************************************************/
#include <iostream>
#include "Determinant.hpp"

int determinant(int **matrix, int size)
{	
	int left = 1;				//Initialize left and right							//diagonals
	int right = 1;
	int det;
				
	if(size == 2)					//If 2x2 matrix
	{
		for(int i = 0; i < size; i++)		//Loop through rows
		{
			for(int j = 0; j < size; j++)	//Loop through
								//columns
			{
				if(i == j)		//If (0,0) or (1,1)
				{
					left *= matrix[i][j];	//Multiply to 
								//get a*d
				}
				
				if((i + j) == (size - 1)) 	//If (0,1) or
								//(1,0)
				{
					right *= matrix[i][j];	//Multiply to 
								//get b*c
				}
			}
		}
		
		det = left - right;		//Subtract right from 
						//left diagonal
	}
	
	if(size == 3)
	{
		int a = matrix[0][0],		//Set matrix values equal
		    b = matrix[0][1],		//to letters to make
		    c = matrix[0][2],		//calculation easier
		    d = matrix[1][0],
		    e = matrix[1][1],
		    f = matrix[1][2],
		    g = matrix[2][0],
		    h = matrix[2][1],
		    i = matrix[2][2];
	
		//Calculate determinant
		det = a * (e * i - f * h) - b * (d * i - f * g) + 
			c * (d * h - e * g);		
	}

	
	return det;
}			
