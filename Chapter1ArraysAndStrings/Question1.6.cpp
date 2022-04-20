/*
Implement an algorithm to compress the string by using the character and the following repeated times.

If the compressed version is longer than or equal to the original one, then don't do compression.

String only contain upper and lower case characters (a~z and A~Z).

Example 1:
	Input: "aaabbb"
	Return: "a3b3"

Example 2:
	Input: "abc"
	Return: "abc" because "a1b1c1" is longer than the original version.
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

// Optimized solution: initialize the result with str.length because result cannot be longer than that
string compressString(string str)
{
	// edge case
	if (str.empty())
		return "";
	// save char->count pair for the 1st character
	unordered_map<char, int> char2Freq;
	string result(' ', str.size());
	char2Freq[str[0]]++;
	result[0] = str[0];
	int index = 1;
	for (int i = 1; i < str.size(); i++)
	{
		if (str[i] != str[i - 1])
		{
			result[index++] = (char2Freq[str[i - 1]] + '0');
			char2Freq[str[i - 1]] = 0;
			if (index >= str.size())
				return str;
			result[index++] = str[i];
			char2Freq[str[i]]++;
		}
		else
		{
			char2Freq[str[i]]++;
		}
		if (index >= str.size())
			return str;
	}
	if (index < str.size())
	{
		result[index] = (char2Freq[str.back()] + '0');
	}
	else
		return str;
	return result.substr(0, index+1);
}


// Solution: less efficient because I repeatedly create a new string when append the character
string compressString1(string str)
{
	// edge case
	if (str.empty())
		return "";
	// save char->count pair for the 1st character
	unordered_map<char, int> char2Freq;
	string result = str.substr(0, 1);
	char2Freq[str[0]]++;
	for (int i = 1; i < str.size(); i++)
	{
		if (str[i] != str[i - 1])
		{
			result += to_string(char2Freq[str[i - 1]]);
			char2Freq[str[i - 1]] = 0;
			result += str[i];
			char2Freq[str[i]]++;
		}
		else
		{
			char2Freq[str[i]]++;
		}
		if (result.size() > str.size())
			return str;
	}
	result += to_string(char2Freq[str.back()]);
	return result.size() < str.size() ? result : str;
}


int main()
{
	assert(compressString("ana") == "ana");
	assert(compressString("") == "");
	assert(compressString("tactcoa") == "tactcoa");
	assert(compressString("abba") == "abba");
	assert(compressString("ab") == "ab");
	assert(compressString("abbc") == "abbc");
	assert(compressString("gggcccdd") == "g3c3d2");
	assert(compressString("anA") == "anA");
	assert(compressString("Aaaaa") == "A1a4");
	assert(compressString("A") == "A");
	assert(compressString("AAAaaa") == "A3a3");
	cout << "All test cases passed!\n";
}