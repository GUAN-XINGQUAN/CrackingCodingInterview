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


string URLify(string url, int length) 
{
	// step 1: figure out how many blanks we have during the given length
	int numBlanks = 0;
	for (int i = 0; i < length; i++)
	{
		if (url[i] == ' ')
			numBlanks++;
	}
	// step 2: figure out the final length of the string
	int finalLength = length - numBlanks + numBlanks * 3;
	// step 3: determine if the total required length can be accommodated
	if (finalLength > url.size())
		return "-999";
	// step 4: re-organize the texts and start from the back to front
	int index1 = finalLength - 1, index2 = length - 1;
	while (index1 >= 0 && index2 >= 0)
	{
		if (url[index2] != ' ')
		{
			url[index1] = url[index2];
			index1--;
			index2--;
		}
		else
		{
			url[index1] = '0';
			url[index1 - 1] = '2';
			url[index1 - 2] = '%';
			index1 = index1 - 3;
			index2--;
		}
	}
	return url;
}


int main()
{
	assert(URLify("GUAN    ", 4) == "GUAN    ");
	assert(URLify("G UAN    ", 5) == "G%20UAN  ");
	assert(URLify("G U AN     ", 6) == "G%20U%20AN ");
	assert(URLify("", 0) == "");
	cout << "All test cases passed!\n";
}
