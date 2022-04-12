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

// Approach 1: use hashtable to store character-count pair
// Assume two strings have similar length
// Time complexity: O(n); n: length of string
// Space complexity: O(n); n: length of string
bool checkPermutation(string str1, string str2)
{
	int m = str1.size(), n = str2.size();
	// If two strings have different lengths --> false
	if (m != n)
		return false;
	unordered_map<char, int> char2Freq;
	// save character->count from str1
	for (int i = 0; i < m; i++)
	{
		char ch = str1[i];
		char2Freq[ch]++;
	}
	// reduce character->count based on str2
	for (int j = 0; j < n; j++)
	{
		char ch = str2[j];
		char2Freq[ch]--;
	}
	// check if any character->count has non-zero values
	unordered_map<char, int>::iterator it = char2Freq.begin();
	while (it != char2Freq.end())
	{
		if (it->second != 0)
			return false;
		it++;
	}
	return true;
}


int main()
{
	assert(checkPermutation("abc", "bca") == true);
	assert(checkPermutation("abc", "cba") == true);
	assert(checkPermutation("abc", "1bca") == false);
	assert(checkPermutation("", "b") == false);
	assert(checkPermutation("", "") == true);
	assert(checkPermutation("a", "") == false);
	assert(checkPermutation("abcd", "bcda") == true);
	cout << "All test cases passed!\n";
}
