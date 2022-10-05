#include <bits/stdc++.h>
#define ll long long

using namespace std;

// check whether position is safe to place our desired number
bool isSafe(int b[][9], int r, int c, int num, int n)
{
	// checking  rows
	for (int i = 0; i < n; i++)
	{
		// check if num is int the row
		if (num == b[r][i])
			return false;
	}
	// For columns
	for (int i = 0; i < n; i++)
	{
		if (num == b[i][c])
			return false;
	}
	// checking the square box
	int sqt = sqrt(n);
	int start = r - r % sqt;
	int end = c - c % sqt;
	for (int i = start; i < start + sqt; i++)
	{
		for (int j = end; j < end + sqt; j++)
		{
			// check if num is already present in the block or not
			if (num == b[i][j])
				return false;
		}
	}
	return true;
}

bool SudokuSolver2(int board[][9], int r, int c, int n)
{
	// base case
	if (r == n)
	{

		// print Matrix
		return true;
	}
	// If we have reached end of our column just change the row
	if (c == n)
	{
		return SudokuSolver2(board, r + 1, 0, n);
	}

	// Skip prefilled cell
	if (board[r][c] != 0)
	{
		return SudokuSolver2(board, r, c + 1, n);
	}
	// fill the current cell with possible number of options
	for (int num = 1; num <= 9; num++)
	{
		// checking whether number can be placed or not
		if (isSafe(board, r, c, num, n))
		{
			board[r][c] = num;
			if (SudokuSolver2(board, r, c + 1, n))
			{
				return true;
			}
			// backtrack
			board[r][c] = 0;
		}
	}
	return false;
}

int main()
{
	// int board[9][9] = {{0, 0, 0, 2, 6, 0, 7, 0, 1},
	// 									 {6, 8, 0, 0, 7, 0, 0, 9, 0},
	// 									 {1, 9, 0, 0, 0, 4, 5, 0, 0},
	// 									 {8, 2, 0, 1, 0, 0, 0, 4, 0},
	// 									 {0, 0, 4, 6, 0, 2, 9, 0, 0},
	// 									 {0, 5, 0, 0, 0, 3, 0, 2, 8},
	// 									 {0, 0, 9, 3, 0, 0, 0, 7, 4},
	// 									 {0, 4, 0, 0, 5, 0, 0, 3, 6},
	// 									 {7, 0, 3, 0, 1, 8, 0, 0, 0}};

	// taking user input
	int board[9][9];
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			cin >> board[i][j];
		}
	}

	if (SudokuSolver2(board, 0, 0, 9)) // If function returs true just display the board
	{
		for (int i = 0; i < 9; i++)
		{
			for (int j = 0; j < 9; j++)
			{
				cout << board[i][j] << " ";
			}
			cout << "\n";
		}
	}
	else
	{
		cout << "Can't solve sudoku\n";
	}
	return 0;
}