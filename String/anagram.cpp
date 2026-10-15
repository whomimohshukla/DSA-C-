#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool isAnagram(string s, string t)
{

    int freqTable[256] = {0};

    for (int i = 0; i < s.length(); i++)
    {

        freqTable[s[i]]++;
    }
    for (int j = 0; j < t.length(); j++)
    {

        freqTable[t[j]]--;
    }

    for (int i = 0; i < 256; i++)
    {

        if (freqTable[i] != 0)
        {

            return false;
        }
    }
    return true;
}
int main()
{

    string s = "anagram";
    string t = "nagaram";

    if (!isAnagram(s, t))
    {
        cout << "strings are not anagram" << endl;
    }

    else
    {
        cout << "Strings are anagram" << endl;
    }

    return 0;
}