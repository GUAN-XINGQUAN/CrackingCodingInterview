/*
Implement an algorithm to determine if the given string is a permutation of a palindrome.

A palindrome is a word that reads the same both forwards and backwards.

You can ignore the case of letters and non-letter characters.

Example 1:
	Input: "Gg"
	Return: true

Example 2:
	Input: "GgGz"
	Return: false

Example 3:
	Input: "Gaa 3212*9"
	Return: true
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

// Solution: traverse the entire string and save character->count pair
// A string is a permutation of a palindrome if and only if all the characters' counts are even numbers
// or there is at maximum of one character's count is odd number.
bool isPalindromePermutation(string str)
{
	unordered_map<char, int> char2Freq;
	for (int i = 0; i < str.size(); i++)
	{
		if (isalpha(str[i]))
			char2Freq[tolower(str[i]) - 'a']++;
	}
	int ct = 0;
	unordered_map<char, int>::iterator it = char2Freq.begin();
	while (it != char2Freq.end())
	{
		if (it->second % 2 != 0)
			ct++;
		it++;
	}
	return ct <= 1;
}


int main()
{
	assert(isPalindromePermutation("ana") == true);
	assert(isPalindromePermutation("") == true);
	assert(isPalindromePermutation("tact coa") == true);
	assert(isPalindromePermutation("ab ba") == true);
	assert(isPalindromePermutation("ab ") == false);
	assert(isPalindromePermutation("ab bc") == false);
	assert(isPalindromePermutation("guan zhang") == false);
	assert(isPalindromePermutation("an A") == true);
	assert(isPalindromePermutation("A ") == true);
	assert(isPalindromePermutation("A 12321") == true);
	assert(isPalindromePermutation("A+/1") == true);
	cout << "All test cases passed!\n";
}