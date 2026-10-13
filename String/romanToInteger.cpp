#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    int romanToInt(string s)
    {
        // Map each Roman numeral to its integer value
        unordered_map<char, int> roman = {
            {'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}};

        int total = 0;

        for (int i = 0; i < s.length(); i++)
        {
            // If the current value is less than the next value, subtract it
            if (i + 1 < s.length() && roman[s[i]] < roman[s[i + 1]])
            {
                total -= roman[s[i]];
            }
            else
            {
                // Otherwise, add it
                total += roman[s[i]];
            }
        }

        return total;
    }
};

int main()
{
    Solution solution;

    // Test Case 1
    string s1 = "III";
    cout << "Input:  " << s1 << endl;
    cout << "Output: " << solution.romanToInt(s1) << " (Expected: 3)\n"
         << endl;

    // Test Case 2
    string s2 = "LVIII";
    cout << "Input:  " << s2 << endl;
    cout << "Output: " << solution.romanToInt(s2) << " (Expected: 58)\n"
         << endl;

    // Test Case 3
    string s3 = "MCMXCIV";
    cout << "Input:  " << s3 << endl;
    cout << "Output: " << solution.romanToInt(s3) << " (Expected: 1994)\n"
         << endl;

    return 0;
}