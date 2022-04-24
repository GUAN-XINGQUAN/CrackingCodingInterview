/*
Given an M*N matrix. Write an algorithm to do the following things:

(1) If an element equals to 0, set its entire row and column as 0 as well.
(2) If an element does not equal to 0, do nothing.

Example:
	Input:
		1	2	3
		4	0	6
		7	8	9
	Return:
		1	0	3
		0	0	0
		7	0	9
*/

#include<iostream>
#include<vector>
#include<cassert>
#include<queue>
#include<unordered_map>
#include<algorithm>
#include<stack>
#include<queue>
#include<string>
#include<sstream>
#include<unordered_set>

using namespace std;

void setRow(int row, vector<vector<int>>& matrix)
{
	for (int j = 0; j < matrix[0].size(); j++)
		matrix[row][j] = 0;
}

void setCol(int col, vector<vector<int>>& matrix)
{
	for (int i = 0; i < matrix.size(); i++)
		matrix[i][col] = 0;
}

// use the 1st row and column to store which row/column should be set to zeros.
// time complexity: O(M*N)
// space complexity: O(1)
vector<vector<int>> setZeroMatrix(vector<vector<int>> matrix)
{
	// edge case
	if (matrix.empty())
		return {};
	// general
	int m = matrix.size(), n = matrix[0].size();
	bool firstRowFlag = false, firstColumnFlag = false;
	// check if 1st column has zero
	for (int i = 0; i < m; i++)
	{
		if (matrix[i][0] == 0)
		{
			firstColumnFlag = true;
			break;
		}
	}
	// check if 1st row has zero
	for (int j = 0; j < n; j++)
	{
		if (matrix[0][j] == 0)
		{
			firstRowFlag = true;
			break;
		}
	}
	// check rest matrix
	for (int i = 1; i < m; i++)
	{
		for (int j = 1; j < n; j++)
		{
			if (matrix[i][j] == 0)
			{
				matrix[i][0] = 0;
				matrix[0][j] = 0;
			}
		}
	}
	// set rows to zeros
	for (int i = 0; i < m; i++)
	{
		if (matrix[i][0] == 0)
			setRow(i, matrix);
	}
	// set cols to zeros
	for (int j = 0; j < n; j++)
	{
		if (matrix[0][j] == 0)
			setCol(j, matrix);
	}
	// set 1st row and col
	if (firstRowFlag)
		setRow(0, matrix);
	if (firstColumnFlag)
		setCol(0, matrix);
	return matrix;
}

// time complexity: O(M*N)
// space complexity: O(M + N)
vector<vector<int>> setZeroMatrix1(vector<vector<int>> matrix)
{
	// edge case
	if (matrix.empty())
		return {}; 
	// general
	int m = matrix.size(), n = matrix[0].size();
	// record rows and columns that have zero elements
	vector<int> rowLabel(m, 0);
	vector<int> colLabel(n, 0);
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (matrix[i][j] == 0)
			{
				rowLabel[i] = 1;
				colLabel[j] = 1;
			}
		}
	}
	// revise the matrix based on recorded row and columns
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (rowLabel[i] == 1 || colLabel[j] == 1)
			
				matrix[i][j] = 0;
		}
	}
	return matrix;
}


int main()
{
	vector<vector<int>> matrix1 = { {1, 2},{0, 4} };
	vector<vector<int>> matrix2 = { {1,2,3}, {4,0,6}, {7,8,9}};
	vector<vector<int>> matrix3 = { {1,2,3,0}, {5,6,7,8}, {9,10,11,12}, {13,14,15,0} };
	vector<vector<int>> result1 = { {0,2}, {0,0} };
	vector<vector<int>> result2 = { {1,0,3}, {0,0,0}, {7,0,9} };
	vector<vector<int>> result3 = { {0,0,0,0}, {5,6,7,0}, {9,10,11,0}, {0,0,0,0} };
	assert(setZeroMatrix(matrix1) == result1);
	assert(setZeroMatrix(matrix2) == result2);
	assert(setZeroMatrix(matrix3) == result3);
	cout << "All test cases passed!\n";
}
