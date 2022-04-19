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

// Optimized solution
bool isOneAway(string str1, string str2)
{
    int m = str1.size(), n = str2.size();
    // Trival case: two lengths differ by more than one --> false
    if (abs(m - n) >= 2)
        return false;
    // This is to ensure that str1 is always the longer one
    if (m < n)
        return isOneAway(str2, str1);
    // Save char->count pair for str1
    unordered_map<char, int> char2Freq;
    for (int i = 0; i < str1.size(); i++)
        char2Freq[str1[i]]++;
    // Remove the char-count pair if same char occurs in str2
    for (int j = 0; j < str2.size(); j++)
    {
        if (char2Freq.count(str2[j]) != 0)
            char2Freq[str2[j]]--;
    }
    // Count how many char's count is nonzero
    unordered_map<char, int>::iterator it = char2Freq.begin();
    int ct = 0;
    while (it != char2Freq.end())
    {
        if (it->second != 0)
            ct++;
        it++;
    }
    return ct <= 1;
}



// Naive Solution 1: non-optimized code structure
bool isOneAway1(string str1, string str2)
{
    int m = str1.size(), n = str2.size();
    // Case 1: two strings' length differ by more than 1 character --> false
    if (abs(m - n) >= 2)
        return false;
    // Case 2: two strings' length differ by a single character
    else if (abs(m - n) == 1)
    {
        // This is to ensure that str1 is always the longer string
        if (m < n)
            return isOneAway(str2, str1);
        unordered_map<char, int> char2Freq;
        for (int i = 0; i < str1.size(); i++)
            char2Freq[str1[i]]++;
        for (int j = 0; j < str2.size(); j++)
        {
            if (char2Freq.count(str2[j]) != 0)
                char2Freq[str2[j]]--;
        }
        unordered_map<char, int>::iterator it = char2Freq.begin();
        int ct = 0;
        while (it != char2Freq.end())
        {
            if (it->second != 0)
                ct++;
            it++;
        }
        return ct == 1;
    }
    // Case 3: two strings' length are equal
    else
    {
        unordered_map<char, int> char2Freq;
        for (int i = 0; i < str1.size(); i++)
            char2Freq[str1[i]]++;
        for (int j = 0; j < str2.size(); j++)
        {
            if (char2Freq.count(str2[j]) != 0)
                char2Freq[str2[j]]--;
        }
        unordered_map<char, int>::iterator it = char2Freq.begin();
        int ct = 0;
        while (it != char2Freq.end())
        {
            if (it->second != 0)
                ct++;
            it++;
        }
        return ct == 1 || ct == 0;
    }

}


int main()
{
    assert(isOneAway("ple", "pale") == true);
    assert(isOneAway("pale", "ple") == true);
    assert(isOneAway("pale", "bale") == true);
    assert(isOneAway("p", "") == true);
    assert(isOneAway("p", "pl") == true);
    assert(isOneAway("p", "b") == true);
    assert(isOneAway("pale", "pl") == false);
    assert(isOneAway("guan", "g") == false);
    assert(isOneAway("guan", "ga") == false);
    assert(isOneAway("guan", "guan") == true);
    cout << "All test cases passed\n";
}
