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

// Approach 1: use hashtable to store character->count pair
// Time complexity: O(n); n: length of string
// Space complexity: O(n); n: length of string
bool isUnique(string s) {
	unordered_map<char, int> char2Freq;
	for (int i = 0; i < s.size(); i++)
	{
		char ch = s[i];
		if (char2Freq.count(ch) != 0)
			return false;
		char2Freq[ch]++;
	}
	return true;
}

// Approach 2: if I am not allowed to use additional structure:
//				sort the string and check every adjacent characters
bool isUnique2(string s) {
	if (s.empty())
		return true;
	sort(s.begin(), s.end());
	for (int i = 0; i < s.size() - 1; i++)
	{
		if (s[i] == s[i+1])
			return false;
	}
	return true;
}

int main()
{
	assert(isUnique("abc") == true);
	assert(isUnique("ancdf") == true);
	assert(isUnique("abca") == false);
	assert(isUnique("") == true);
	assert(isUnique("1231") == false);
	assert(isUnique("a1b2c3d3") == false);
	cout << "All test cases passed\n";
}
