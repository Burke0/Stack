/*
 * prog3.cpp
 *
 *  Created on: Oct 29, 2019
 *      Author: J. Alex Burke
 */
# include <iomanip>
# include <iostream>
#include "Stack.h"
using namespace std;
int size;
void displayNQueensSolution(int** grid);
bool isConfrontational(int** grid, int row, int col);
bool solveNQueens(int** grid);
int main()
{
	cout<<"Enter # of Queens: "<<endl;
	cin>>size;
	int** grid= new int*[size];
	for(int i=0; i<size; i++)
		grid[i]=new int[size];

	for(int i=0; i<size; i++)
	{
		for(int j=0; j<size; j++)
			grid[j][i]=0;
	}
	if(solveNQueens(grid))
	{
		cout<<"Solution Found!"<<endl;
		displayNQueensSolution(grid);
	}
	else
		cout<<"No Solution!"<<endl;

	for(int i = 0; i < size; i++)
	{
		delete [] grid[i];
	}
	delete [] grid;

	return 0;
}
/*solveNQueens attempts to find a solution for n queens using backtracking.
 * It calls isConfrontational to see if a queen can placed somewhere on that row.
 * If it finds a spot, it breaks the loop, increments row, and continues to the next row.
 * If a queen can not be placed on that row, it pops the last queen of the stack.
 * Then, it goes back a row and moves the queen forward to find another spot for it.
 * If a position is not found and all queens are off the stack, the function returns false to show a solution could not be found.
 *  */
bool solveNQueens(int** grid)
{
	Stack queensStack;
	int row=0,prevCol=0;
	Position queen;
	while(row<size)
	{
		bool placed=false;
		for(int col=0+prevCol; col<size; col++)//while(placed==false or something
		{
			if(isConfrontational(grid, row, col)==false)
			{
				placed=true;
				queen.row=row;
				queen.col=col;
				queensStack.push(queen);
				grid[queen.row][queen.col]=1;
				row++;
				prevCol=0;
				break;
			}
		}
		if(!placed)
		{
			if(queensStack.isEmpty())
				return false;
			else
			{
				queensStack.pop(queen);
				grid[queen.row][queen.col]=0;
				row--;
				prevCol=queen.col+1;
			}
		}
	}

		return true;

}
//This function outputs the array with the queens locations marked as Q's and empty space as -'s
void displayNQueensSolution(int** grid)
{
	for(int j=0; j<size; j++)
	{
		for(int i=0; i<size; i++)
		{
			if(grid[i][j]==0)
				cout<<"-";
			else if(grid[i][j]==1)
				cout<<"Q";
		}
		cout<<endl;
	}

}
//checks row, column, upper left, upper right, lower left, and lower right diagonals in grid array for a queen from specified row and column index.
//true: it is confrontational. false: it is safe
bool isConfrontational(int** grid, int row, int col)
{
	int i,j;
	for(i=0; i<size; i++)
		if(grid[row][i]==1)
			return true;
	for(i=0; i<size; i++)
		if(grid[i][col]==1)
			return true;
	for(i=row, j=col; i>=0 && j>=0; i--,j--)//upper left diagonal
		if(grid[i][j]==1)
			return true;
	for(i=row, j=col; i>=0 && j<size;i--,j++)//upper right diagonal
		if(grid[i][j]==1)
			return true;
	for( i=row, j=col; i<size && j<size; i++,j++)//lower right diagonal
		if(grid[i][j]==1)
			return true;
	for(i=row,j=col;i<size && j>=0 ;i++,j--)//lower left diagonal
		if(grid[i][j]==1)
			return true;
	return false;
}




