/*

Impelement functions to do the following thins:

(1) isSubstring(str1, str2):
	return true if str1 is a substring of str2, false otherwise.

(2) isRotation(str1, str2):
	return true if str2 is a rotation of str1.
	Only call isSubstring once in this function.
*/

/*
Clarify:
	1. empty string is a substring of any string (including empty itself)
	2. A string is a rotation of itself: "abc" is a rotation of "abc".
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

/*
	b	c
	a	b	c	d	e
	0	1	2	3	4
	
	m = 2
	n = 5
*/

// time O(m*n) space O(1)
bool isSubstring(string str1, string str2)
{
	// return true if str1 is a substring of str2
	int m = str1.size(), n = str2.size();
	for (int i = 0; i <= n - m; i++)
	{
		int j = 0;
		while (j < m)
		{
			if (str1[j] != str2[i+j])
				break;
			j++;
		}

		if (j == m)
			return true;
	}
	return false;
}

/*

str1
	l	e	e	t	c	o	d	e
str2
	c	o	d	e	l	e	e	t
	0	1	2	3	4	5	6	7

str2 + str2:
	c	o	d	e	l	e	e	t	c	o	d	e	l	e	e	t

str1:
	x | y

str2:
	y | x | y | x

*/
bool isRotation(string str1, string str2)
{
	string newString = str2 + str2;
	return isSubstring(str1, newString);
}

int main()
{
	assert(isSubstring("abc", "abc") == true);
	assert(isSubstring("ab", "") == false);
	assert(isSubstring("", "abc") == true);
	assert(isSubstring("", "") == true);
	assert(isSubstring("acf", "ac") == false);

	assert(isRotation("abc", "bca") == true);
	assert(isRotation("abc", "cab") == true);
	assert(isRotation("abc", "abc") == true);
	assert(isRotation("abc", "cba") == false);
	assert(isRotation("leetcode", "codeleet") == true);
	cout << "All test cases passed\n";
}