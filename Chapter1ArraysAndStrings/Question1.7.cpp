/*
Implement an algorithm to rotate a given N*N matrix in 90 degree. (N != 0) (clockwise)

Example:
	Input:
		1	2	3	4
		5	6	7	8
		9	10	11	12
		13	14	15	16
	Return:
		13	9	5	1
		14	10	6	2
		15	11	7	3
		16	12	8	4
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

// Optimized solution: perform the operation in place
// Look at a 4X4 matrix:
// 
// ...
vector<vector<int>> rotateMatrix(vector<vector<int>> matrix)
{
	if (matrix.empty())
		return {};
	int n = matrix.size();
	// i is the layer counting from outmost edge
	for (int i = 0; i < n / 2; i++)
	{
		for (int j = i; j < n-1-i; j++)
		{
			int offset = j - i; 
			int top = matrix[i][j]; 
			int left = matrix[n-1-i - offset][i]; 
			int bot = matrix[n-1-i][n-1-i-offset];
			int right = matrix[j][n-1-i];

			matrix[i][j] = left;
			matrix[n - 1 - i - offset][i] = bot;
			matrix[n - 1 - i][n - 1 - i - offset] = right;
			matrix[j][n - 1 - i] = top;
		}
	}
	return matrix;
	
}


// Naive solution: create another matrix and fill the cell using the following equation:
// result(j, N-i) = matrix(i, j)
vector<vector<int>> rotateMatrix1(vector<vector<int>> matrix)
{
	if (matrix.empty())
		return {};
	int n = matrix.size();
	vector<vector<int>> result(n, vector<int>(n, 0));
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			result[j][n-i-1] = matrix[i][j];
		}
	}
	return result;
}


int main()
{
	vector<vector<int>> matrix1 = { {1, 2},{3, 4} };
	vector<vector<int>> matrix2 = { {1,2,3}, {4,5,6}, {7,8,9}};
	vector<vector<int>> matrix3 = { {1,2,3,4}, {5,6,7,8}, {9,10,11,12}, {13,14,15,16} };
	vector<vector<int>> result1 = { {3,1}, {4,2} };
	vector<vector<int>> result2 = { {7,4,1}, {8,5,2}, {9,6,3} };
	vector<vector<int>> result3 = { {13,9,5,1}, {14,10,6,2}, {15,11,7,3}, {16,12,8,4} };
	assert(rotateMatrix(matrix1) == result1);
	assert(rotateMatrix(matrix2) == result2);
	assert(rotateMatrix(matrix3) == result3);
	cout << "All test cases passed!\n";
}